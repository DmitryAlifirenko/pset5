# compiler to use
CC = g++

# flags to pass compiler
CFLAGS = -ggdb3 -g -O0 -Wall -Werror #-Wno-unused-variable 

# name for executable
EXE = speller #test

# space-separated list of header files
HDRS =  HashMap.h dictionary.h #ArrayList.h LinkedList.h

# space-separated list of libraries, if any,
# each of which should be prefixed with -l
LIBS =

# space-separated list of source files
SRCS =  HashMap.cpp Speller.cpp dictionary.cpp #Test.cpp ArrayList.cpp LinkedList.cpp

# automatically generated list of object files
OBJS = $(SRCS:.c=.o)


# default target
$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

# dependencies 
$(OBJS): $(HDRS) Makefile

# housekeeping
clean:
	rm -f core $(EXE) *.o

