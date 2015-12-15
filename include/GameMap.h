#pragma once
#include <vector>
#include "Assets.h"
using namespace std;

struct Block
{
      int x,y;
      int block_type;
};

class GameMap
{
public:
      vector<Block*>blocks;
      GameMap();
      ~GameMap(void);
};
