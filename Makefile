CXX = g++
SRC = src/
CPU = src/gba/cpu/
LDR = src/loader/
OARGS = -c -std=c++11 -o bin/
PROGS = utils.o cpu.o log.o rom_load.o gba.o
DIRPROGS = bin/utils.o bin/cpu.o bin/log.o bin/rom_load.o bin/gba.o
VPATH = bin:src:src/gba:src/gba/cpu:src/gba/loader

%.o : %.cpp | bin/
		$(CXX) -c -std=c++11 -o bin/$@ $<

main: $(PROGS) $(SRC)main.cpp | bin/
		$(CXX) -std=c++11 -o bin/main $(DIRPROGS) $(SRC)main.cpp

clean: 
		rm -rf *.o *.obj *.exe $(PROGS) bin/

bin/:
		mkdir bin