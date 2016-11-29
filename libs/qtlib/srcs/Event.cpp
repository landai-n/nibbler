//
// Event.cpp for  in /home/landai_n/rendu/nibbler/libs/qtlib/srcs
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Fri Apr  3 15:32:15 2015 Nathanael Landais
// Last update Fri Apr  3 15:32:15 2015 Nathanael Landais
//

#include	<Qt>
#include	"Event.hpp"

KeyEvent::KeyEvent(Type p_type, int p_key) : QKeyEvent(p_type, p_key, Qt::NoModifier)
{

}
