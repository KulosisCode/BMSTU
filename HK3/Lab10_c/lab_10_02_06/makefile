INC := inc/
OUT := out/
SRC := src/
UNI := unit_tests/

CC := gcc
CFLAGS = -std=c99 -Wall -Werror -Wvla -pedantic

OBJS := $(OUT)input.o $(OUT)out.o $(OUT)add.o $(OUT)mul.o $(OUT)lin.o
CHECKOBJS := $(OUT)input.o $(OUT)add.o $(OUT)check_add.o

.PHONY : debug release clean

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

unit : unit_tests.exe
	./unit_tests.exe

app.exe : $(OUT)main.o $(OBJS)
		$(CC) -o $@ $^

unit_tests.exe : $(OUT)check_main.o $(CHECKOBJS)
		$(CC) -o $@ $^ -lcheck -lpthread

$(OUT)%.o : $(SRC)%.c $(INC)*.h
		mkdir -p out
		$(CC) $(CFLAGS) -I inc -o $@ -c $<

$(OUT)%.o : $(UNI)%.c $(INC)*.h
		mkdir -p out
		$(CC) $(CFLAGS) -I inc -o $@ -c $<

clean :
	$(RM) $(OUT)*.o *.exe