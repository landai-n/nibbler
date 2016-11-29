//
// PlayMulti.hpp for  in /home/landai_n/rendu/nibbler/sources/Game
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sun Apr  5 20:29:10 2015 Nathanael Landais
// Last update Sun Apr  5 20:29:10 2015 Nathanael Landais
//

#include	<iostream>
#include	"PlayMulti.hpp"
#include	"Packet.hpp"

PlayMulti::PlayMulti(IWindow *p_window, int p_width, int p_height,
		     const std::string &host, int port)
  : Play(p_window, p_width, p_height), m_host(host), m_port(port)
{
  m_socket = NULL;
  m_write = new Select(true, false);
}

PlayMulti::~PlayMulti()
{
  m_socket->end();
  delete (m_socket);
  delete (m_write);
}

bool		PlayMulti::connect()
{
  m_socket = new Socket();
  if (m_socket->connect(m_host, m_port))
    {
      m_select.add_fd(m_socket->get_sock());
      m_write->add_fd(m_socket->get_sock());
      return (true);
    }
  delete (m_socket);
  m_socket = NULL;
  return (false);
}

void		PlayMulti::display()
{
   Play::display();
   execPackets();
}

void		PlayMulti::control()
{
   Play::control();
   if (m_state == GameState::PAUSE)
     m_state = GameState::PLAYMULTI;
}

GameState::e_state	PlayMulti::exec()
{
  m_state = GameState::PLAYMULTI;
  if (m_socket == NULL)
    if (!connect())
      return (GameState::START);
  control();
  this->control();
  m_score += m_snake->triggerEntities();
  if (m_snake->collid() == false)
    {
      if (m_snake->crossBorder() == false)
        m_snake->move();
      this->display();
    }
  else
    this->reset();
  sendPosition();
  return (m_state);
}

void		PlayMulti::sendPosition()
{
  ByteBuffer	packet(PKT_IDENTITY);
  const Color	&color(m_snake->getColor());

  packet.write<int>(m_snake->getX());
  packet.write<int>(m_snake->getY());
  packet.write<unsigned char>(color.r);
  packet.write<unsigned char>(color.g);
  packet.write<unsigned char>(color.b);
  packet.release();

  m_write->set_timeout(0, 100000);
  m_write->wait();
  if (m_write->isset(m_socket->get_sock()))
    m_socket->send(&packet);
}

void		PlayMulti::execPackets()
{
  m_select.set_timeout(0, 10000);
  m_select.wait();
  if (m_select.isset(m_socket->get_sock()))
    {
      displayEnnemy(m_socket->receive());
    }
}

void		PlayMulti::displayEnnemy(ByteBuffer *p_packet)
{
  p_packet->read<int>();
  p_packet->read<int>();
  int		x = p_packet->read<int>();
  int		y = p_packet->read<int>();
  size_t        partSizeX = m_window->getWidth() / m_width;
  size_t        partSizeY = m_window->getHeight() / m_height;

  m_window->drawSquare(x * partSizeX, y * partSizeY, partSizeX, Color(255,0,255));
}
