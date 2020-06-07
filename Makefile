CFLAGS += -Ofast -Wall

.PHONY : test
.DEFAULT : test
.SECONDARY : 

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

.PHONY : clean
clean :
	@$(RM) *.o test.out
