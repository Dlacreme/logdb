CC = gcc

CFLAGS  = -g -Wall

INCLUDES =  -I./include

LFLAGS = -L./lib

LIBS = -lm

SRCS =	src/main.c		\
		src/parser.c	\
		src/print.c		\
		src/command.c 	\
		src/command/fetch.c	\
		src/command/insert.c	\
		src/command/db.c

OBJS = $(SRCS:.c=.o)

MAIN = logdb

.PHONY: depend clean

all: $(MAIN)
	@echo Logdb successfully compiled.

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

re: clean all

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean: clean_o
	rm -f $(MAIN)

clean_o:
	rm -f src/*.o src/**/*.o