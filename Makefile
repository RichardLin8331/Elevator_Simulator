CPP_SOURCES = $(wildcard ./*.cpp)
OBJ_FILES = $(patsubst ./%.cpp, ./%.o, $(CPP_SOURCES))

all: compile link run
compile: $(OBJ_FILES)
%.o: ./%.cpp
	g++ -c -o $@ $<
link: $(OBJ_FILES)
	g++ $(OBJ_FILES) -o main
run: link
	./main
clean:
	rm ./*.o