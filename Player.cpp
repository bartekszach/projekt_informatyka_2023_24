#include "Player.h"


void Player::initVeriavles()
{
	movementSpeed = 3.f;
	attackCooldawnMax = 10.f;
	attackCooldown = attackCooldawnMax;

	//test
	hpMax = 100;
	hp = hpMax;
}

void Player::initTexture()
{
	//Load a texture from file 
	if (!texture.loadFromFile("Textures/statek.png"))
	{
		std::cout << "PLAYER:FAILED LOAD TEXTURE" << "\n";
	}

}

void Player::initSprite()
{
	//Set the texture to the sprite 
	this->sprite.setTexture(texture);

	//Resize this sprite
	this->sprite.scale(0.12f, 0.12f);

	this->sprite.setPosition(350.f, 500.f);
}

Player::Player()
{
	this->initVeriavles();

	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}

const sf::Vector2f& Player::getPos() const
{
	return sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return sprite.getGlobalBounds();
}

const int& Player::getHp() const
{
	return hp;
}

const int& Player::getHpMax() const
{
	return hpMax;
}

void Player::setPosition(const sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	sprite.setPosition(x, y);
}

void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	hp -= value;
	if (hp < 0)
		hp = 0;
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(movementSpeed * dirX, movementSpeed * dirY);
}

bool Player::canAttack()
{
	if (attackCooldown >= attackCooldawnMax) {
		attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Player::updateAttack()
{
	if (attackCooldown < attackCooldawnMax)
		attackCooldown += 0.5f;
}

//Functions
void Player::update()
{
	updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}