#pragma once
#include "block_types.h"
#include "GameMap.h"
#include <time.h>

class MapGenerator
{
      int h_min; //нижняя граница
      int h_max; //верхняя граница
public:
      MapGenerator(void);
      void Generate(vector<Block*>&blocks, const int map_width, const int map_height);
      ~MapGenerator(void);
};
