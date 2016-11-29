//
// Server.hpp for  in /home/landai_n/rendu/nibbler/includes/Server
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sun Apr  5 14:56:14 2015 Nathanael Landais
// Last update Sun Apr  5 14:56:14 2015 Nathanael Landais
//

#ifndef			SERVER_HPP
# define		SERVER_HPP

# include		<list>
# include		"ByteBuffer.hpp"
# include		"Select.hpp"
# include		"Packet.hpp"

class			Server
{
public:
  Server();
  ~Server();
  void				run();
  void				acceptClients();
  void				readPacket(Socket *);
  void				propagatePackets(Socket *);
  void				clearPacketList();
  void				disconnectClient(Socket *);
private:
  std::list<Socket *>		m_clientList;
  std::list<ByteBuffer *>	m_packetList;
  Socket			*m_socket;
  Select			m_select;
};

#endif
