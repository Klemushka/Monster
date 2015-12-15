#include "../include/Game.h"

int main()
{
      Game* game = new Game();
      if(game->Init())
      {
       game->Loop();
      }
         return 0;
}
