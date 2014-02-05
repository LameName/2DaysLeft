#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/AIPad.o \
	${OBJECTDIR}/Game.o \
	${OBJECTDIR}/MainMenu.o \
	${OBJECTDIR}/PlayerPad.o \
	${OBJECTDIR}/Puck.o \
	${OBJECTDIR}/SplashScreen.o \
	${OBJECTDIR}/Sprite.o \
	${OBJECTDIR}/SpriteManager.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lsfml-audio -lsfml-audio.so.2 -lsfml-audio.so.2.1 -lsfml-graphics -lsfml-graphics.so.2 -lsfml-graphics.so.2.1 -lsfml-network -lsfml-network.so.2 -lsfml-network.so.2.1 -lsfml-system -lsfml-system.so.2 -lsfml-system.so.2.1 -lsfml-window -lsfml-window.so.2 -lsfml-window.so.2.1

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pong

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pong: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pong ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/AIPad.o: AIPad.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/SFML/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/AIPad.o AIPad.cpp

${OBJECTDIR}/Game.o: Game.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/SFML/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Game.o Game.cpp

${OBJECTDIR}/MainMenu.o: MainMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/SFML/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/MainMenu.o MainMenu.cpp

${OBJECTDIR}/PlayerPad.o: PlayerPad.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/SFML/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/PlayerPad.o PlayerPad.cpp

${OBJECTDIR}/Puck.o: Puck.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/SFML/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Puck.o Puck.cpp

${OBJECTDIR}/SplashScreen.o: SplashScreen.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/SFML/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/SplashScreen.o SplashScreen.cpp

${OBJECTDIR}/Sprite.o: Sprite.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/SFML/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sprite.o Sprite.cpp

${OBJECTDIR}/SpriteManager.o: SpriteManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/SFML/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/SpriteManager.o SpriteManager.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../SFML/SFML/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pong

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
