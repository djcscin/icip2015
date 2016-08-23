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
CC=clang
CCC=clang++
CXX=clang++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=CLang-Linux-x86
CND_DLIB_EXT=so
CND_CONF=ReleaseO2
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1386528437/arquivo.o \
	${OBJECTDIR}/_ext/1553561446/test.o


# C Compiler Flags
CFLAGS=-O2 -Winline -fomit-frame-pointer

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ../../../exe/${CND_PLATFORM}-${CND_CONF}/ICIP2015

../../../exe/${CND_PLATFORM}-${CND_CONF}/ICIP2015: ${OBJECTFILES}
	${MKDIR} -p ../../../exe/${CND_PLATFORM}-${CND_CONF}
	${LINK.c} -o ../../../exe/${CND_PLATFORM}-${CND_CONF}/ICIP2015 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1386528437/arquivo.o: ../../../src/arquivo.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1386528437
	${RM} "$@.d"
	$(COMPILE.c) -I../../../include -I../../../include/union_find -I../../../include/provisional -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1386528437/arquivo.o ../../../src/arquivo.c

${OBJECTDIR}/_ext/1553561446/test.o: ../../../src/provisional/test.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1553561446
	${RM} "$@.d"
	$(COMPILE.c) -I../../../include -I../../../include/union_find -I../../../include/provisional -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1553561446/test.o ../../../src/provisional/test.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ../../../exe/${CND_PLATFORM}-${CND_CONF}/ICIP2015

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
