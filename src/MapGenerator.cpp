#include "MapGenerator.h"
#include <iostream>

MapGenerator::MapGenerator(void)
{

}

int Random(int a, int b)
{
      int result = a + rand()%(b-a+1);
      return result;
}

void MapGenerator::Generate(vector<Block*>&blocks, const int map_width, const int map_height)
{
      /*Удаляем старую карту*/
      for(int i = 0; i < blocks.size(); i++)
      {
       delete blocks[i];
      }
      blocks.clear();
      h_min = 1 ;//+ Random(4,5);
      h_max = map_height; //- 1 - Random(2,3);
      int height = 0;//Random(h_min, h_max);


      /*for(int x = 0; x < map_width; x++)
       {

       y = map_height - 1;
       blocks.push_back(new Block());
       blocks[blocks.size() - 1]->block_type = GRASS;
       blocks[blocks.size() - 1]->x = x;
       blocks[blocks.size() - 1]->y = y;

       y = 0;
       blocks.push_back(new Block());
       blocks[blocks.size() - 1]->block_type = GRASS;
       blocks[blocks.size() - 1]->x = x;
       blocks[blocks.size() - 1]->y = y;
       }
       for(int y = 0; y < map_height; y++){

       x = map_width - 1;
       blocks.push_back(new Block());
       blocks[blocks.size() - 1]->block_type = GRASSb;
       blocks[blocks.size() - 1]->x = x;
       blocks[blocks.size() - 1]->y = y;

       x = 0;
       blocks.push_back(new Block());
       blocks[blocks.size() - 1]->block_type = GRASS;
       blocks[blocks.size() - 1]->x = x;
       blocks[blocks.size() - 1]->y = y;
      }
      /*for(int y = 0; y < map_height; y++)
      {
       int x = 0;
       blocks.push_back(new Block());
       blocks[blocks.size() - 1]->block_type = GRASS;
       blocks[blocks.size() - 1]->x = x;
       blocks[blocks.size() - 1]->y = y;
      }
      /*for(int x = 0; x < map_width; x++)
      {
       int y = 0;
       blocks.push_back(new Block());
       blocks[blocks.size() - 1]->block_type = GRASS;
       blocks[blocks.size() - 1]->x = x;
       blocks[blocks.size() - 1]->y = y;
       /*if(Random(-3,3) == 0)
       {
        blocks.push_back(new Block());
        blocks[blocks.size() - 1]->block_type = FLOWERS;
        blocks[blocks.size() - 1]->x = x;
        blocks[blocks.size() - 1]->y = height - 1;
       }

      /* for(int y = height+1; y < map_height; y++)
       {
        std::cout<<Random(-1,1)<<endl;
        blocks.push_back(new Block());
        blocks[blocks.size() - 1]->block_type = LAND;
        blocks[blocks.size() - 1]->x = x;
        blocks[blocks.size() - 1]->y = y;
       }*/

       height += Random(-1,1);
       if(height > h_max)
       {
        height -= 2;
       }
       else if(height < h_min)
       {
        height += 2;
       }
      }


MapGenerator::~MapGenerator(void)
{
}
