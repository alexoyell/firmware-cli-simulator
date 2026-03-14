CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = firmware.exe

all: test_uart

test_uart: tests/test_uart.c drivers/uart.c
	$(CC) $(CFLAGS) -o tests/test_uart tests/test_uart.c drivers/uart.c

run_uart: test_uart
	./tests/test_uart

test_shell: tests/test_shell.c app/shell.c drivers/uart.c
	$(CC) $(CFLAGS) -o tests/test_shell tests/test_shell.c app/shell.c drivers/uart.c

run_shell: test_shell
	./tests/test_shell

test_ring: tests/test_ring_buffer.c kernel/ring_buffer.c
	$(CC) $(CFLAGS) -o tests/test_ring_buffer tests/test_ring_buffer.c kernel/ring_buffer.c

run_ring: test_ring
	./tests/test_ring_buffer

build: main.c drivers/uart.c kernel/ring_buffer.c app/shell.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c drivers/uart.c kernel/ring_buffer.c app/shell.c

run: build
	./$(TARGET)

clean:
	rm -f tests/test_uart tests/test_shell tests/test_ring_buffer $(TARGET)