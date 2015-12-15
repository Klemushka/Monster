#include "../include/Game.h"

Game::Game(void): game_width(640), game_height(480) //Не пугайтесь, это всего лишь инициализация переменных
{

}

bool Game::Init()
{
     Title = "My Super Duper Omega Generator"; //Название создаваемого окна : )))))

     window = new sf::RenderWindow(sf::VideoMode(game_width, game_height), Title.c_str());
     if(!Load()) //Если произошла ошибка во время загрузки ресурсов игры нам необходимо незамедлительно завершить работу программы
     {
      return false;
     }
     else
     {
      //Log("Game resources load successfully"); <- Реализуйте сами : )
     }
     return true;
}

bool Game::Load()
{
     res = new Assets();
     res->Push("LAND","land.png");
     res->Push("GRASS","grass.png");
     res->Push("GRASSb","grass.png");
     res->Push("FLOWERS","flowers.png");

     map = new GameMap();
     mapGen.Generate(map->blocks, (int)(game_width/32), (int)(game_height/32));
     return true;
}
bool Game::UnLoad()
{
     delete map;
     delete res;
     //Log("Game resources unloaded");
     return true;
}

void Game::Loop()
{
     //Log("Running the game");
     while(window->isOpen())
     {
      sf::Event event;
      while(window->pollEvent(event))
      {
       if(event.type == sf::Event::Closed) /*Если поступило событие "Закрытие окна" надо завершить работу приложения, т.е. освободить ресурсы и закрыть программу*/
       {
        Shutdown();
        window->close();
        break;
       }
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) //Если нажали ESC - выход
      {
        Shutdown();
        window->close();
        break;
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
      {
       mapGen.Generate(map->blocks, (int)(game_width/32), (int)(game_height/32));
      }

      sf::Sprite some;
      window->clear();
      for(int i = 0; i < (int) map->blocks.size(); i++) //Рисуем карту
      {
       switch(map->blocks[i]->block_type)
       {
        case LAND:
        {
         some.setTexture(res->Get("LAND"));
         break;
        }
        case GRASS:
        {
         some.setTexture(res->Get("GRASS"));
         break;
        }
        case GRASSb:
        {
         some.setTexture(res->Get("GRASSb"));
         break;
        }
        case FLOWERS:
        {
         some.setTexture(res->Get("FLOWERS"));
         break;
        }
       }
       some.setPosition(map->blocks[i]->x*32, map->blocks[i]->y*32);
       window->draw(some);
      }
      window->display();
     }
}

void Game::Shutdown()
{
     UnLoad();
     //Log("The game shuts down\n");
}

Game::~Game(void)
{
}
