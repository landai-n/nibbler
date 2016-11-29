//
// Pause.hpp for  in /home/landai_n/rendu/nibbler
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sat Apr  4 22:38:20 2015 Nathanael Landais
// Last update Sat Apr  4 22:38:20 2015 Nathanael Landais
//

#ifndef		PAUSE_HPP
# define	PAUSE_HPP

# include	"GameState.hpp"
# include	"IWindow.hpp"

class			Pause : public GameState
{
public:
  Pause(IWindow *);
  virtual			~Pause() {}
  virtual void			control();
  virtual void			display();
  virtual GameState::e_state	exec();
private:
  IWindow		*m_window;
  GameState::e_state	m_state;
};

#endif
