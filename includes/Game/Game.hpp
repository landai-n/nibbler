//
// Game.hpp for  in /home/landai_n/rendu/nibbler
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sat Apr  4 14:53:00 2015 Nathanael Landais
// Last update Sat Apr  4 14:53:00 2015 Nathanael Landais
//

#ifndef		GAME_HPP
# define	GAME_HPP

# include	<map>
# include	<iostream>
# include	<pthread.h>
# include	"LibManager.hpp"
# include	"IWindow.hpp"
# include	"Snake.hpp"
# include	"Play.hpp"
# include	"Pause.hpp"
# include	"GameOver.hpp"
# include	"GameState.hpp"

class		Game
{
public:
  Game();
  ~Game();
  bool		init(int, char **);
  bool		isRunning() const;
  void		run();
  int		myAtoi(char *);

private:
  LibManager					*m_libMgr;
  IWindow					*m_window;
  GameState::e_state				m_state;
  std::map<GameState::e_state, GameState *>	m_gameState;
  pthread_t					m_serverThread;
  bool						m_run;
  GameState					*getActiveState();
  void						start_server();
  static void					*server_launcher(void *);
};

#endif
