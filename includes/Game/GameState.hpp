//
// GameState.hpp for  in /home/landai_n/rendu/nibbler
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sat Apr  4 22:35:43 2015 Nathanael Landais
// Last update Sat Apr  4 22:35:43 2015 Nathanael Landais
//

#ifndef		GAMESTATE_HPP
# define	GAMESTATE_HPP

class		GameState
{
public:
  enum          e_state
    {
      START,
      PLAY,
      PLAYMULTI,
      PAUSE,
      GAMEOVER
    };
  virtual		~GameState() {};
  virtual void		control() = 0;
  virtual void		display() = 0;
  virtual e_state	exec() = 0;
};

#endif
