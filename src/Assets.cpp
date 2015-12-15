#include "Assets.h"

Assets::Assets(void)
{
}

sf::Texture& Assets::Get(const string& Key)
{
      return *Textures[Key];
}

void Assets::Push(const string& Key, const string& FilePath)
{
      sf::Texture* some = new sf::Texture; //Создать в программной куче место под текстуру
      some->loadFromFile(FilePath); //Загрузить текстуру (хочу заметить, что в FilePath вместо \ надо писать \\, т.к. \ - это специальный символ С\С++
      Textures[Key] = some; //Поместить указатель на текстуру с "пометкой" Key
}

Assets::~Assets(void)
{

}
