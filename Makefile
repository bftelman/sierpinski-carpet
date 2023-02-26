CC = gcc
CFLAGS = -Wall -Werror
LFLAGS = -lm

carpet:
	$(CC) $(CFLAGS) -o main main.c $(LFLAGS)

clean:
	rm *.ppm ./main

open:
	xdg-open output.ppm