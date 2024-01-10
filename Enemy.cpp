#include "Enemy.h"

void Enemy::initVeriables()
{
	pointCount = rand() % 8 + 5; // Min 3, max 12
	speed = static_cast<float>(pointCount / 4);
	hpHax = static_cast<int>(pointCount);
	hp = hpHax;
	damage = pointCount;
	points = pointCount;
}

void Enemy::initShape()
{
	texture.loadFromFile("Textures/meteoryt.png");
	shape.setTexture(texture);
	shape.setScale(1.f / pointCount, 1.f / pointCount);

	/*texture.loadFromFile("Textures/meteoryt.png");
	shape.setTexture(texture);
	shape.setOrigin(shape.getGlobalBounds().width / 2.f, shape.getGlobalBounds().height / 2.f);
	shape.setScale(1.f / pointCount, 1.f / pointCount);*/
}

Enemy::Enemy(float posX, float posY)
{
	initVeriables();
	initShape();
	shape.setPosition(posX, posY);
}

Enemy::~Enemy()
{
}

// Accersor 
// Zwraca kopie
const sf::FloatRect Enemy::getBounds() const
{
	return shape.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return points;
}

const int& Enemy::getDamage() const
{
	return damage;
}

// Functions
void Enemy::update()
{
	shape.move(0.f, speed);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(shape);
}