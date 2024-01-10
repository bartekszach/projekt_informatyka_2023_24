#include "Bullet.h"

Bullet::Bullet(sf::Texture* texture, float posX, float posY, float dirX, float dirY, float movement_speed)
{
	shape.setTexture(*texture);
	shape.setScale(0.2f, 0.2f);
	shape.setPosition(posX, posY);
	direction.x = dirX;
	direction.y = dirY;
	movementSpeed = movement_speed;
}

Bullet::~Bullet()
{
}

const sf::FloatRect Bullet::getBounds() const
{
	return shape.getGlobalBounds();
}

void Bullet::update()
{
	// Ruch
	shape.move(movementSpeed * direction);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(shape);
}
