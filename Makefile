CXX = g++
SRC = src/
CPU = src/cpu/
PROGS = utils.o cpu.o log.o

log.o: $(SRC)log.cpp $(SRC)log.h
		$(CXX) -c -std=c++11 $(SRC)log.cpp

utils.o: $(SRC)utils.cpp $(SRC)utils.h
		$(CXX) -c -std=c++11 $(SRC)utils.cpp

cpu.o: $(CPU)cpu.cpp $(CPU)cpu.h
		$(CXX) -c -std=c++11 $(CPU)cpu.cpp

main: $(PROGS) $(SRC)main.cpp
		$(CXX) -std=c++11 -o main $(PROGS) $(SRC)main.cpp

clean: 
		rm -f *.o *.obj *.exe $(PROGS)
