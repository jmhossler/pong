pong: paddles.o screen.o difficulty.o pong.o logic.o
	gcc pong.o paddles.o screen.o difficulty.o logic.o -lncurses -lm -o pong

pong.o: src/pong.c
	gcc -lncurses -lm -c src/pong.c

logic.o: src/logic.c
	gcc -lncurses -c src/logic.c

paddles.o: src/paddles.c
	gcc -c src/paddles.c

difficulty.o: src/difficulty.c
	gcc -lncurses -c src/difficulty.c

screen.o: src/screen.c
	gcc -lncurses -c src/screen.c

clean:
	rm screen.o difficulty.o paddles.o pong.o logic.o
