CC=g++
EXE_FILE=escape

all: $(EXE_FILE)

$(EXE_FILE): MazeLocation.hpp Wall.o OpenSpace.o MazeLevel.o MazePerson.hpp IntrepidStudent.o TA.o Instructor.o Maze.o game.cpp
	$(CC) Wall.o OpenSpace.o MazeLevel.o IntrepidStudent.o TA.o Instructor.o Maze.o game.cpp -o $(EXE_FILE)

Wall.o: Wall.hpp Wall.cpp
	$(CC) -c Wall.cpp
	

OpenSpace.o: OpenSpace.hpp OpenSpace.cpp
	$(CC) -c OpenSpace.cpp
	

MazeLevel.o: MazeLevel.hpp MazeLevel.cpp
	$(CC) -c MazeLevel.cpp
	
IntrepidStudent.o: IntrepidStudent.hpp IntrepidStudent.cpp
	$(CC) -c IntrepidStudent.cpp	
	
TA.o: TA.hpp TA.cpp
	$(CC) -c TA.cpp
	
	
Instructor.o: Instructor.hpp Instructor.cpp
	$(CC) -c Instructor.cpp


Maze.o: Maze.hpp Maze.cpp
	$(CC) -c Maze.cpp


clean:
	rm -f *.o $(EXE_FILE)
