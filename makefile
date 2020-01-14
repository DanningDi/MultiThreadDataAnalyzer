SOURCE := src/*.cpp
OBJECT := $(patsubst src/%.cpp, obj/%.o, $(wildcard ${SOURCE}))
OBJECTDIR := obj

TARGET := decoder
CXX := g++
OPTION := -std=c++11 -o2 -g -pthread

INCLUDE := -Iinclude

all: ${TARGET}

test:
	@echo ${OBJECT}
	@echo ${SOURCE}

clean:
	@rm ${TARGET}
	@rm obj/*

${OBJECTDIR}/%.o: src/%.cpp
#$(CXX) ${INCLUDE} -c $<
	$(CXX) ${OPTION} ${INCLUDE} -c -o $@ $<

${TARGET} : ${OBJECT}
#	@echo ${OBJECT}
	$(CXX) ${OPTION} ${INCLUDE} -o ${TARGET} ${OBJECT}