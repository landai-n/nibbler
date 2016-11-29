#include	<iostream>
#include	<errno.h>
#include	<cstring>
#include	"Socket.hpp"
#include	"Config.hpp"

Socket::Socket()
{
  m_size = sizeof(m_sin);
}

void    Socket::set_sock(SOCKET sock)
{
  m_sock = sock;
}

SOCKET			&Socket::get_sock()
{
  return (m_sock);
}

SOCKADDR_IN		&Socket::get_sin()
{
  return (m_sin);
}

socklen_t		&Socket::get_size()
{
  return (m_size);
}

unsigned int		Socket::gen_id()
{
  static unsigned int	id(0);

  return (id++);
}

bool			Socket::init()
{
  int   val(0);

  Console::getInstance()->aff_info("Initializing socket");
  if ((m_sock = socket(AF_INET, SOCK_STREAM | O_NONBLOCK, 0)) == -1)
    return (Console::getInstance()->aff_error(strerror(errno)));
  if (setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(int)) < 0)
    Console::getInstance()->aff_error(strerror(errno));
  fcntl(m_sock, F_SETFL, O_NONBLOCK);
  m_sin.sin_addr.s_addr = htonl(INADDR_ANY);
  m_sin.sin_family = AF_INET;
  m_sin.sin_port = htons(3140);
  if (bind(m_sock, (SOCKADDR *) &m_sin, sizeof(m_sin)) == -1)
    return (Console::getInstance()->aff_error("Socket : bind : " + std::string(strerror(errno))));
  if (listen(m_sock, 10) == -1)
    return (Console::getInstance()->aff_error("Socket : listen : " + std::string(strerror(errno))));
  return (Console::getInstance()->aff_success("Socket initialized"));
}

void	Socket::end()
{
  if (m_sock > 0)
    close(m_sock);
}

bool			Socket::new_client(Socket &prev)
{
  m_sock = accept(prev.get_sock(), (SOCKADDR *)&m_sin, &m_size);
  if (m_sock != -1)
    return (true);
  return (false);
}

bool			Socket::connect(const std::string &host, int port)
{
  Console::getInstance()->aff_info("Initializing client socket");
  if ((m_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    return (Console::getInstance()->aff_error(strerror(errno)));
  if ((m_hostinfo = gethostbyname(host.c_str())) == NULL)
    return (Console::getInstance()->aff_error("Host not found"));
  m_sin.sin_addr = *(IN_ADDR *) m_hostinfo->h_addr;
  m_sin.sin_family = AF_INET;
  m_sin.sin_port = htons(port);
  if (::connect(m_sock, (SOCKADDR *) &m_sin, sizeof(SOCKADDR)) == -1)
    return (Console::getInstance()->aff_error(strerror(errno)));
  return (Console::getInstance()->aff_success("Socket initialized"));
}

ByteBuffer         *Socket::receive()
{
  int                   byte(0);
  ByteBuffer		*buffer = new ByteBuffer();
  uint32_t		size = 0;
  std::vector<uint8_t>	*data;

  if ((byte = read(m_sock, &size, sizeof(size))) < 0)
    {
      if (byte == 0)
	{
	  this->end();
	  this->set_sock(-1);
	}
      return (NULL);
    }
  data = new std::vector<uint8_t>(size);
  if ((byte = read(m_sock, &data[0], size)) < 0)
    return (NULL);
  if (byte == 0)
    {
      this->end();
      this->set_sock(-1);
    }
  buffer->setStorage(data);
  return (buffer);
}

bool                    Socket::send(ByteBuffer *buffer)
{
  if (write(m_sock, &(buffer->getStorage()[0]), sizeof(buffer->getSize())) < 0)
    return (false);
  return (true);
}
