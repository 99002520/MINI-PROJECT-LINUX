
all:	send	receive
send:	send.c
	gcc send.c -o send -lpthread
reci:	receive.c
	gcc receive.c -o receive -lpthread
