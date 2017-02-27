OBJS := pong.o paddles.o screen.o difficulty.o logic.o 
CC := gcc
LDLIBS := -lncurses -lm 
VPATH := src
TARGET := pong
.PHONY: clean

$(TARGET): $(OBJS)
clean:
	rm -f $(OBJS) $(TARGET)
