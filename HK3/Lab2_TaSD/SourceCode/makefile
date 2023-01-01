CC = gcc


CFLAGS = -std=c99 -Wall -Werror -Wvla -pedantic

.PHONY : clean debug release

release : CFLAGS += -DNDEBUG -g0
release : app.exe

debug : CFLAGS += -g3
debug : app.exe

clean :
	$(RM) *.o *.exe

app : app.exe
	./app.exe

app.exe: main.o io_table.o sorted.o
	$(CC) -o $@ $^

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $<