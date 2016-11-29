//
// Window.cpp for nibbler in /home/landai_n/rendu/nibbler/libs/qtlib/srcs
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Wed Apr  1 15:09:18 2015 Nathanael Landais
// Last update Wed Apr  1 15:09:18 2015 Nathanael Landais
//

#include	<QApplication>
#include	<QWidget>
#include	<QGraphicsScene>
#include	<QGraphicsView>
#include	<QGraphicsItem>
#include	"Window.hpp"
#include	"Event.hpp"
#include	"GraphicsView.hpp"
#include	"Color.hpp"

Window::Window(size_t p_width, size_t p_height, const std::string &p_name)
{
  int	paramNb = 1;
  char	*param[] = { (char *)p_name.c_str() };

  m_app = new QApplication(paramNb, param);
  m_scene = new QGraphicsScene(0, 0, p_width, p_height);
  m_view = new GraphicsView(m_scene);
  m_run = false;

  m_view->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
  open();
}

Window::~Window()
{
  delete (m_app);
  delete (m_scene);
  delete (m_view);
}

void		Window::open()
{
  m_view->show();
  m_app->processEvents();
  m_run = true;
}

void		Window::close()
{
  m_run = false;
}

bool		Window::isOpen()
{
  if (m_run)
    m_view->cleanKeys();
  while (this->pollEvents());
  return (m_run);
}

bool		Window::isKeyPressed(Keyboard::Key p_key)
{
  if (m_run)
    return (m_view->isPressed(p_key));
  return (false);
}

bool		Window::pollEvents()
{
  if (m_run)
    if (m_app->hasPendingEvents())
      {
	m_app->processEvents();
	return (true);
      }
  return (false);
}

void		Window::flush()
{
}

void		Window::clear()
{
  for (std::list<QGraphicsItem *>::iterator it = m_itemList.begin(); it != m_itemList.end(); ++it)
    m_scene->removeItem((QGraphicsItem *)(*it));
  m_itemList.clear();
}

size_t		Window::getWidth() const
{
  return (m_view->width());
}

size_t		Window::getHeight() const
{
  return (m_view->height());
}

void		Window::drawSquare(size_t p_x, size_t p_y, size_t p_size, const Color &p_color)
{
  if (!m_run)
    return;
  QBrush	brush(QColor(p_color.r, p_color.g, p_color.b, 255));

  m_itemList.push_back((QGraphicsItem *)m_scene->addRect(
					QRectF(p_x, p_y, p_size, p_size),
					QPen(),
					brush
					));
}

void		Window::writeText(size_t p_x, size_t p_y, size_t p_size,
				  const Color &p_color, const std::string &p_str)
{
  QGraphicsTextItem *text = m_scene->addText(QString(p_str.c_str()),
							 QFont("Arial", p_size));

  text->setPos(p_x, p_y);
  text->setDefaultTextColor(QColor(p_color.r, p_color.g, p_color.b, 255));
  m_itemList.push_back((QGraphicsItem *)text);
}

extern "C"
{

  IWindow		*createWindow(size_t p_width, size_t p_height, const std::string &p_name)
  {
    return (new Window(p_width, p_height, p_name));
  }

}
