CC = gcc

OBJS = key.o free.o sort.o
OBJS_UNIT = check_key.o check_sort.o

APP_INCS = io.h key.h sort.h

CFLAGS = -std=c99 -Wall -Werror -Wvla -pedantic

.PHONY : clean debug release

release : CFLAGS += -DNDEBUG -g0
release : app.exe

debug : CFLAGS += -g3
debug : app.exe

unit : unit_tests.exe
	./unit_tests.exe

func :
	cd func_tests && ./run_tests.bat 
time : time.exe
	./time.exe
clean :
	$(RM) *.o *.exe

app.exe: main.o io.o $(OBJS)
	$(CC) -o $@ $^
unit_tests.exe: check_main.o $(OBJS) $(OBJS_UNIT) 
	$(CC) -o $@ $^ -lcheck
time.exe : time.o sort.o
	$(CC) -o $@ $^
%.o: %.c *.h
	$(CC) $(CFLAGS) -c $<