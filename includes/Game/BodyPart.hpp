//
// BodyPart.hpp for  in /home/couill_b/Dropbox/yo
// 
// Made by Benjamin COUILLAUD
// Login   <couill_b@epitech.net>
// 
// Started on  Mon Mar 30 16:00:48 2015 Benjamin COUILLAUD
// Last update Mon Mar 30 16:53:59 2015 Benjamin COUILLAUD
//

#ifndef			_BODYPART_HPP_
# define		_BODYPART_HPP_

# include		"Entity.hpp"

class			BodyPart : public Entity
{
public:
  enum                  e_direction
   {
     LEFT,
     TOP,
     RIGHT,
     BOTTOM,
     MAX
   };
  BodyPart(size_t p_x, size_t p_y);
  ~BodyPart();
  void			move(BodyPart::e_direction, size_t, size_t);

private:
};

#endif
