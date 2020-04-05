
#CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O2

.PHONY: c11 phex
all: clean crp1 crp2 crp3

crp1:
	@echo "Should produce: SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t"
	gcc $(CFLAGS) -o crp1 crp1.c
	./crp1
	rm crp1

crp2:
	gcc $(CFLAGS) -o crp2 crp2.c
	./crp2
	rm crp2

crp3:
	gcc $(CFLAGS) -o crp3 crp3.c
	./crp3
	rm crp3


clean:
	rm -f crp1
	rm -f crp2
	rm -f crp3

