CC = gcc
CFLAGS = -Wall -Wextra -std=c2x -pedantic -g
TARGET = target/main
TARGET_TEST = target/test
OUT_DIR = target
OBJS = $(OUT_DIR)/main.o $(OUT_DIR)/vec3.o $(OUT_DIR)/color.o $(OUT_DIR)/ray.o
OBJS_TEST = $(OUT_DIR)/test.o $(OUT_DIR)/vec3.o $(OUT_DIR)/color.o $(OUT_DIR)/ray.o

all: $(TARGET)
test: $(TARGET_TEST)

$(TARGET): $(OBJS) | $(OUT_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(TARGET_TEST): $(OBJS_TEST) | $(OUT_DIR)
	$(CC) $(CFLAGS) -o $(TARGET_TEST) $(OBJS_TEST)

$(OUT_DIR)/main.o: main.c | $(OUT_DIR)
	$(CC) $(CFLAGS) -c main.c -o $(OUT_DIR)/main.o

$(OUT_DIR)/test.o: test.c | $(OUT_DIR)
	$(CC) $(CFLAGS) -c test.c -o $(OUT_DIR)/test.o

$(OUT_DIR)/vec3.o: vec3.c vec3.h | $(OUT_DIR)
	$(CC) $(CFLAGS) -c vec3.c -o $(OUT_DIR)/vec3.o

$(OUT_DIR)/color.o: color.c color.h | $(OUT_DIR)
	$(CC) $(CFLAGS) -c color.c -o $(OUT_DIR)/color.o

$(OUT_DIR)/ray.o: ray.c ray.h | $(OUT_DIR)
	$(CC) $(CFLAGS) -c ray.c -o $(OUT_DIR)/ray.o

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

clean:
	rm -rf $(OUT_DIR)

.PHONY: all test clean
