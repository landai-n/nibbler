//
// Socket.hpp for  in /home/landai_n/rendu/nibbler/includes/Server
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sun Apr  5 15:48:51 2015 Nathanael Landais
// Last update Sun Apr  5 15:48:51 2015 Nathanael Landais
//

#ifndef		__SOCKET_HPP__
# define	__SOCKET_HPP__

# include               <sys/types.h>
# include               <sys/socket.h>
# include               <netinet/in.h>
# include               <arpa/inet.h>
# include               <unistd.h>
# include               <netdb.h>
# include		<fcntl.h>
# include		"Console.hpp"
# include		"ByteBuffer.hpp"

typedef                 int SOCKET;
typedef struct          sockaddr_in SOCKADDR_IN;
typedef struct          sockaddr SOCKADDR;
typedef struct          in_addr IN_ADDR;

class		Socket
{
public:
  Socket();
  bool				init();
  bool				new_client(Socket &prev);
  bool				connect(const std::string &host, int port);
  bool				send(ByteBuffer *);
  ByteBuffer			*receive();
  bool				nodelay();
  SOCKET			&get_sock();
  SOCKADDR_IN			&get_sin();
  socklen_t			&get_size();
  void				set_sock(SOCKET sock);
  unsigned int			gen_id();
  void				end();
private:
  SOCKET		m_sock;
  SOCKADDR_IN		m_sin;
  socklen_t		m_size;
  struct hostent	*m_hostinfo;
};

#endif
