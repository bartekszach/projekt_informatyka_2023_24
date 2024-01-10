#pragma once
#include"Bullet.h"

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;

	float attackCooldown;
	float attackCooldawnMax;

	int hp;
	int hpMax;


	//private functions
	void initVeriavles();
	void initTexture();
	void initSprite();

public:
	Player();
	virtual~Player();

	//Accessor
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getHpMax() const;

	//Modifires
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setHp(const int hp);
	void loseHp(const int value);

	//Functions
	void move(const float dirX, const float dirY);
	bool canAttack();

	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);
};

