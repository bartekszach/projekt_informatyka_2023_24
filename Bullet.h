#pragma once
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

class Bullet
{
private:
	sf::Sprite shape;
	//lepsza optymalizacjs jak jest wska�nik 


	sf::Vector2f direction;
	float movementSpeed;

public:
	
	Bullet(sf::Texture* texture, float posX, float posY, float dirX, float dirY, float movement_speed);
	virtual ~Bullet();

	//Accessor 
	const sf::FloatRect getBounds() const;

	void update();
	void render(sf::RenderTarget* target);
};
