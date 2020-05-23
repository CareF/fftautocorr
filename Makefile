CFLAGS += -Ofast -Wall -lm

.PHONY : test
.DEFAULT : test
.SECONDARY : 

test: test.out
	./test.out

test.out : test.c fftautocorr.o 
	$(CC) $(CFLAGS) -lfftw3 -I/usr/local/include -L/usr/local/lib $^ -o $@

fftautocorr.o : fftautocorr.c fftautocorr.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean :
	@$(RM) *.o test.out
