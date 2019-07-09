#ifndef BDA_engine_hpp_
#define BDA_engine_hpp_

// This is the overall game class.

extern int lastKeypress;

class Engine {
public:
    Engine();
    ~Engine();
    
    bool update();
    bool render();

    std::shared_ptr<Actor> hero;
    ActorManager manager_ACTR;
private:
};

#endif // BDA_engine_hpp_