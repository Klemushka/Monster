#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

class Assets
{
      map<string,sf::Texture*>Textures;
public:
      Assets(void);
      sf::Texture& Get(const string& Key); //Получить текстуру со словесным ключем
      void Push(const string& Key, const string& FilePath); //Положить текстуру с ключем
      ~Assets(void);
};
