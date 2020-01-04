GTESTFLAG = -lgtest -std=c++0x
INCLUDE = -I/usr/local/include
LIBDIR = -L/usr/local/lib

CC = g++
CFLAGS = $(GTESTFLAG)

All: main

main: function_as_parameter.cc
	$(CC) function_as_parameter.cc $(CFLAGS)

clean:
	rm *.o