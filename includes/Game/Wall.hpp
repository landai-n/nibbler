//
// Wall.hpp for  in /home/landai_n/rendu/nibbler
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sat Apr  4 14:39:54 2015 Nathanael Landais
// Last update Sat Apr  4 14:39:54 2015 Nathanael Landais
//

#ifndef		WALL_HPP
# define	WALL_HPP

# include	"Entity.hpp"

class		Wall : public Entity
{
public:
  Wall(size_t p_x, size_t p_y);
};

#endif
