#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include<iostream>

class Menu {
private:
    sf::Texture texture;
    sf::Sprite sprite;

    sf::Texture texture2;
    sf::Sprite sprite2;

    sf::Texture texture3;
    sf::Sprite sprite3;

    sf::Texture texture4;
    sf::Sprite sprite4;
    sf::RenderWindow* window;
    sf::Font font;
    std::vector<std::vector<std::string>> options;

    int selectedOption;
    int selectedOption2;
    //wskaünik
    int Edwardo;
    int ifopen;

    void setupbg();
    void setupMenu();
    void handleKeyPress(sf::Keyboard::Key key);
    void handleOption(int optionIndex,int optionIndex2);
   

public:
    Menu(sf::RenderWindow* window);
    void update();
    void render();
    int ifopenmenu();
    void zamien(int a);
    void zamienEdwardo(int a);
};

