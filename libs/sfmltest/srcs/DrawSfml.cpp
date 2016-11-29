//
// DrawSfml.cpp for  in /home/couill_b/Dropbox/cpp_nibbler/libs/sfmltest
// 
// Made by Benjamin COUILLAUD
// Login   <couill_b@epitech.net>
// 
// Started on  Wed Apr  1 18:50:11 2015 Benjamin COUILLAUD
// Last update Sun Apr  5 21:15:52 2015 Benjamin COUILLAUD
//

#include		"DrawSfml.hpp"

DrawSfml::DrawSfml(size_t p_x, size_t p_y, const std::string &p_name)
{
  this->m_y = p_y;
  this->m_x = p_x;
  this->m_name = p_name;
  this->m_window = NULL;
  if (!m_font.loadFromFile("arial.ttf"))
    throw DrawSfml::Error("Failed to load font file");
}

DrawSfml::~DrawSfml()
{
  if (this->m_window != NULL)
    delete this->m_window;
}

void			DrawSfml::open()
{
  this->m_window = new sf::RenderWindow(sf::VideoMode(this->m_y, this->m_x), this->m_name);
}

void			DrawSfml::close()
{
  this->m_window->close();
}

void			DrawSfml::flush()
{
  this->m_window->display();
}

void			DrawSfml::clear()
{
  this->m_window->clear();
}

size_t			DrawSfml::getWidth() const
{
  sf::Vector2f		size(this->m_window->getSize());
  
  return (size.x);
}

size_t			DrawSfml::getHeight() const
{
  sf::Vector2f		size(this->m_window->getSize());
  
  return (size.y);
}

void			DrawSfml::drawSquare(size_t p_x, size_t p_y, size_t p_size \
					     , const Color &p_color)
{
  sf::RectangleShape	square(sf::Vector2f(p_size, p_size));

  square.setPosition(p_x, p_y);
  square.setFillColor(sf::Color(p_color.r, p_color.g, p_color.b));
  this->m_window->draw(square);
}

bool			DrawSfml::isOpen()
{
  return (m_window->isOpen());
}

bool			DrawSfml::isKeyPressed(Keyboard::Key p_key)
{
  static t_keyMap	keyTab[] =
    {
      { sf::Keyboard::Left, Keyboard::LEFT },
      { sf::Keyboard::Right, Keyboard::RIGHT },
      { sf::Keyboard::Up, Keyboard::UP },
      { sf::Keyboard::Down, Keyboard::DOWN },
      { sf::Keyboard::Escape, Keyboard::ESC },
      { sf::Keyboard::Return, Keyboard::ENTER },
      { sf::Keyboard::H, Keyboard::UNDEFINED }
    };

  for (int i = 0; keyTab[i].libKey != Keyboard::UNDEFINED; ++i)
    if (keyTab[i].libKey == p_key && sf::Keyboard::isKeyPressed(keyTab[i].sfmlKey))
      return (true);
  return (false);
}

void			DrawSfml::writeText(size_t p_x, size_t p_y, size_t p_size \
					    , const Color &p_color, const std::string &p_text)
{
  sf::Text		text;

  text.setFont(this->m_font);
  text.setString(p_text);
  text.setCharacterSize(p_size);
  text.setColor(sf::Color(p_color.r, p_color.g, p_color.b));
  text.setPosition(p_x, p_y);
  this->m_window->draw(text);
}

extern "C"
{

  IWindow		*createWindow(size_t p_width, size_t p_height, const std::string &p_name)
  {
    return (new DrawSfml(p_width, p_height, p_name));
  }

}
