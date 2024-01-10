#include "Game.h"
#include <ctime>
#include "Menu.h"
#include "WindowsMenager.h"

int main() {

	srand(static_cast<unsigned>(time(0)));

	
	WindowsMenager menager;

	menager.run();
	

	return 0;
}