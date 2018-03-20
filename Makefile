CXX = g++
SRC = src/
CPU = src/cpu/
PROGS = utils.o cpu.o

utils.o: $(SRC)utils.cpp $(SRC)utils.h
		$(CXX) -c $(SRC)utils.cpp

cpu.o: $(CPU)cpu.cpp $(CPU)cpu.h
		$(CXX) -c $(CPU)cpu.cpp

main: utils.o cpu.o src/main.cpp
		$(CXX) -o main.exe utils.o cpu.o $(SRC)main.cpp

clean: 
		rm -f *.o *.obj *.exe $(PROGS)
