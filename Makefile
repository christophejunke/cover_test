all: main

.PHONY: frama-c

frama-c:
	frama-c main.c \
		~/.opam/4.14.0/share/frama-c/libc/string.c \
		-eva-slevel=3 \
		-eva-partition-history=2 \
		-eva
