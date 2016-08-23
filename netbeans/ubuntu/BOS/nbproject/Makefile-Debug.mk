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
CND_PLATFORM=CLang-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/52a4beb5/arquivo.o \
	${OBJECTDIR}/_ext/5c997766/bos.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ../../../exe/${CND_PLATFORM}-${CND_CONF}/BOS.exe

../../../exe/${CND_PLATFORM}-${CND_CONF}/BOS.exe: ${OBJECTFILES}
	${MKDIR} -p ../../../exe/${CND_PLATFORM}-${CND_CONF}
	${LINK.c} -o ../../../exe/${CND_PLATFORM}-${CND_CONF}/BOS ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/52a4beb5/arquivo.o: ../../../src/arquivo.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/52a4beb5
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../../include -I../../../include/union_find -I../../../include/provisional -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/52a4beb5/arquivo.o ../../../src/arquivo.c

${OBJECTDIR}/_ext/5c997766/bos.o: ../../../src/provisional/bos.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c997766
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../../include -I../../../include/union_find -I../../../include/provisional -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c997766/bos.o ../../../src/provisional/bos.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ../../../exe/${CND_PLATFORM}-${CND_CONF}/BOS.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
