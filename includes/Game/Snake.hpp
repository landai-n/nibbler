//
// Snake.hpp for  in /home/couill_b/Dropbox/yo
// 
// Made by Benjamin COUILLAUD
// Login   <couill_b@epitech.net>
// 
// Started on  Mon Mar 30 15:26:56 2015 Benjamin COUILLAUD
// Last update Mon Mar 30 16:57:07 2015 Benjamin COUILLAUD
//

#ifndef			_SNAKE_HPP_
# define		_SNAKE_HPP_

# include		<list>
# include		"Keyboard.hpp"
# include		"BodyPart.hpp"
# include		"Map.hpp"

class				IWindow;
class				Apple;

# define			SNAKE_BEGIN_SIZE	4
# define			SNAKE_PART_SIZE		10
class				Snake : public Entity
{
  Map				&m_map;
  std::list<BodyPart *>		m_body;
  BodyPart::e_direction		m_dir;

public:
  Snake(Map &p_map, size_t p_posX, size_t p_posY);
  ~Snake();
  void			move();
  void			changeDirection(BodyPart::e_direction);
  int			eat(Entity *);
  void			growUp();
  void			display(IWindow &p_window);
  bool			collid();
  bool			crossBorder();
  int			triggerEntities();

};

#endif
