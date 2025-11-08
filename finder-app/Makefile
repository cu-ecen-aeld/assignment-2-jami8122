#Makefile for finder-app
#
ifdef CROSS_COMPILE
CC := $(CROSS_COMPILE)gcc
else
CC ?= gcc
endif

CFLAGS ?= -Wall -Wextra -Werror -O2 -g -std=c11

TARGET := writer
SRC := writer.c
OBJ := $(SRC:.c=.o)

.PHONY: all clean
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

