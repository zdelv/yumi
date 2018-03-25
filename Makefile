CXX = g++
SRC = src/
CPU = src/cpu/
LDR = src/loader/
OARGS = -c -std=c++11
PROGS = utils.o cpu.o log.o rom_load.o

rom_load.o: $(LDR)rom_load.cpp $(LDR)load.h
		$(CXX) $(OARGS) $(LDR)rom_load.cpp

log.o: $(SRC)log.cpp $(SRC)log.h
		$(CXX) $(OARGS) $(SRC)log.cpp

utils.o: $(SRC)utils.cpp $(SRC)utils.h
		$(CXX) $(OARGS) $(SRC)utils.cpp

cpu.o: $(CPU)cpu.cpp $(CPU)cpu.h
		$(CXX) $(OARGS) $(CPU)cpu.cpp

main: $(PROGS) $(SRC)main.cpp
		$(CXX) -std=c++11 -o main $(PROGS) $(SRC)main.cpp

clean: 
		rm -f *.o *.obj *.exe $(PROGS)
