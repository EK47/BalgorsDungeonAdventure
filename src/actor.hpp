#ifndef BDA_actor_hpp_
#define BDA_actor_hpp_

extern int lastKeypress;

class Actor
{
public:
	Actor( int x, int y, char glyph, std::string name, std::string fcolor );
	~Actor();

	int x, y;
	char glyph;
	std::string name, fcolor, bcolor;

	bool update( std::shared_ptr<Actor> actor );
	bool render();

	std::unique_ptr<AI> ai = nullptr;

	// This exists solely for organization in the ActorManager system.
	enum ActorType { Enemy, Item, Corpse, NONE };
	ActorType actorType { NONE };

private:
};

// Actor Manager System
/*
 * The actor manager controls all game actors aka anything that isn't terrain. The manager is essentially the storage bag
 * that all actors reside within.
 */

class ActorManager
{
public:
	// A list of the lists of actor types.
	ActorManager();
	~ActorManager();

	/* Actor Box
	 *
	 *	The box stores the actors in a specific order.
	 *	Enemies > Items > Corpses
	 *	Enemies can be inserted at the front in all cases.
	 *	Keeping track of the amount of enemies, one can then easily insert items after the index of the last enemy in the list.
	 *	Likewise, one can insert all corpses after the last item. This system makes rendering easier.
	 */

	std::vector< std::shared_ptr<Actor> > actorBox;

private:
};

#endif // BDA_actor_hpp_
