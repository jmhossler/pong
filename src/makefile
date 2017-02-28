OBJS := pong.o paddles.o screen.o difficulty.o logic.o 
CC := gcc
LDLIBS := -lncurses -lm 
TARGET := pong
.PHONY: clean

$(TARGET): $(OBJS)

difficulty.o: difficulty.h
logic.o: logic.h
paddles.o: paddles.h
screen.o: paddles.h difficulty.h screen.h

clean:
	rm -f $(OBJS) $(TARGET)
