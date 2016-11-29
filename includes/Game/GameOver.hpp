//
// GameOver.hpp for  in /home/landai_n/rendu/nibbler
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sat Apr  4 23:24:11 2015 Nathanael Landais
// Last update Sat Apr  4 23:24:11 2015 Nathanael Landais
//

#ifndef		GAMEOVER_HPP
# define	GAMEOVER_HPP

# include	"GameState.hpp"
# include	"IWindow.hpp"

class			GameOver : public GameState
{
public:
  GameOver(IWindow *);
  virtual			~GameOver() {}
  virtual void			control();
  virtual void			display();
  virtual GameState::e_state	exec();
private:
  IWindow			*m_window;
  GameState::e_state		m_state;
};

#endif
