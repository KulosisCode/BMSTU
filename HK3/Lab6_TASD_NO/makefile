CC := gcc
CFLAGS = -std=c99 -Wall -Werror -Wvla -pedantic


app.exe : main.o func.o
		$(CC) -o $@ $^
		rm *o


%.o : %.c *.h
		$(CC) $(CFLAGS) -c $<

clean :
	$(RM) *.o *.exe