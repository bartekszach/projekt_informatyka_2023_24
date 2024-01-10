#pragma once
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <sstream>
#include<string>

class Game
{
private:
	//GameStatus;
	int gameSatus1;
	//Window
	sf::RenderWindow* window; 
	//Resources
	sf::Texture* textures;
	std::vector<Bullet*> bullets;
	

	//Gui
	sf::Font font;
	sf::Text pointText;

	//koniec gry
	sf::Text GameOver;
	sf::RectangleShape GameOverShape;

	//World
	sf::Texture bgtexture;
	sf::Sprite wolrdBackground;

	//Systems
	int  points;

	//Player 
	Player* player;

	//Player GUI
	sf::RectangleShape platerHpBar;
	sf::RectangleShape playerHpBarBack;

	//Enemies 
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

	//Private Functions
	void setTextures();
	void setGUI();
	void setBackgorund();
	void setSystems();

	void setPlayer();
	void setEnemies();
public:
	Game(sf::RenderWindow *okno);
	virtual ~Game();

	//Functions
	// 
	//UPDATE
	void update();
	void updateGameStatus();
	void updateInput();
	void updateCollision();
	void updateBullests();
	void updateEnemies();
	void upadateCombat();
	void updateGUI();
	void updateWorld();
	
	void render();
	void renderWorld();
	void renderGUI();
	
	int gameStatus();
	void zamien(int a);
};


