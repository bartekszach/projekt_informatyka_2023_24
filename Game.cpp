#include "Game.h"

//GAMWE STATUS !!!!!!0 RUN  1 ESCAPE 2 F1 !!!!!!!!!
// Cons/Des
Game::Game(sf::RenderWindow* okno) : window(okno),gameSatus1(0)
{
	setTextures();
	setGUI();
	setBackgorund();
	setSystems();
	setPlayer();
	setEnemies();
}

Game::~Game()
{
	delete window;
	delete player;

	delete textures;

	// delete Bulletes
	for (auto* i : bullets)
	{
		delete i;
	}
	// delete Enemies
	for (auto* i : enemies)
	{
		delete i;
	}
}

// Private Functions

void Game::setTextures()
{
	textures = new sf::Texture();
	textures->loadFromFile("Textures/pocisk.png");
}

void Game::setGUI()
{
	// Load font
	if (!font.loadFromFile("Fonts/pricedow.ttf"))
		std::cout << "GAME:Failed to Load font" << "\n";

	// Init point text 
	pointText.setPosition(575.f, 11.f);
	pointText.setFont(font);
	pointText.setCharacterSize(50);
	pointText.setFillColor(sf::Color::Black);
	pointText.setOutlineColor(sf::Color::Red);
	pointText.setOutlineThickness(3.5f);

	// Game Over
	GameOver.setFont(font);
	GameOver.setCharacterSize(80);
	GameOver.setOutlineColor(sf::Color::Black);
	GameOver.setOutlineThickness(5.f);
	GameOver.setFillColor(sf::Color::Red);
	GameOver.setString("Game Over");
	GameOver.setRotation(30);
	GameOver.setPosition(
		window->getSize().x / 2.f - GameOver.getGlobalBounds().width / 2.75f,
		window->getSize().y / 2 - GameOver.getGlobalBounds().height / 2.f);
	// Init game over shape
	GameOverShape.setSize(sf::Vector2f(800.f, 600.f));
	// Pobawic siê tym 
	GameOverShape.setFillColor(sf::Color(0, 0, 0));

	// Init player Gui
	platerHpBar.setSize(sf::Vector2f(300.f, 25.f));
	platerHpBar.setFillColor(sf::Color::Red);
	platerHpBar.setPosition(sf::Vector2f(20.f, 20.f));
	platerHpBar.setOutlineColor(sf::Color::Black);
	platerHpBar.setOutlineThickness(3.f);

	playerHpBarBack = platerHpBar;
	playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
}

void Game::setBackgorund()
{
	if (!bgtexture.loadFromFile("Textures/tlo.png"))
	{
		std::cout << "GAME:Failed to load bg" << "\n";
	}

	wolrdBackground.setTexture(bgtexture);
	wolrdBackground.setScale(0.55f, 0.55f);
	wolrdBackground.setPosition(1.f, 1.f);
}

void Game::setSystems()
{
	points = 0;
}

void Game::setPlayer()
{
	player = new Player();
}

void Game::setEnemies()
{
	spawnTimerMax = 50.f;
	spawnTimer = spawnTimerMax;
}

// Functions

// UPDATE
void Game::update()
{
	updateGameStatus();

	updateInput();

	player->update();

	updateCollision();

	updateBullests();

	updateEnemies();

	upadateCombat();

	updateGUI();

	updateWorld();
}

void Game::updateGameStatus()
{
	//GAMWE STATUS !!!!!!0 RUN  1 ESCAPE 2 F1 !!!!!!!!!
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		gameSatus1 = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
	{
		gameSatus1 = 2;
	}
}

void Game::updateInput()
{
	// Move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		player->move(0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		player->move(0.f, -1.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && player->canAttack())
	{
		// Teraz jest lepiej
		bullets.push_back(new Bullet(
			textures, player->getPos().x + player->getBounds().width / 1.5f,
			player->getPos().y, 0.f, -1.f, 5.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::V) && player->canAttack())
	{
		// Teraz jest lepiej
		bullets.push_back(new Bullet(
			textures, player->getPos().x + 10.f,
			player->getPos().y, 0.f, -1.f, 5.f));
	}
}

void Game::updateCollision()
{
	// Left collison
	if (player->getBounds().left < -20.f)
	{
		player->setPosition(-20.f, player->getBounds().top);
	}
	// Right collison
	else if (player->getBounds().left + player->getBounds().width >= (window->getSize().x + 20.f))
	{
		player->setPosition(window->getSize().x - player->getBounds().width + 20.f, player->getBounds().top);
	}
	// Top collison
	if (player->getBounds().top < 0.f)
	{
		player->setPosition(player->getBounds().left, 0.f);
	}
	// Bottom collison
	else if (player->getBounds().top + player->getBounds().height >= (window->getSize().y + 0.f))
	{
		player->setPosition(player->getBounds().left, window->getSize().y - player->getBounds().height + 0.f);
	}
}

void Game::updateBullests()
{
	int counter = 0;
	for (auto* bullet : bullets)
	{
		bullet->update();

		// Bullet culling 
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			// Delete bullet
			delete bullets.at(counter);
			bullets.erase(bullets.begin() + counter);

			// Debugging !!!!usunac
			std::cout << bullets.size() << "\n";
		}
		++counter;
	}
}

void Game::updateEnemies()
{
	// Spawning
	spawnTimer += 0.5f;
	if (spawnTimer >= spawnTimerMax)
	{
		// Problem z teksturami //sloved :D
		enemies.push_back(new Enemy(rand() % window->getSize().x, -100.f));
		spawnTimer = 0.f;
	}

	// Update
	int counter = 0;
	for (auto* enemy : enemies)
	{
		enemy->update();

		// Enemy culling 
		if (enemy->getBounds().top > window->getSize().y)
		{
			// Delete enemies
			// Najpierw usuwam z pamiêci potem z wektora aby nie mieæ strat pamiêci
			delete enemies.at(counter);
			enemies.erase(enemies.begin() + counter);

			// Debugging  !!!usunac
			std::cout << bullets.size() << "\n";
		}
		// Enemy player collsion
		else if (enemy->getBounds().intersects(player->getBounds()))
		{
			player->loseHp(enemies.at(counter)->getDamage());
			delete enemies.at(counter);
			enemies.erase(enemies.begin() + counter);
		}

		++counter;
	}
}

void Game::upadateCombat()
{
	for (int i = 0; i < enemies.size(); ++i)
	{
		// Skorzysta³em z poradnika na yt
		// Dodac bool bo siê bêdzie crashowaæ
		bool enemy_deleted = false;

		for (size_t j = 0; j < bullets.size() && enemy_deleted == false; j++)
		{
			if (enemies[i]->getBounds().intersects(bullets[j]->getBounds()))
			{
				points += enemies[i]->getPoints();

				delete enemies[i];
				enemies.erase(enemies.begin() + i);

				delete bullets[j];
				bullets.erase(bullets.begin() + j);

				enemy_deleted = true;
			}
		}
	}
}

void Game::updateGUI()
{
	// Ustawienie tekstu punkty
	std::stringstream ss;
	ss << "Points: " << points;
	pointText.setString(ss.str());

	// Update player GUI
	float hpPerCent = static_cast<float>(player->getHp()) / player->getHpMax();
	platerHpBar.setSize(sf::Vector2f(300.f * hpPerCent, platerHpBar.getSize().y));
}

void Game::updateWorld()
{
	// Cos dodac moze 
}

// RENDER

void Game::render()
{
	window->clear();

	// Draw bg
	renderWorld();
	// Draw all stuffs
	player->render(*window);

	for (auto* bullet : bullets)
	{
		bullet->render(window);
	}

	for (auto* enemy : enemies)
	{
		enemy->render(window);
	}

	renderGUI();

	// Game over screen
	if (player->getHp() <= 0)
	{
		// Tutaj wstawic teksture
		window->draw(GameOverShape);
		window->draw(GameOver);
	}

	window->display();
}

// Zmienic
void Game::renderWorld()
{
	window->draw(wolrdBackground);
}

void Game::renderGUI()
{
	window->draw(pointText);
	window->draw(playerHpBarBack);
	window->draw(platerHpBar);
}

int Game::gameStatus()
{
	return gameSatus1;
}

void Game::zamien(int a)
{
	if (a == 1) {
		gameSatus1 = 1;
	}
	if (a == 0) {
		gameSatus1 = 0;
	}
	if (a == 2) {
		gameSatus1 = 2;
	}
}




