SOURCE := src/*.cpp
OBJECT := $(patsubst src/%.cpp, obj/%.o, $(wildcard ${SOURCE}))
OBJECTDIR := obj

TARGET := decoder
CXX := g++
OPTION := -std=c++11 -o2 -g -pthread

INCLUDE := -I${CODA}/Linux-x86_64/include -Iinclude
CODALIBS := -L${CODA}/Linux-x86_64/lib -levio -levioxx -lexpat


all: ${TARGET}

test:
	@echo ${OBJECT}
	@echo ${SOURCE}

clean:
	@rm ${TARGET}
	@rm obj/*

${OBJECTDIR}/%.o: src/%.cpp
#$(CXX) ${INCLUDE} -c $<
	$(CXX) ${OPTION} ${INCLUDE} ${CODALIBS} -c -o $@ $<

${TARGET} : ${OBJECT}
#	@echo ${OBJECT}
	$(CXX) ${OPTION} ${INCLUDE} ${CODALIBS} -o ${TARGET} ${OBJECT}
