CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lraylib -lm

SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c)
BUILD_DIR = build
TARGET = $(BUILD_DIR)/cubebase

build: $(SRC)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)
	cp -r resources/* $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
