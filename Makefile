CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = main.cpp flashcard.cpp cardFunctions.cpp game_code.cpp
DEPS = flashcard.h cardFunctions.h game_code.h
OBJ = *.o
EXEC = flashcards.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(DEPS) $(LBLIBS)

$(OBJ): $(SRC)
	$(CXX) -c $(SRC) $(DEPS)

clean:
	rm -rf $(OBJ) $(EXEC)