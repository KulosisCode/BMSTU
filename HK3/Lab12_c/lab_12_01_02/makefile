CC := gcc
CFLAGS := -std=gnu99 -Wall -Wvla -pedantic -Wpedantic
STATIC:= cd static
DYN_1 := cd dyn1
DYN_2 := cd dyn2


all : app_static app_dyn1 app_dyn2

.PHONY : clean debug release

release : CFLAGS += -DNDEBUG -g0
release : app.exe

debug : CFLAGS += -g3
debug : app.exe

# статическая библиотека

build_static_lib :
	#
	# Build static library
	#
	$(STATIC)/out && $(CC) $(CFLAGS) -I "../inc" -c ../lib/*.c
	$(STATIC) && ar rc static.a out/*.o
	$(STATIC) && ranlib static.a
	$(STATIC)/out && rm *.o

app_static : build_static_lib
	#
	# Build app_static
	#
	$(STATIC) && $(CC) $(CFLAGS) -I "inc" src/*.c static.a -o app.exe

unit_tests_static : build_static_lib
	#
	# Build unit_tests_static
	#
	$(STATIC) && $(CC) $(CFLAGS) -I "inc" unit_tests/*.c static.a -o unit_tests.exe -lcheck


# динамическая библиотека (динамическая компоновка)

build_dyn1_lib :
	#
	# Build dyn1 library (динамическая компоновка)
	#
	$(DYN_1)/out && $(CC) $(CFLAGS) -I "../inc" -c ../lib/*.c
	$(DYN_1) && $(CC) -shared out/*.o -Wl,--subsystem,windows -o dyn1.dll
	$(DYN_1)/out && rm *.o

app_dyn1 : build_dyn1_lib
	#
	# Build app_dyn1
	#
	$(DYN_1) && $(CC) $(CFLAGS) -I "inc" src/*.c -L. -ldyn1 -o app.exe

unit_tests_dyn1 : build_dyn1_lib
	#
	# Build unit_tests_dyn1
	#
	$(DYN_1) && $(CC) $(CFLAGS) -I "inc"  unit_tests/*.c -L. -ldyn1 -o unit_tests.exe -lcheck


# динамическая библиотека (динамическая загрузка)

build_dyn2_lib :
	#
	# Build dyn2 library (динамическая загрузка)
	#
	$(DYN_2)/out && $(CC) $(CFLAGS) -I "../inc" -c ../lib/*.c
	$(DYN_2) && $(CC) -shared out/*.o -Wl,--subsystem,windows -o dyn2.dll
	$(DYN_2)/out && rm *.o

app_dyn2 : build_dyn2_lib
	#
	# Build app_dyn2
	#
	$(DYN_2) && $(CC) $(CFLAGS) -I "inc" src/*.c  -o app.exe

unit_tests_dyn2 : build_dyn2_lib

	#
	# Build unit_tests_dyn2
	#
	$(DYN_2) && $(CC) $(CFLAGS) -I "inc" src/cmp.c unit_tests/*.c -o unit_tests.exe -lcheck



unit : unit_tests_static unit_tests_dyn1 unit_tests_dyn2
	$(STATIC) && ./unit_tests.exe
	$(DYN_1) && ./unit_tests.exe
	$(DYN_2) && ./unit_tests.exe

clean :
	rm static/*.exe dyn1/*.exe dyn2/*.exe static/*.a dyn1/*.dll dyn2/*.dll