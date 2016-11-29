//
// Event.hpp for  in /home/landai_n/rendu/nibbler/libs/qtlib/includes
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Fri Apr  3 15:30:01 2015 Nathanael Landais
// Last update Fri Apr  3 15:30:01 2015 Nathanael Landais
//

#ifndef		EVENT_HPP
# define	EVENT_HPP

# include	<QKeyEvent>

class		KeyEvent : public QKeyEvent
{
public:
  KeyEvent(Type p_type, int p_key);
private:
};

#endif
