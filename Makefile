# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11 -I/opt/homebrew/Cellar/sfml/2.6.1/include

# Source files
SRCS = main.cpp GameBoard.cpp Snake.cpp Food.cpp Score.cpp MainMenu.cpp HighScore.cpp GameOver.cpp TripleFood.cpp HowToPlay.cpp
#SRCS = GameBoard.cpp GameObject.cpp Food.cpp Snake.cpp MultiProgTest.cpp
# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = snake2

# Default rule
all: $(EXEC)

# Rule to compile .cpp files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link object files into executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC) -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system

# Clean rule
clean:
	rm -f $(OBJS) $(EXEC)
