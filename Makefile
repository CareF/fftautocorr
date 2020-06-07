CFLAGS += -Ofast -Wall

.PHONY : test clean
.DEFAULT : fftautocorr.o
.SECONDARY : fftautocorr.o

test: test.out
	./test.out

test.out : test.c fftautocorr.o  pocketfft.o
	$(CC) $(CFLAGS) -lm -lfftw3 -I/usr/local/include -L/usr/local/lib $^ -o $@

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
