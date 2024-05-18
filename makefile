# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -std=c++11 -Wall

# SFML libraries
SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SRCS := main.cpp Snake.cpp Food.cpp GameBoard.cpp Score.cpp MainMenu.cpp HighScore.cpp GameOver.cpp GameObject.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

# Executable
EXEC := sfml-app

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS) $(EXEC)
