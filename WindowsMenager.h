#pragma once
#include "Game.h"
#include "Menu.h"
class WindowsMenager
{
private:
	
	sf::RenderWindow* window1;
	void initWindow1();


public:
	WindowsMenager();
	~WindowsMenager();

	void run();
	void updatePollEvents();

	void render();


};

