//
// Entity.hpp for  in /home/couill_b/Dropbox/yo
// 
// Made by Benjamin COUILLAUD
// Login   <couill_b@epitech.net>
// 
// Started on  Mon Mar 30 15:27:15 2015 Benjamin COUILLAUD
// Last update Mon Mar 30 16:55:29 2015 Benjamin COUILLAUD
//

#ifndef		_ENTITY_HPP_
# define	_ENTITY_HPP_

# include	<string>
# include	"Color.hpp"

class		Entity
{
public:
  enum		e_type
    {
      SNAKE,
      APPLE,
      LEMON,
      WALL
    };
protected:
  int		m_x;
  int		m_y;
  e_type	m_type;
  Color		m_color;
  bool		m_solid;
  int		m_value;

public:
  Entity(int p_x, int p_y, e_type p_type, Color p_color, bool p_solid, int m_value = 0);
  ~Entity();
  int		getX() const;
  int		getY() const;
  e_type	getType() const;
  bool		isSolid() const;
  const Color	&getColor() const;
  int		getValue() const;
};

#endif
