#ifndef BDA_ai_hpp_
#define BDA_ai_hpp_

// AI is a virtual class. It exists only as an inheritance framework so accessing the specific functions of its child classes is possible

extern int lastKeypress;

class AI
{
public:
	AI() { ; }
	~AI() { ; }

	virtual bool update( std::shared_ptr<Actor> actor ) = 0;
private:
};

// This is the PlayerAI class. Only one single PlayerAI should exist.

class PlayerAI : public AI
{
public:
	PlayerAI();
	~PlayerAI();

	bool update( std::shared_ptr<Actor> actor );
private:
};

// All monsters are based on this AI.

class MonsterAI : public AI
{
public:
	MonsterAI();
	~MonsterAI();

	bool update( std::shared_ptr<Actor> actor );
private:
};

#endif // BDA_ai_hpp_
