//
// Event.hpp for  in /home/couill_b/Dropbox/yo
// 
// Made by Benjamin COUILLAUD
// Login   <couill_b@epitech.net>
// 
// Started on  Mon Mar 30 17:28:13 2015 Benjamin COUILLAUD
// Last update Mon Mar 30 17:36:00 2015 Benjamin COUILLAUD
//

#ifndef			_EVENT_HPP_
# define		_EVENT_HPP_

class			Event
{
public:
  Event();
  ~Event();
  void			getKey();
  void			useKey(); // ici on fait un tableau qui compare la clé qu'on a avec la clé de notre putaing ( ou pinaise selon affinité) de lib !!!!!!!!


private:
  size_t		p_key;
};

#endif
