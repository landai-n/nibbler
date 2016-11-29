//
// ByteBuffer.cpp for  in /home/landai_n/rendu/nibbler/sources/Server
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sun Apr  5 16:00:59 2015 Nathanael Landais
// Last update Sun Apr  5 16:00:59 2015 Nathanael Landais
//

#include	"ByteBuffer.hpp"

ByteBuffer::ByteBuffer(uint32_t p_opcode)
{
  m_storage = new std::vector<uint8_t>();
  m_pos = 0;
  if (p_opcode != 0)
    {
      write<uint32_t>(0);
      write<uint32_t>(p_opcode);
    }
  m_opcode = -1;
}

void		ByteBuffer::setStorage(std::vector<uint8_t> *p_storage)
{
  delete (m_storage);
  m_storage = p_storage;
}

std::vector<uint8_t>	*ByteBuffer::getStorage() const
{
  return (m_storage);
}

uint32_t		ByteBuffer::getSize() const
{
  return (m_storage->size());
}

void		ByteBuffer::release()
{
  replace(m_storage->size(), 0);
}
