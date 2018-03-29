ifeq ($(OS),Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell uname -s)
endif

ifeq ($(detected_OS),Windows)
	STDFLAG = -std=c++11
endif
ifeq ($(detected_OS),Darwin)  # Mac OS X
    STDFLAG = -std=c++1y  
endif
ifeq ($(detected_OS),Linux)
    STDFLAG = -std=c++11
endif

CXX = g++
SRC = src/
CPU = src/gba/cpu/
LDR = src/gba/loader/
OARGS = -c -std=c++11 -o bin/
PROGS = utils.o cpu.o log.o load.o memory.o
DIRPROGS = bin/utils.o bin/cpu.o bin/log.o bin/load.o bin/memory.o
VPATH = bin:src:src/gba:src/gba/cpu:src/gba/loader:src/gba/memory

%.o : %.cpp | bin 
		$(CXX) -std=c++11 -c -o bin/$@ $<

yumi: $(PROGS) $(SRC)yumi.cpp | bin/
		$(CXX) -std=c++11 -o bin/yumi $(DIRPROGS) $(SRC)yumi.cpp

clean: 
		rm -rf *.o *.obj *.exe $(PROGS) bin/

bin:
		mkdir bin