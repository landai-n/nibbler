//
// ISprite.hpp for  in /home/couill_b/Dropbox/yo
// 
// Made by Benjamin COUILLAUD
// Login   <couill_b@epitech.net>
// 
// Started on  Mon Mar 30 17:21:39 2015 Benjamin COUILLAUD
// Last update Mon Mar 30 17:26:35 2015 Benjamin COUILLAUD
//

#ifndef			_ISPRITE_HPP_
# define		_ISPRITE_HPP_

# include		<string>

class			ISprite
{
public:
  virtual ~Sprite() = 0;
  virtual void		loadTexture(const std::string &path) = 0;
  virtual void		putTexture() = 0;
};

#endif
