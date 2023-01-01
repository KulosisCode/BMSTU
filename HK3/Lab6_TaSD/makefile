INC := inc/
OUT := out/
SRC := src/
UNI := unit_tests/

CC := gcc
CFLAGS = -std=c99 -Wall -Werror -Wvla -pedantic

OBJS := $(OUT)hash.o $(OUT)tree.o $(OUT)efficiency.o 

.PHONY : debug release clean

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

app : app.exe
	./app.exe

app.exe : $(OUT)main.o $(OBJS)
		$(CC) -o $@ $^


$(OUT)%.o : $(SRC)%.c $(INC)*.h
		mkdir -p out
		$(CC) $(CFLAGS) -I inc -o $@ -c $<

clean :
	$(RM) $(OUT)*.o *.exe *.dot *.gv *.png