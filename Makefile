CC=clang

CFLAGS = -Wall -Isrc -g -std=c11

SRC = $(wildcard src/*.c src/test/*.c)
#OBJS = $(addprefix build/objs/,$(SRC:.c=.o))
OBJS = $(SRC:.c=.o)
OBJS_DIR=build/objs/

TEST_SRC = src/test/test
TEST_BINS = $(addprefix build/bins/,$(TEST_SRC))

%.o: %.c
	mkdir -p $(dir build/objs/$@)
	$(CC) $< -c -o $(addprefix $(OBJS_DIR),$@) $(CFLAGS)

$(TEST_SRC): $(OBJS)
	mkdir -p $(dir build/bins/$@)
	$(CC) $(CFLAGS) -o $(addprefix build/bins/,$@) $(addprefix $(OBJS_DIR),$(OBJS))

test: $(TEST_SRC)
	./$(TEST_BINS)

all: test

.PHONY: all test
