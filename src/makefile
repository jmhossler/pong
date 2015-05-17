pong: paddles.o screen.o difficulty.o pong.o logic.o
	gcc pong.o paddles.o screen.o difficulty.o logic.o -lncurses -lm -o pong

pong.o: pong.c
	gcc -lncurses -lm -c pong.c

logic.o: logic.c
	gcc -lncurses -c logic.c

paddles.o: paddles.c
	gcc -c paddles.c

difficulty.o: difficulty.c
	gcc -lncurses -c difficulty.c

screen.o: screen.c
	gcc -lncurses -c screen.c

clean:
	rm screen.o difficulty.o paddles.o pong.o logic.o
