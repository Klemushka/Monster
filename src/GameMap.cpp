#include "../include/GameMap.h"

GameMap::GameMap()
{

}

GameMap::~GameMap(void)
{
      for(int i = 0; i < blocks.size(); i++)
      {
       delete blocks[i];
      }
}
