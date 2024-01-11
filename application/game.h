#ifndef GAME_H
#define GAME_H

class Game
{

public:
  Game () = default;
  ~Game () = default;

  Game *m_nextGame;

  virtual void init () = 0;
  virtual int calculateScore () = 0;
  void onIsFinished ();
};

#endif // GAME_H
