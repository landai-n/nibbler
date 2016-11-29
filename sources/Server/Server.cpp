//
// Server.cpp for  in /home/landai_n/rendu/nibbler/sources/Server
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sun Apr  5 18:24:31 2015 Nathanael Landais
// Last update Sun Apr  5 18:24:31 2015 Nathanael Landais
//

#include	<unistd.h>
#include	"Server.hpp"

Server::Server()
{
  Console::getInstance()->aff_info("Server started");
  m_socket = new Socket();
  if (!m_socket->init())
    m_socket->set_sock(-1);
  m_select.add_fd(m_socket->get_sock());
}

Server::~Server()
{
  delete (m_socket);
  Console::getInstance()->aff_info("Server stopped");
}

void		Server::acceptClients()
{
  Socket	*l_new = new Socket();
  Socket	*last_socket;

  if (m_clientList.empty())
    last_socket = m_socket;
  else
    last_socket = m_clientList.back();
  if (!l_new->new_client(*last_socket))
    return;
  m_select.add_fd(l_new->get_sock());
  m_clientList.push_back(l_new);
  Console::getInstance()->aff_info("New client connected");
}

void		Server::run()
{
  m_select.set_timeout(5, 0);
  m_select.reset_fd();
  m_select.wait();
  if (m_select.isset(m_socket->get_sock()))
    acceptClients();
  for (std::list<Socket *>::iterator it = m_clientList.begin(); it != m_clientList.end(); ++it)
    propagatePackets((*it));
  for (std::list<Socket *>::iterator it = m_clientList.begin(); it != m_clientList.end(); ++it)
    if ((*it)->get_sock() == -1)
      {
  	m_clientList.erase(it);
  	break ;
      }
  clearPacketList();
  usleep(1000);
}

void		Server::readPacket(Socket *p_socket)
{
  ByteBuffer	*packet;

  if ((packet = p_socket->receive()) == NULL)
    return ;
  m_packetList.push_back(packet);
}

void		Server::propagatePackets(Socket *p_socket)
{
  for (std::list<ByteBuffer *>::iterator it = m_packetList.begin(); it != m_packetList.end(); ++it)
    if (p_socket->send(*it) == false)
      disconnectClient(p_socket);
}

void		Server::clearPacketList()
{
  for (std::list<ByteBuffer *>::iterator it = m_packetList.begin(); it != m_packetList.end(); ++it)
    delete (*it);
  m_packetList.clear();
}

void		Server::disconnectClient(Socket *p_socket)
{
  m_select.rm_fd(p_socket->get_sock());
  p_socket->end();
  p_socket->set_sock(-1);
  Console::getInstance()->aff_info("Disconnect a client");
}
