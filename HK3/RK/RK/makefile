CC := gcc
CFLAGS = -std=c99 -Wall -Werror -Wvla -pedantic


app.exe: main.o matrix.o input.o error.o
	$(CC) -o $@ $^

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $<

.PHONY : clean
clean :
	$(RM) *.o *.exe