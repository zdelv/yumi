CXX = g++
SRC = src/
CPU = src/cpu/
LDR = src/loader/
OARGS = -c -std=c++11 -o bin/
PROGS = utils.o cpu.o log.o rom_load.o
DIRPROGS = bin/utils.o bin/cpu.o bin/log.o bin/rom_load.o
VPATH = bin:src:src/cpu:src/loader

#rom_load.o: $(LDR)rom_load.cpp $(LDR)load.h  bin/
#		$(CXX) $(OARGS)rom_load.o $(LDR)rom_load.cpp
#
#log.o: $(SRC)log.cpp $(SRC)log.h bin/
#		$(CXX) $(OARGS)log.o $(SRC)log.cpp
#
#utils.o: $(SRC)utils.cpp $(SRC)utils.h bin/
#		$(CXX) $(OARGS)utils.o $(SRC)util.cpp
#
#cpu.o: $(CPU)cpu.cpp $(CPU)cpu.h bin/
#		$(CXX) $(OARGS)cpu.o $(CPU)cpu.cpp

%.o : %.cpp | bin/
		$(CXX) -c -std=c++11 -o bin/$@ $<

main: $(PROGS) $(SRC)main.cpp | bin/
		$(CXX) -std=c++11 -o bin/main $(DIRPROGS) $(SRC)main.cpp

clean: 
		rm -rf *.o *.obj *.exe $(PROGS) bin/

bin/:
		mkdir bin