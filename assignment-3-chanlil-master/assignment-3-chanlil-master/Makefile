CC=g++
EXE_FILE=zoo_tycoon

all: $(EXE_FILE)

$(EXE_FILE): Animal.o Monkey.o Sloth.o Otter.o Zoo.o zoo_tycoon.cpp
	$(CC) Animal.o Monkey.o Sloth.o Otter.o Zoo.o zoo_tycoon.cpp -o $(EXE_FILE)

Animal.o: Animal.hpp Animal.cpp
	$(CC) -c Animal.cpp

Monkey.o: Monkey.hpp Monkey.cpp
	$(CC) -c Monkey.cpp

Sloth.o: Sloth.hpp Sloth.cpp
	$(CC) -c Sloth.cpp
	
Otter.o: Otter.hpp Otter.cpp
	$(CC) -c Otter.cpp
	
Zoo.o: Zoo.hpp Zoo.cpp
	$(CC) -c Zoo.cpp
	
clean:
	rm -f *.o $(EXE_FILE)
