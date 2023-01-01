CC := gcc

CFLAGS = -std=c99 -Wall -Werror -Wvla -pedantic

OBJS := io.o read_thing.o sort.o create.o

.PHONY : debug release clean

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe


unit : unit_tests.exe
	./unit_tests.exe

clean :
	$(RM) $(OUT)*.o *.exe

app.exe : main.o $(OBJS) 
		$(CC) -o $@ $^
unit_tests.exe : check_main.o check_sort.o sort.o create.o
		$(CC) -o $@ $^ -lcheck
%.o : %.c *.h
		$(CC) $(CFLAGS) -c $<