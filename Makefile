CPP_SOURCES = $(wildcard ./*.cpp)
OBJ_FILES = $(patsubst ./%.cpp, ./%.o, $(CPP_SOURCES))
MAIN_OBJ_FILES = $(filter-out lib_test.o, $(wildcard *.o))
GTEST_LIBS = -lgtest -lgtest_main -pthread

all: compile link run
compile: $(OBJ_FILES)
%.o: ./%.cpp
	g++ -std=c++11 -c -o $@ $<
link: $(OBJ_FILES)
	g++ -std=c++11 $(MAIN_OBJ_FILES) -o main
run: link
	./main
test: $(OBJ_FILES)
	g++  lib_test.o lib.o -o run_tests $(GTEST_LIBS)
	./run_tests
	
clean:
	rm ./*.o
	rm ./main