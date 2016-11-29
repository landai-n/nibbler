//
// Map.hpp for  in /home/couill_b/Dropbox/yo
// 
// Made by Benjamin COUILLAUD
// Login   <couill_b@epitech.net>
// 
// Started on  Mon Mar 30 16:20:22 2015 Benjamin COUILLAUD
// Last update Mon Mar 30 16:43:01 2015 Benjamin COUILLAUD
//

#ifndef			_MAP_HPP_
# define		_MAP_HPP_

# include		<list>
# include		"Entity.hpp"
# include		"IWindow.hpp"

class			Map
{
public:
  Map(size_t p_sizeX, size_t p_sizeY);
  ~Map();
  void					generateFood(const Entity *, Entity::e_type);
  void					eatFood();
  int					getNbFood() const;
  size_t				getSizeX() const;
  size_t				getSizeY() const;
  void					display(IWindow &p_window);
  Entity				*triggerEntities(const Entity &p_entity);
  Entity				*triggerEntities(int p_x, int p_y);
  bool					collid(const Entity &p_entity);
  void					deleteTriggeredEntity(const Entity &p_entity);
  void					generateBorders();
  void					createWall(size_t, size_t, int);

private:
  std::list<Entity *>	m_entityList;
  size_t		m_sizeX;
  size_t		m_sizeY;
  int			m_nbFood;

};

#endif
