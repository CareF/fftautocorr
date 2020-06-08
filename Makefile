CFLAGS += -Ofast -Wall

ifeq ($(OS),Windows_NT)
	CFLAGS += -D WIN32
else 
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		CFLAGS += -D MAC
		LDFLAGS += -L/usr/local/lib
		LDLIBS += -lm -I/usr/local/include 
	else
		# Assuming linux
		LDLIBS += -lmvec
	endif
endif


.PHONY : test clean
.DEFAULT_GOAL := fftautocorr.o
.SECONDARY : fftautocorr.o

test: test.out
	./test.out

test.out : test.c fftautocorr.o  pocketfft.o
	$(CC) $(CFLAGS) $(LDLIBS) -lfftw3 $(LDFLAGS) $^ -o $@

fftautocorr.o : fftautocorr.c fftautocorr.h factortable.h
	$(CC) $(CFLAGS) -c $< -o $@

pocketfft.o : pocketfft/pocketfft.c pocketfft/pocketfft.h
	$(CC) $(CFLAGS) -c $< -o $@

factortable.h : tablegen.py
	./tablegen.py $@

pocketfft/% : 
	git clone https://gitlab.mpcdf.mpg.de/mtr/pocketfft.git

.PHONY : clean
clean :
	@$(RM) *.o test.out
