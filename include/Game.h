#pragma once
#include "Assets.h"
#include "block_types.h"
#include "GameMap.h"
#include "MapGenerator.h"
#include <string>
#include <math.h>
#include <vector>
using namespace std;

class Game
{
  string Title;
  sf::RenderWindow *window;
  Assets *res; //Здесь будем хранить ресурсы игрули
  GameMap *map;
  MapGenerator mapGen;
  const int game_width;
  const int game_height;
public:
  Game(void); //Конструктор
  bool Init(); //Инициализация окон и прочих систем (файл будет дополняться)
  bool Load(); //Загрузка ресурсов игры
  bool UnLoad(); //Удаление ресурсов игры из оперативной памяти
  void Loop(); //Главный цикл игры
  void Shutdown(); //Завершение работы игры
  ~Game(void); //Деструктор
};
