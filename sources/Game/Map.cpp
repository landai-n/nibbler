#include	<cstdlib>
#include	<ctime>
#include	"Map.hpp"
#include	"Apple.hpp"
#include	"Lemon.hpp"
#include	"Wall.hpp"
#include	"Config.hpp"

Map::Map(size_t p_sizeX, size_t p_sizeY)
{
  srand(time(0));
  m_sizeX = p_sizeX;
  m_sizeY = p_sizeY;
  m_nbFood = 0;
}

Map::~Map()
{
  for (std::list<Entity *>::iterator it = m_entityList.begin(); it != m_entityList.end(); ++it)
    delete (*it);
}

void		Map::generateFood(const Entity *p_entity, Entity::e_type p_type)
{
  static size_t	prevX = 0;
  static size_t	prevY = 0;
  size_t	p_x;
  size_t	p_y;

  (void)p_entity;
  do
    {
      p_x = rand() % m_sizeX;
      p_y = rand() % m_sizeY;
    }
  while ((p_x == prevX && p_y == prevY)
	 || triggerEntities(p_x, p_y));

  if (p_type == Entity::APPLE)
    m_entityList.push_back(new Apple(p_x, p_y));
  else if (p_type == Entity::LEMON)
    m_entityList.push_back(new Lemon(p_x, p_y));
  prevX = p_x;
  prevY = p_y;
  m_nbFood++;
}

size_t		Map::getSizeX() const
{
  return (m_sizeX);
}

size_t		Map::getSizeY() const
{
  return (m_sizeY);
}

void		Map::eatFood()
{
  m_nbFood--;
}

int		Map::getNbFood() const
{
  return (m_nbFood);
}

void		Map::display(IWindow &p_window)
{
  size_t        partSizeX = p_window.getWidth() / getSizeX();
  size_t        partSizeY = p_window.getHeight() / getSizeY();

  for (std::list<Entity *>::iterator it = m_entityList.begin(); it != m_entityList.end(); it++)
    {
      p_window.drawSquare((*it)->getX() * partSizeX,
                          (*it)->getY() * partSizeY,
			  partSizeX,
                          (*it)->getColor());
    }
}

Entity		*Map::triggerEntities(const Entity &p_entity)
{
  for (std::list<Entity *>::iterator it = m_entityList.begin(); it != m_entityList.end(); ++it)
    {
      if (p_entity.getX() == (*it)->getX() && p_entity.getY() == (*it)->getY())
	return (*it);
    }
  return (NULL);
}

Entity		*Map::triggerEntities(int p_x, int p_y)
{
  for (std::list<Entity *>::iterator it = m_entityList.begin(); it != m_entityList.end(); ++it)
    {
      if (p_x == (*it)->getX() && p_y == (*it)->getY())
	return (*it);
    }
  return (NULL);
}

bool		Map::collid(const Entity &p_entity)
{
  for (std::list<Entity *>::iterator it = m_entityList.begin(); it != m_entityList.end(); ++it)
    {
      if (p_entity.getX() == (*it)->getX() && p_entity.getY() == (*it)->getY())
	if (p_entity.isSolid())
	  return (true);
    }
  return (false);
}

void		Map::deleteTriggeredEntity(const Entity &p_entity)
{
  Entity	*entity;

  for (std::list<Entity *>::iterator it = m_entityList.begin(); it != m_entityList.end(); ++it)
    if (p_entity.getX() == (*it)->getX() && p_entity.getY() == (*it)->getY())
      {
	entity = *it;
	m_entityList.erase(it);
	delete(entity);
	return;
      }
}

void		Map::generateBorders()
{
  size_t	size_holes = rand() % (MAX_SIZE_HOLE - MIN_SIZE_HOLE) + MIN_SIZE_HOLE;

  createWall(size_holes, m_sizeX, m_sizeY - 1);
}

void		Map::createWall(size_t p_size_holes, size_t p_max, int p_def)
{
  for (size_t i = 0; i < p_max; i++)
    {
      if (rand() % HOLE_RATE == HOLE_RATE - 1)
	i+= p_size_holes;
      else
	{
	  m_entityList.push_back(new Wall(i, 0));
	  m_entityList.push_back(new Wall(i, p_def));
	  m_entityList.push_back(new Wall(p_def, i));
	  m_entityList.push_back(new Wall(0, i));
	}
    }
}
