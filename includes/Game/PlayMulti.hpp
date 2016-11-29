//
// PlayMulti.hpp for  in /home/landai_n/rendu/nibbler/includes
//
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
//
// Started on  Sun Apr  5 20:25:37 2015 Nathanael Landais
// Last update Sun Apr  5 20:25:37 2015 Nathanael Landais
//

#ifndef		PLAYMULTI_HPP
# define	PLAYMULTI_HPP

# include	"Select.hpp"
# include	"Play.hpp"

class				PlayMulti : public Play
{
public:
  PlayMulti(IWindow *, int, int, const std::string &host = "127.0.0.1", int port = 3140);
  virtual			~PlayMulti();
  virtual void			display();
  virtual void			control();
  virtual GameState::e_state	exec();
  bool				connect();
  void				sendPosition();
  void				execPackets();
  void				displayEnnemy(ByteBuffer *);
private:
  Socket			*m_socket;
  Select			m_select;
  Select			*m_write;
  std::string			m_host;
  int				m_port;
};

#endif
