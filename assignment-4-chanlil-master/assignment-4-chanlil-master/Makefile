CC=g++
EXE_FILE=play_game

all: $(EXE_FILE)

$(EXE_FILE): Room.o Event.hpp Wumpus.o Bats.o Pit.o Gold.o Empty.o hunt.o play_game.cpp
	$(CC) Room.o Wumpus.o Bats.o Pit.o Gold.o Empty.o hunt.o play_game.cpp -o $(EXE_FILE)

Room.o: Room.hpp Room.cpp
	$(CC) -c Room.cpp
 
Wumpus.o: Wumpus.hpp Wumpus.cpp
	$(CC) -c Wumpus.cpp
	
Bats.o: Bats.hpp Bats.cpp
	$(CC) -c Bats.cpp
	
Pit.o: Pit.hpp Pit.cpp
	$(CC) -c Pit.cpp
	
Gold.o: Gold.hpp Gold.cpp
	$(CC) -c Gold.cpp
	
Empty.o: Empty.hpp Empty.cpp
	$(CC) -c Empty.cpp
	
hunt.o: hunt.hpp hunt.cpp
	$(CC) -c hunt.cpp
	
clean:
	rm -f *.o $(EXE_FILE)
