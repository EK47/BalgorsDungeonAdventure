objects = main.o actor.o map.o engine.o ai.o gui.o

main : $(objects)
	g++ -L../lib/ -lBearLibTerminal -o main $(objects)

main.o : main.hpp
actor.o : actor.hpp
map.o : map.hpp
engine.o : engine.hpp
ai.o : ai.hpp
gui.o : gui.hpp

.PHONY : clean
clean :
	rm -f $(objects)
