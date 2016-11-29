//
// Color.hpp for  in /home/landai_n/rendu/nibbler
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sat Apr  4 13:34:30 2015 Nathanael Landais
// Last update Sat Apr  4 13:34:30 2015 Nathanael Landais
//

#ifndef		COLOR_HPP
# define	COLOR_HPP

class		Color
{
public:
  Color(unsigned char p_r, unsigned char p_g, unsigned char p_b) : r(p_r), g(p_g), b(p_b) { }
  unsigned char r;
  unsigned char g;
  unsigned char b;
};

#endif
