
all:	send	reci
send:	send.c
	gcc send.c -o send -lpthread
reci:	reci.c
	gcc reci.c -o reci -lpthread