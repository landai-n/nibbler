//
// ByteBuffer.hpp for  in /home/landai_n/rendu/nibbler/includes/Server
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sun Apr  5 15:48:27 2015 Nathanael Landais
// Last update Sun Apr  5 15:48:27 2015 Nathanael Landais
//

#ifndef				BYTEBUFFER_HPP
# define			BYTEBUFFER_HPP

# include			<cstring>
# include			<stdint.h>
# include			<vector>

class				ByteBuffer
{
public:
  ByteBuffer(uint32_t p_opcode = 0);
  template <typename T>
  void           write(const T &p_value)
  {
    uint32_t      mask = 0xff;

    for (int i = 0; i < sizeof(T); i++)
      {
	m_storage->resize(m_storage->size() + sizeof(T));
	m_storage->assign(m_pos, (uint8_t)(p_value & 0xff));
	mask = mask << 1;
	m_pos++;
      }
  }

  template <typename T>
  void            replace(const T &p_value, uint32_t p_pos)
  {
    uint32_t      mask = 0xff;

    for (int i = 0; i < sizeof(T); i++)
      {
	m_storage->resize(m_storage->size() + sizeof(T));
	m_storage->assign(p_pos, (uint8_t)(p_value & 0xff));
	mask = mask << 1;
	p_pos++;
      }
  }
  template <typename T>
  T       read()
  {
    T     value;

    memcpy(&value, &m_storage[m_pos], sizeof(T));
    m_pos -= sizeof(T);
    return (value);
  }
  void				release();
  void				setStorage(std::vector<uint8_t>*);
  std::vector<uint8_t>		*getStorage() const;
  uint32_t			getSize() const;
private:
  std::vector<uint8_t>		*m_storage;
  uint32_t			m_opcode;
  uint32_t			m_pos;
};

#endif
