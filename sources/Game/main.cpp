#include	"Game.hpp"

int		main(int argc, char **argv)
{
  Game		nibbler;

  if (nibbler.init(argc, argv) == false)
    return (-1);
  nibbler.run();
  return (0);
}
