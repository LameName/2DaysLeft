#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
CXX=g++




# Object Files
OBJECTFILES=AIPad.o Upgrade.o Game.o MainMenu.o PlayerPad.o Puck.o SplashScreen.o Sprite.o SpriteManager.o CounterManager.o main.o

# C Compiler Flags

CXXFLAGS=-std=c++0x -g -Wall

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window

# Build Targets



all: $(OBJECTFILES)
	$(CXX) -o pong ${OBJECTFILES} ${LDLIBSOPTIONS}

%.o: %.c
	$(CXX) $(CXXFLAGS) -o %.o %.cpp $<
	
clean:
	rm -rf *o pong
