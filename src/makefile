objects = main.o engine.o map.o actor.o ai.o gui.o

main : $(objects)
	g++ -L../lib/ -lBearLibTerminal -o main $(objects)

main.o : main.hpp
engine.o : engine.hpp
map.o : map.hpp
actor.o : actor.hpp
ai.o : ai.hpp
gui.o : gui.hpp

.PHONY : clean
clean :
	rm -f $(objects)
