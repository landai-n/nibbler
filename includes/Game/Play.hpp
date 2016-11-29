//
// Play.hpp for  in /home/landai_n/rendu/nibbler
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sat Apr  4 22:15:23 2015 Nathanael Landais
// Last update Sat Apr  4 22:15:23 2015 Nathanael Landais
//

#ifndef		PLAY_HPP
# define	PLAY_HPP

# include	"Snake.hpp"
# include	"Map.hpp"
# include	"GameState.hpp"

class		IWindow;

class		Play : public GameState
{
public:
  Play(IWindow *, int, int);
  virtual				~Play();
  virtual void				control();
  virtual void				display();
  void					reset();
  virtual GameState::e_state		exec();
protected:
  int					m_width;
  int					m_height;
  int					m_score;
  Snake					*m_snake;
  Map					*m_map;
  IWindow				*m_window;
  GameState::e_state			m_state;
  void					init();
};

#endif
