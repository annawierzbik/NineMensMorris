CXX = g++

SRC = coordinates.cpp game_board.cpp nine_mens_morris.cpp player.cpp main.cpp

TARGET = game.exe

$(TARGET): $(SRC)
	$(CXX) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean
