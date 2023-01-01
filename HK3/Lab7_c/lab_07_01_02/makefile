CC = gcc
INC = ./inc/
OUT = ./out/
SRC = ./src/
UNIT = ./unit_tests/

OBJS = $(OUT)key.o $(OUT)io.o $(OUT)sort.o
OBJS_UNIT = $(OUT)check_key.o $(OUT)check_sort.o

APP_INCS = $(INC)io.h $(INC)key.h $(INC)sort.h

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

clean :
	$(RM) $(OUT)*.o *.exe

app.exe: $(OUT)main.o $(OBJS)
	$(CC) -o $@ $^
unit_tests.exe: $(OUT)check_main.o $(OBJS) $(OBJS_UNIT) 
	$(CC) -o $@ $^ -lcheck

# app

$(OUT)main.o: $(SRC)main.c $(APP_INCS)
	cd out && $(CC) $(CFLAGS) -c ../$<

$(OUT)key.o: $(SRC)key.c $(INC)key.h $(INC)constan.h
	cd out && $(CC) $(CFLAGS) -c ../$<

$(OUT)io.o: $(SRC)io.c $(INC)io.h $(INC)constan.h 
	cd out && $(CC) $(CFLAGS) -c ../$<

$(OUT)sort.o: $(SRC)sort.c $(INC)sort.h $(INC)constan.h
	cd out && $(CC) $(CFLAGS) -c ../$<

# unit_tests

$(OUT)check_main.o: $(UNIT)check_main.c $(INC)check_main.h
	cd out && $(CC) $(CFLAGS) -c ../$<

$(OUT)check_key.o: $(UNIT)check_key.c $(INC)check_main.h
	cd out && $(CC) $(CFLAGS) -c ../$< 

$(OUT)check_sort.o: $(UNIT)check_sort.c $(INC)check_main.h
	cd out && $(CC) $(CFLAGS) -c ../$<