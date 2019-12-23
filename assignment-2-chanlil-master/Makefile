CC=g++
EXE_FILE=gofish

all: $(EXE_FILE)

$(EXE_FILE): card.o deck.o hand.o player.o game.o gofish.cpp 
	$(CC) card.o deck.o hand.o player.o game.o gofish.cpp -o $(EXE_FILE)

card.o: card.hpp card.cpp
	$(CC) -c card.cpp

deck.o: deck.hpp deck.cpp
	$(CC) -c deck.cpp

hand.o: hand.hpp hand.cpp
	$(CC) -c hand.cpp

player.o: player.hpp player.cpp
	$(CC) -c player.cpp

game.o: game.hpp game.cpp
	$(CC) -c game.cpp

clean:
	rm -f *.o $(EXE_FILE)

