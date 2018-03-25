CXX = g++
SRC = src/
CPU = src/gba/cpu/
LDR = src/gba/loader/
OARGS = -c -std=c++11 -o bin/
PROGS = utils.o cpu.o log.o load.o gba.o
DIRPROGS = bin/utils.o bin/cpu.o bin/log.o bin/load.o bin/gba.o
VPATH = bin:src:src/gba:src/gba/cpu:src/gba/loader

%.o : %.cpp | bin/
		$(CXX) -c -std=c++11 -o bin/$@ $<

yumi: $(PROGS) $(SRC)yumi.cpp | bin/
		$(CXX) -std=c++11 -o bin/yumi $(DIRPROGS) $(SRC)yumi.cpp

clean: 
		rm -rf *.o *.obj *.exe $(PROGS) bin/

bin/:
		mkdir bin