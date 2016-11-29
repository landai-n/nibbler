//
// Game.cpp for  in /home/landai_n/rendu/nibbler/sources
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sat Apr  4 14:54:48 2015 Nathanael Landais
// Last update Sun Apr  5 21:16:54 2015 Benjamin COUILLAUD
//

#include	<sstream>
#include	<unistd.h>
#include	"Config.hpp"
#include	"PlayMulti.hpp"
#include	"Game.hpp"
#include	"Map.hpp"
#include	"Snake.hpp"
#include	"Console.hpp"
#include	"Server.hpp"
#include	"Start.hpp"

Game::Game()
{
  m_state = GameState::START;
  Console::getInstance()->aff_info("Game started");
  m_run = true;
  m_libMgr = NULL;
}

Game::~Game()
{
  Console::getInstance()->close();
  if (m_libMgr)
    delete (m_libMgr);
}

int		Game::myAtoi(char *input)
{
  std::istringstream iss(input);
  int tmp;

  iss>>tmp;
  return tmp;
}

bool		Game::init(int argc, char **argv)
{
  if (argc < 4)
    {
      std::cerr << "Usage: " << argv[0] << " width, height, [library_path] [host] [port]." << std::endl;
      return (false);
    }
  m_libMgr = new LibManager(argv[3]);
  m_window = m_libMgr->createWindow(WINDOW_SIZE, WINDOW_SIZE , "Nibbler", WINDOW_SIZE / MAP_SIZE);
  m_gameState[GameState::PLAY] = new Play(m_window, myAtoi(argv[1]), myAtoi(argv[2]));
  m_gameState[GameState::START] = new Start(m_window);
  if (argc == 6)
    m_gameState[GameState::PLAYMULTI] =
      new PlayMulti(m_window, myAtoi(argv[1]), myAtoi(argv[2]), argv[3], myAtoi(argv[4]));
  else
    {
      start_server();
      m_gameState[GameState::PLAYMULTI] =
	new PlayMulti(m_window, myAtoi(argv[1]), myAtoi(argv[2]));
    }
  m_gameState[GameState::PAUSE] = new Pause(m_window);
  m_gameState[GameState::GAMEOVER] = new GameOver(m_window);

  return (true);
}

void		Game::run()
{
  m_window->open();

  while (m_window->isOpen())
    m_state = getActiveState()->exec();
  m_run = false;
}

GameState	*Game::getActiveState()
{
  if (m_gameState.find(m_state) == m_gameState.end())
    return (m_gameState[GameState::PAUSE]);
  return (m_gameState[m_state]);
}

bool		Game::isRunning() const
{
  return (m_run);
}

void		Game::start_server()
{
  pthread_create(&m_serverThread, NULL, &server_launcher, (void *)this);
}

void		*Game::server_launcher(void *p_param)
{
  Game		*game = (Game *)p_param;
  Server	server;

  while (game->isRunning())
    server.run();
  return (NULL);
}
