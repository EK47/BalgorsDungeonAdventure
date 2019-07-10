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
  std::shared_ptr<Map> map;
  std::shared_ptr<Gui> gui;
  ActorManager manager_ACTR;
private:
};

extern Engine engine;

#endif // BDA_engine_hpp_
