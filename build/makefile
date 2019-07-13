objects = bresenham.o tiles.o ai.o actor.o map.o gui.o engine.o main.o
flags = -L../lib/ -lBearLibTerminal
debug = -Wall -Wextra -g

VPATH = ../src/

main : $(objects)
	g++ $(flags) $(debug) -o ../bin/main $(objects)

bresenham.o : bresenham.hpp
tiles.o : tiles.hpp
ai.o : ai.hpp
actor.o : actor.hpp
map.o : map.hpp
gui.o : gui.hpp
engine.o : engine.hpp
main.o : main.hpp

.PHONY : clean
clean :
	rm -f $(objects)
