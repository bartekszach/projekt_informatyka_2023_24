#include "WindowsMenager.h"

void WindowsMenager::initWindow1()
{
    window1 = new sf::RenderWindow(sf::VideoMode(800, 600), "Window", sf::Style::Close | sf::Style::Titlebar);
    window1->setFramerateLimit(144);
}

WindowsMenager::WindowsMenager()
{
    initWindow1();
}

WindowsMenager::~WindowsMenager()
{
    delete window1;
}

void WindowsMenager::run()
{
    while (window1->isOpen())
    {
        updatePollEvents();
        render();
    }
}

void WindowsMenager::updatePollEvents()
{
    //GAMWE STATUS !!!!!! |0 RUN  1 ESCAPE 2 F1 !!!!!!!!!
   // ifopenmenu !!!!!!! -1 POZA MENU  |0 MENU ZWYKLE | 1 ESC | 2 F1
    Game gra(window1);
    Menu menu(window1);

    while (window1->isOpen())
    {
        if (menu.ifopenmenu() == 0)
        {
            menu.update();
            menu.render();
            gra.zamien(0); 
        }
        if (menu.ifopenmenu() == -1&&(gra.gameStatus()==0))
        {
            gra.update();
            gra.render();
          //  std::cout << "Gram";
        }
        if (menu.ifopenmenu() == -1 &&( gra.gameStatus() == 1))
        {
            menu.update();
            menu.render();
            menu.zamien(1);
            gra.zamien(0);
          //  std::cout << "ESC";
        }
        if (menu.ifopenmenu() ==-1 && (gra.gameStatus() == 2))
        {
            menu.update();
            menu.render();
            menu.zamien(2);
            gra.zamien(0);
           // std::cout << "F1";
        }
        if (menu.ifopenmenu() == 1 && (gra.gameStatus() == 0))
        {
            menu.update();
            menu.render();
            menu.zamienEdwardo(menu.ifopenmenu());
     
        }
        if (menu.ifopenmenu() == 2 && (gra.gameStatus() == 0))
        {
            menu.update();
            menu.render();
            menu.zamienEdwardo(menu.ifopenmenu());
       
        }




    }
}

void WindowsMenager::render()
{
    window1->clear();
    window1->display();
}

