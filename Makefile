#CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O2

.PHONY : all
all: crp1 crp2 crp3 crp4


crp1:
	@echo "Should produce: SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t"
	gcc $(CFLAGS) -o $@ $@.c
	./$@
	rm $@

crp2:
	@echo "Should produce: 746865206b696420646f6e277420706c6179"
	gcc $(CFLAGS) -o $@ $@.c
	./$@
	rm $@

crp3:
	@echo "Should produce: Cooking MC's like a pound of bacon"
	gcc $(CFLAGS) -o $@ $@.c
	./$@
	rm $@

crp4:
	@echo Checking in file: 4.txt
	[[ -f 4.txt ]] || wget https://cryptopals.com/static/challenge-data/4.txt
	gcc $(CFLAGS) -o $@ $@.c
	./$@
	rm $@
