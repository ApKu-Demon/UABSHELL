# Simple Makefile structure for building the shell and its commands
CC = gcc
CFLAGS = -Wall -Iinclude

all: shell commands

shell:
	$(CC) $(CFLAGS) src/*.c -o bin/uabshell

commands:
	$(CC) $(CFLAGS) commands/drawbmp.c -o bin/drawbmp
	$(CC) $(CFLAGS) commands/sysinfo.c -o bin/sysinfo
	$(CC) $(CFLAGS) commands/cryptofile.c -o bin/cryptofile

clean:
	rm -rf bin/*