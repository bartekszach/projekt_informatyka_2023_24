#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy
{
private:
	unsigned pointCount;
	sf::Texture texture;
	sf::Sprite shape;
	float speed;
	int hp;
	int hpHax;
	int damage;
	int points;

	void initVeriables();
	void initShape();

public:
	Enemy(float posX, float posY);
	virtual ~Enemy();
	//Accessors
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;

	//Functions
	void update();
	void render(sf::RenderTarget* target);


};


