#include "Menu.h"

//ifopenmenu !!!!!!!0 MENU ZWYKLE |1 ESC |2 F1
Menu::Menu(sf::RenderWindow* window) : window(window), selectedOption(0),selectedOption2(0),Edwardo(0) ,ifopen(0){
    if (!font.loadFromFile("Fonts/pricedow.ttf"))
    {
        std::cout << "Blad w czcionce:Menu" << "\n";
    }
    setupbg();
    setupMenu();
}

//tla
void Menu::setupbg()
{
    //sprite1
   if (!texture.loadFromFile("Textures/tlomenu.png"))
    {
    std::cout << "Nie wczytano tekstur1y :Menu" << "\n";
    }
   sprite.setTexture(texture);
   sprite.setScale(0.6f, 0.6f);

   //sprite 2
   if (!texture2.loadFromFile("Textures/tlomenu2.png"))
   {
       std::cout << "Nie wczytano tekstury2 :Menu" << "\n";
   }
   sprite2.setTexture(texture2);
   sprite2.setScale(1.f, 1.f);

   //sprite 3
   if (!texture3.loadFromFile("Textures/tlomenu3.png"))
   {
       std::cout << "Nie wczytano tekstury3 :Menu" << "\n";
   }
   sprite3.setTexture(texture3);
   sprite3.setScale(1.f, 1.f);

   //sprite 4
   if (!texture4.loadFromFile("Textures/tlomenu4.png"))
   {
       std::cout << "Nie wczytano tekstury4 :Menu" << "\n";
   }
   sprite4.setTexture(texture4);
   sprite4.setScale(0.45f, 0.45f);
}

//tutaj mam to co ma wypisac
void Menu::setupMenu() { //Main     //START1    //START 2     //AUTOR   //ESC MENU         //F1 MENU
    options.push_back({ "START", "NEW GAME",    "EASY",         ""     ,"CONTINUE",            "BACK"});
    options.push_back({ "SCORE BOARD", "CONTINUE", "MEDIUM", "BACK"    ,"SAVE & BACK TO MENU",        ""});
    options.push_back({ "AUTOR",      "",        "HARD",       ""      ,"",                ""});
    options.push_back({ "EXIT",     "BACK",      "BACK",       ""      , "CLOSE GAME"      ,            ""});
}

//tutaj mam to bedzie updatowane w windows Mengaer
void Menu::update() {
    sf::Event event;
    while (window->pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            handleKeyPress(event.key.code);
            break;
        default:
            break;
        }
    }
}
//do przycikow
void Menu::handleKeyPress(sf::Keyboard::Key key) {
    if (Edwardo != 3&&(ifopen==0||ifopen==1))
    {
        if (key == sf::Keyboard::Up) {
            selectedOption = (selectedOption - 1 + options.size()) % options.size();
        }
        if (key == sf::Keyboard::Down) {
            selectedOption = (selectedOption + 1) % options.size();
        }
    }

     if (key == sf::Keyboard::Enter) {
       // std::cout << "Wybrano: " << options[selectedOption][selectedOption2] << std::endl;
       
        handleOption(selectedOption,selectedOption2);
    }
}

void Menu::handleOption(int optionIndex,int optionIndex2) {
    //Start
    if (ifopen == 0) {
        if (optionIndex == 0 && optionIndex2 == 0) {
            Edwardo = 1;
            std::cout << "Start";
            selectedOption2 = 1;
            selectedOption = 0;

        }
        //NEW GAME/LOAD GAME BACK
        if (optionIndex == 0 && optionIndex2 == 1)
        {
            std::cout << "NEW GAME";
            Edwardo = 2;
            selectedOption2 = 2;
            selectedOption = 0;
        }
        //dziala
        if (optionIndex == 1 && optionIndex2 == 1)
        {
            std::cout << "CONTINUE";
            ifopen = -1;
            Edwardo = 0;
            selectedOption2 = 0;
            selectedOption = 0;

        }

        if (optionIndex == 0 && optionIndex2 == 2)
        {
            std::cout << "EASY";
            //ifopen = false;
            //cos z tym Edwardo przekminic
            //Edwardo =0 ;
            //selectedOption2 = 0;
            //selectedOption = 0;

        }
        if (optionIndex == 1 && optionIndex2 == 2)
        {
            std::cout << "MEDIUM";
            //ifopen = false;
            //cos z tym Edwardo przekminic
            //Edwardo = 0;
            //selectedOption2 = 0;
            //selectedOption = 0;

        }

        if (optionIndex == 2 && optionIndex2 == 2)
        {
            std::cout << "HARD";
            //ifopen = false;
            //cos z tym Edwardo przekminic
            //Edwardo = 0;
            //selectedOption2 = 0;
            //selectedOption = 0;

        }

        //Autor
        if (optionIndex == 2 && optionIndex2 == 0) {
            Edwardo = 3;
            std::cout << "AUTOR";
            selectedOption2 = 3;
            selectedOption = 1;
        }
        //exit
        if (optionIndex == 3 && optionIndex2 == 0) {
            std::cout << "EXIT";

            window->close();
        }
        //BACK OGOLNY
        if ((optionIndex == 3 && optionIndex2 == 1)
            || (optionIndex == 1 && optionIndex2 == 3)) {
            std::cout << "BACK";
            Edwardo = 0;
            selectedOption2 = 0;
            selectedOption = 0;

        }
        //BACK START2
        if (optionIndex == 3 && optionIndex2 == 2)
        {
            std::cout << "BACK 2";
            Edwardo = 1;
            selectedOption2 = 1;
            selectedOption = 0;

        }
    }

    //ESC MENU
    if (ifopen == 1) {

        //std::cout <<"WSP :" << optionIndex << ", " << optionIndex2<<"\n";
        if (optionIndex == 0&& optionIndex2 == 0)
        {
            std::cout << "CONTINUE";
            ifopen = -1;
        }
        if (optionIndex == 1 && optionIndex2 == 0)
        {
            std::cout << "BACK TO MENU";
            ifopen = 0;
            Edwardo = 0;
            selectedOption2 = 0;
            selectedOption = 0;
        }
        if (optionIndex == 3 && optionIndex2 == 0)
        {
            window->close();
        }


    }

    //F1 MENU
    //dziala ale zmienic jak starczy czasu
    if (ifopen == 2) {
        std::cout << "Menu F1, ";
       // std::cout << optionIndex << " " << optionIndex2;
        if (optionIndex ==0&& optionIndex2 ==0)
        {
            std::cout << "BACK";
            ifopen = -1;
        }

    }
}

void Menu::render() {
    window->clear();
    //rysowanie tla
    if (Edwardo == 0 &&ifopen==0)
    {
        window->draw(sprite);
    }
    if (Edwardo == 1)
    {
        window->draw(sprite2);
    }
    if (Edwardo == 2)
    {
        window->draw(sprite3);
    }
    if (Edwardo == 3)
    {
        window->draw(sprite4);
    }
    // Rysuj opcje menu

    for (size_t i = 0; i < options.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(options[i][Edwardo]);
        text.setCharacterSize(70);
        if (Edwardo != 3)
            text.setPosition(100, 100 + i * 100);
        if(Edwardo==3)
            text.setPosition(180, 100 + i * 100);
        if (ifopen == 1)
            text.setPosition(50, 100 + i * 100);


        // Podœwietl aktualnie zaznaczon¹ opcjê
        if (i == selectedOption) {
            text.setFillColor(sf::Color::Black);
            text.setOutlineThickness(5.f);
            text.setOutlineColor(sf::Color::Red);

        }
        else {
            text.setFillColor(sf::Color::White);
            text.setOutlineThickness(3.f);
            text.setOutlineColor(sf::Color::Black);
        }

        window->draw(text);
    }
   
    window->display();
}

int Menu::ifopenmenu()
{
    return ifopen;
}

void Menu::zamien(int a)
{

    if (a == 0) {
        ifopen = 0;
    }
    if (a == 1) {
        ifopen = 1;
    }
    if (a == 2) {
        ifopen = 2;
    }
}

void Menu::zamienEdwardo(int a)
{
    if (ifopen==1) {
        Edwardo = 4;
    }
    if (ifopen==2) {
        Edwardo = 5;
    }
}
