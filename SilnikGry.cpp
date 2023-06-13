#include "SilnikGry.h"

void SilnikGry::stworzOkno()
{
	this->okno = new RenderWindow(VideoMode(1280, 720), "Game", Style::Close | Style::Titlebar);
	this->okno->setActive(true);
	this->okno->setFramerateLimit(60);
	this->okno->setKeyRepeatEnabled(false);
	this->okno->setMouseCursorGrabbed(false);
	this->okno->setMouseCursorVisible(true);
	this->okno->setVerticalSyncEnabled(false);
}

void SilnikGry::stworzTekstury()
{
	this->textures["player"] = new Texture;
	this->textures["player"]->loadFromFile("textures/rocket.png");

	this->textures["missile"] = new Texture;
	this->textures["missile"]->loadFromFile("textures/missile.png");
	
	this->textures["bomb"] = new Texture;
	this->textures["bomb"]->loadFromFile("textures/bomb.png");

	this->textures["asteroid"] = new Texture;
	this->textures["asteroid"]->loadFromFile("textures/asteroid.png");

	this->textures["coin"] = new Texture;
	this->textures["coin"]->loadFromFile("textures/coin.png");

	this->textures["power"] = new Texture;
	this->textures["power"]->loadFromFile("textures/power.png");

	this->textures["heart"] = new Texture;
	this->textures["heart"]->loadFromFile("textures/heart.png");

	this->textures["x2"] = new Texture;
	this->textures["x2"]->loadFromFile("textures/x2.png");

	this->textures["speed"] = new Texture;
	this->textures["speed"]->loadFromFile("textures/speed.png");

	this->textures["boom"] = new Texture;
	this->textures["boom"]->loadFromFile("textures/boom.png");

	this->textures["enemy"] = new Texture;
	this->textures["enemy"]->loadFromFile("textures/enemy.png");

	this->textures["enemy_2"] = new Texture;
	this->textures["enemy_2"]->loadFromFile("textures/enemy_2.png");
	
	this->textures["boss"] = new Texture;
	this->textures["boss"]->loadFromFile("textures/boss.png");
}


void SilnikGry::stworzGui()
{
	if (!this->font.loadFromFile("fonts/BAHNSCHRIFT.ttf"))
		cout << "Error: Font not load!";

	this->punkty.setPosition(20, 20);
	this->punkty.setFont(this->font);
	this->punkty.setCharacterSize(24);
	this->punkty.setFillColor(Color::White);
	this->punkty.setStyle(sf::Text::Bold);

	this->zdrowie.setPosition(20, 666);
	this->zdrowie.setFont(this->font);
	this->zdrowie.setCharacterSize(24);
	this->zdrowie.setFillColor(Color::White);
	this->zdrowie.setStyle(sf::Text::Bold);

	this->sila.setPosition(20, 636);
	this->sila.setFont(this->font);
	this->sila.setCharacterSize(24);
	this->sila.setFillColor(Color::Yellow);
	this->sila.setStyle(sf::Text::Bold);

	this->ROF.setPosition(20, 606);
	this->ROF.setFont(this->font);
	this->ROF.setCharacterSize(24);
	this->ROF.setFillColor(Color::Yellow);
	this->ROF.setStyle(sf::Text::Bold);


	this->BonusX2.setFont(this->font);
	this->BonusX2.setCharacterSize(42);
	this->BonusX2.setFillColor(Color(255,255,255,0));

	this->rectangle.setSize(sf::Vector2f(200, 20));
	this->rectangle.setFillColor(sf::Color::White);
	this->rectangle.setPosition(110, 672);
	this->HP_bar.setSize(sf::Vector2f(200, 20));
	this->HP_bar.setFillColor(sf::Color::Red);
	this->HP_bar.setPosition(110, 672);

	this->tloMenu.setSize(Vector2f(this->okno->getSize().x, this->okno->getSize().y));
	this->tloMenu.setFillColor(Color(0,0,0,170));
	
	this->pauza.setFont(this->font);
	this->pauza.setCharacterSize(120);
	this->pauza.setFillColor(Color::White);
	this->pauza.setStyle(sf::Text::Bold); 
	this->pauza.setString("PAUSE");
	this->pauza.setPosition(
		this->okno->getSize().x / 2 - this->pauza.getGlobalBounds().width / 2,
		this->okno->getSize().y / 6 - this->pauza.getGlobalBounds().height / 2
	);

	this->wznow.setFont(this->font);
	this->wznow.setCharacterSize(45);
	this->wznow.setFillColor(Color::White);
	this->wznow.setStyle(sf::Text::Bold);
	this->wznow.setString("RETURN");
	this->wznow.setPosition(
		this->okno->getSize().x / 2 - this->wznow.getGlobalBounds().width / 2,
		this->okno->getSize().y / 2 - this->wznow.getGlobalBounds().height / 2 - 30
	);

	this->wyjdz.setFont(this->font);
	this->wyjdz.setCharacterSize(45);
	this->wyjdz.setFillColor(Color::White);
	this->wyjdz.setStyle(sf::Text::Bold);
	this->wyjdz.setString("EXIT");
	this->wyjdz.setPosition(
		this->okno->getSize().x / 2 - this->wyjdz.getGlobalBounds().width / 2,
		this->okno->getSize().y / 2 - this->wyjdz.getGlobalBounds().height / 2 + 30
	);

	this->latwy.setFont(this->font);
	this->latwy.setCharacterSize(45);
	this->latwy.setFillColor(Color::Black);
	this->latwy.setStyle(sf::Text::Bold);
	this->latwy.setString("EASY");
	this->latwy.setPosition(
		this->okno->getSize().x / 2 - this->latwy.getGlobalBounds().width / 2 - 150,
		this->okno->getSize().y / 1.2 - this->latwy.getGlobalBounds().height / 2 
	);

	this->trudny.setFont(this->font);
	this->trudny.setCharacterSize(45);
	this->trudny.setFillColor(Color::Black);
	this->trudny.setStyle(sf::Text::Bold);
	this->trudny.setString("HARD");
	this->trudny.setPosition(
		this->okno->getSize().x / 2 - this->trudny.getGlobalBounds().width / 2 + 150,
		this->okno->getSize().y / 1.2 - this->trudny.getGlobalBounds().height / 2
	);

	this->start.setFont(this->font);
	this->start.setCharacterSize(75);
	this->start.setFillColor(Color::Black);
	this->start.setStyle(sf::Text::Bold);
	this->start.setString("START");
	this->start.setPosition(
		this->okno->getSize().x / 2 - this->start.getGlobalBounds().width / 2,
		this->okno->getSize().y / 1.10 - this->start.getGlobalBounds().height / 2
	);

	this->napisKoncowy.setFont(this->font);
	this->napisKoncowy.setCharacterSize(100);
	this->napisKoncowy.setStyle(sf::Text::Bold);
}

void SilnikGry::stworzObiekty()
{
	player = new Gracz(this->textures["player"], 0, 0);  //TEKSTURA GRACZA

	Vector2i start_position(this->okno->getSize().x / 2 - this->player->getBounds().width / 2,
		this->okno->getSize().y / 2 - this->player->getBounds().height / 2 + 260);

	Mouse::setPosition(start_position, *this->okno);  // TOTALNIE CZARODZIEJSKIE TAJNIKI ŒRODKOWANIA I POZYCJONOWANIA XD
}

void SilnikGry::stworzTlo()
{
	//Zaladuj teksture
	if (this->textureTlo.loadFromFile("textures/background.png") == false)
	{
		cout << "Error: Nie zaladowano tla!" << endl;
	}
	//Zaladuj teksture do typu sprite
	this->spriteTlo.setTexture(this->textureTlo);
	//Rozmiar Tla
	this->spriteTlo.scale(4.f, 4.f);
}

void SilnikGry::stworzDzwieki()
{
	if (!buffer_shoot.loadFromFile("sounds/shoot.ogg")) {
		cout << "Error: Sound not load!" << endl;
	}
	if (!buffer_boom.loadFromFile("sounds/boom.ogg")) {
		cout << "Error: Sound not load!" << endl;
		sound_boom.setVolume(50.f);
	}
	if (!buffer_money.loadFromFile("sounds/money.ogg")) {
		cout << "Error: Sound not load!" << endl;
	}
	if (!buffer_effect.loadFromFile("sounds/power.ogg")) {
		cout << "Error: Sound not load!" << endl;
	}
}


SilnikGry::SilnikGry()
{
	this->stworzOkno();
	this->stworzTekstury();
	this->stworzGui();
	this->stworzObiekty();
	this->stworzTlo();
	this->stworzDzwieki();
}

SilnikGry::~SilnikGry()
{
	delete this->okno;
}

void SilnikGry::run()
{
	while (this->okno->isOpen())
	{
		this->updatePollEvents();
		if (!gamePaused && this->HP > 0 && koniecGry == 0) {
			this->update();
			this->render();
			this->rozgrywka();
		}
		else if (this->HP <= 0) {
			koniecGry = 1;
			this->okno->clear();
			this->napisKoncowy.setFillColor(Color::Red);
			this->napisKoncowy.setString("YOU DIED");
			this->napisKoncowy.setPosition(
				this->okno->getSize().x / 2 - this->napisKoncowy.getGlobalBounds().width / 2,
				this->okno->getSize().y / 2 - this->napisKoncowy.getGlobalBounds().height / 2
			);
			this->okno->draw(this->napisKoncowy);
			this->okno->display();
		}
		else if (koniecGry == 1) {
			this->okno->clear();
			this->napisKoncowy.setFillColor(Color::Green);
			this->napisKoncowy.setString("YOU WIN");
			this->napisKoncowy.setPosition(
				this->okno->getSize().x / 2 - this->napisKoncowy.getGlobalBounds().width / 2,
				this->okno->getSize().y / 2 - this->napisKoncowy.getGlobalBounds().height / 2
			);

			stringstream money;
			money << "YOU EARNED: " << this->money << "$";

			this->start.setFillColor(Color::Green);
			this->start.setString(money.str());
			this->start.setPosition(
				this->okno->getSize().x / 2 - this->start.getGlobalBounds().width / 2,
				this->okno->getSize().y / 1.5 - this->start.getGlobalBounds().height / 2
			);

			this->okno->draw(this->napisKoncowy);
			this->okno->draw(this->start);
			this->okno->display();

		}
	}
}

void SilnikGry::updatePollEvents()
{
	while (this->okno->pollEvent(e))
	{
		if (e.Event::type == Event::Closed)
			this->okno->close();

		if (e.type == Event::KeyPressed && e.Event::key.code == Keyboard::Escape && koniecGry == 1) {
			this->okno->close();
		}

		if (e.type == Event::KeyPressed && e.Event::key.code == Keyboard::Escape && !wstep && koniecGry == 0) {
			gamePaused = !gamePaused;
			delta_clock.restart();
			if (gamePaused == 1) {
				saved_mouse_pos = Mouse::getPosition();
				this->okno->setMouseCursorVisible(true);
			}
			else {
				Mouse::setPosition(saved_mouse_pos);
				this->okno->setMouseCursorVisible(false);
			}

			while (gamePaused == 1) {
				render();
				updatePollEvents();
				if (Mouse::isButtonPressed(Mouse::Left) && wznow.getGlobalBounds().contains(this->okno->mapPixelToCoords(Mouse::getPosition(*okno)))) {
					gamePaused = 0;
					
					delta_clock.restart();
					Mouse::setPosition(saved_mouse_pos);
					this->okno->setMouseCursorVisible(false);
				}
				if (Mouse::isButtonPressed(Mouse::Left) && wyjdz.getGlobalBounds().contains(this->okno->mapPixelToCoords(Mouse::getPosition(*okno)))) {
					this->okno->close();
				}
			}
		}
		while (wstep) {
			
			tloGlowneMenu.setFillColor(Color::White);
			tloGlowneMenu.setSize(Vector2f(1280, 720));

			Texture infobox;
			infobox.loadFromFile("textures/infobox.png");
			Sprite info_box;
			info_box.setTexture(infobox);
			info_box.setScale(0.5f, 0.5f);
			info_box.setPosition(this->okno->getSize().x / 2 - info_box.getGlobalBounds().width / 2, 20);

			this->okno->draw(this->tloGlowneMenu);
			this->okno->draw(info_box);
			this->okno->draw(this->latwy);
			this->okno->draw(this->trudny);
			this->okno->draw(this->start);
		
			this->okno->display();

			if (Mouse::isButtonPressed(Mouse::Left) && latwy.getGlobalBounds().contains(this->okno->mapPixelToCoords(Mouse::getPosition(*okno)))) {
				this->szansa = 4;
				this->power = 4;
			}
			if (Mouse::isButtonPressed(Mouse::Left) && trudny.getGlobalBounds().contains(this->okno->mapPixelToCoords(Mouse::getPosition(*okno)))) {
				this->szansa = 1;
				this->power = 1;
			}
			if (Mouse::isButtonPressed(Mouse::Left) && start.getGlobalBounds().contains(this->okno->mapPixelToCoords(Mouse::getPosition(*okno)))) {
				this->clock.restart();
				wstep = 0;
				this->okno->setMouseCursorGrabbed(true);
				this->okno->setMouseCursorVisible(false);
				cout << "Zaczynamy przygode!";
			}

			updatePollEvents();
		}
	}	

	if (!gamePaused) {
		mouse_pos = Mouse::getPosition(*okno);
		translated_pos = this->okno->mapPixelToCoords(mouse_pos);

		this->player->setPosition(translated_pos.x - this->player->getBounds().width / 2, translated_pos.y - this->player->getBounds().height / 2);

		if (Mouse::isButtonPressed(Mouse::Left) && this->cooldown.asMilliseconds() > 2000 / this->rof) {
			this->missiles.emplace_back(new Missile(this->textures["missile"], translated_pos.x - 8, translated_pos.y - this->player->getBounds().height / 2));
			sound.setBuffer(this->buffer_shoot);
			sound.play();
			this->cooldown = cooldown_clock.restart();
		}

		this->time = clock.getElapsedTime();
		this->cooldown = cooldown_clock.getElapsedTime();
	}
}


void SilnikGry::updateGui()
{
	stringstream pkt;
	pkt << "Money: " << this->money;
	this->punkty.setString(pkt.str());

	stringstream hp;
	hp << "HP: " << this->HP;
	this->zdrowie.setString(hp.str());

	stringstream power;
	power << "Power: " << this->power;
	this->sila.setString(power.str());

	stringstream rof_text;
	rof_text << "ROF: " << this->rof;
	this->ROF.setString(rof_text.str());

	stringstream bonus_text;
	bonus_text << "MONEY x2: " << 20-int(this->bonus_clock.getElapsedTime().asSeconds()) << " SECONDS";

	this->BonusX2.setString(bonus_text.str());
	this->BonusX2.setPosition(
		this->okno->getSize().x / 2 - BonusX2.getGlobalBounds().width / 2,
		(this->okno->getSize().y / 2 - BonusX2.getGlobalBounds().height / 2)/8
	);

	this->HP_bar.setSize(sf::Vector2f(2*(this->HP), 20));

	if (this->HP < 0) { this->HP = 0; }
}

void SilnikGry::updateCollision()
{

	//ASTEROIDA + POCISK
	for (auto ast = asteroids.begin(); ast != asteroids.end(); ) {
		bool collisionDetected = false;

		for (auto mis = missiles.begin(); mis != missiles.end(); ) {
			if ((*ast)->getPos().y > 5 && (*ast)->getBounds().intersects((*mis)->getBounds())) {
				sound_boom.setBuffer(this->buffer_boom);
				sound_boom.play();
				
				this->coins.emplace_back(new Coin(this->textures["coin"], (*ast)->getPos().x , (*ast)->getPos().y  ));

				this->explosions.emplace_back(new Boom(this->textures["boom"], (*ast)->getPos().x - (*ast)->getBounds().width / 2, (*ast)->getPos().y - (*ast)->getBounds().height / 2));

				// Usuniêcie obiektu z wektora asteroids
				delete* ast;
				ast = asteroids.erase(ast);
				// Usuniêcie obiektu z wektora missiles
				delete* mis;
				mis = missiles.erase(mis);
				collisionDetected = true;
	
				break;
			}
			else {
				++mis;
			}
		}
		if (!collisionDetected) {
			++ast;
		}
	}
	//PRZECIWNIK + POCISK
	for (auto en = enemies.begin(); en != enemies.end(); ) {
		bool collisionDetected = false;
		Enemy* enemy = dynamic_cast<Enemy*>(*en);

		if (rand() % 1000 < 1 && (*en)->getCzas() > 2000 && (*en)->getPos().y > -100) {
			this->enemy_missiles.emplace_back(new Enemy_missile(this->textures["bomb"], (*en)->getPos().x+26, (*en)->getPos().y+(*en)->getBounds().height/1.8  ));
			(*en)->restetCzas();
		}

		for (auto mis = missiles.begin(); mis != missiles.end(); ) {
			if ((*en)->getBounds().intersects((*mis)->getBounds())) {
				int wartosc_damage = 10 * this->power;
				enemy->HP -= wartosc_damage;

				// Usuniêcie obiektu z wektora enemies
				if (enemy->HP <= 0) {
					sound_boom.setBuffer(this->buffer_boom);
					sound_boom.play();
					if (rand() % 20 < this->szansa) { // SZANSA NA BONUS!!!
						this->bonuses_power.emplace_back(new Bonus(this->textures["power"], (*en)->getPos().x - ((80 - (*en)->getBounds().width) / 2), (*en)->getPos().y - ((80 - (*en)->getBounds().height) / 2)));
					}
					else if (rand() % 20 < this->szansa) {
						this->bonuses_health.emplace_back(new Bonus(this->textures["heart"], (*en)->getPos().x - ((80 - (*en)->getBounds().width) / 2), (*en)->getPos().y - ((80 - (*en)->getBounds().height) / 2)));
					}
					else if (rand() % 20 < this->szansa) {
						this->bonuses_rof.emplace_back(new Bonus(this->textures["speed"], (*en)->getPos().x - ((80 - (*en)->getBounds().width) / 2), (*en)->getPos().y - ((80 - (*en)->getBounds().height) / 2)));
					}
					else if (rand() % 20 < this->szansa) {
						this->bonuses_x2.emplace_back(new Bonus(this->textures["x2"], (*en)->getPos().x - ((80 - (*en)->getBounds().width) / 2), (*en)->getPos().y - ((80 - (*en)->getBounds().height) / 2)));
					}
					else {
						this->coins.emplace_back(new Coin(this->textures["coin"], (*en)->getPos().x - ((80 - (*en)->getBounds().width) / 2), (*en)->getPos().y - ((80 - (*en)->getBounds().height) / 2)));
					}
					int wartosc_money = 10 * this->mnoznik;

					stringstream ind;
					ind << "+" << wartosc_money;

					this->indicators.emplace_back(new Indicator((*en)->getPos().x - ((80 - (*en)->getBounds().width) / 2)+80, (*en)->getPos().y - ((80 - (*en)->getBounds().height) / 2)+20, ind.str(), Color(252, 194, 0, 1)));
					
					this->money += wartosc_money;
					this->explosions.emplace_back(new Boom(this->textures["boom"], (*en)->getPos().x-((120-(*en)->getBounds().width)/2), (*en)->getPos().y - ((200 - (*en)->getBounds().height) / 2)));
					delete* en;
					en = enemies.erase(en);
				}
				else {
					stringstream ind;
					ind << "-" << wartosc_damage;

					this->indicators.emplace_back(new Indicator((*en)->getPos().x - ((80 - (*en)->getBounds().width) / 2) + 80, (*en)->getPos().y - ((80 - (*en)->getBounds().height) / 2)-20, ind.str(), Color(255, 71, 73, 1)));
				}
				// Usuniêcie obiektu z wektora missiles
				this->explosions.emplace_back(new Boom(this->textures["boom"], (*mis)->getPos().x - ((*mis)->getBounds().width/2), (*mis)->getPos().y - ((*mis)->getBounds().height/ 2) - 22, 0.4f ));
				delete* mis;
				mis = missiles.erase(mis);
				collisionDetected = true;

				break;
			}
			else {
				++mis;
			}
		}
		if (!collisionDetected) {
			++en;
		}
	}


	// PRZECIWNIK 2
	for (auto en = enemies_2.begin(); en != enemies_2.end(); ) {
		bool collisionDetected = false;
		Enemy* enemy = dynamic_cast<Enemy*>(*en);

		if (rand() % 1000 < 2 && (*en)->getCzas() > 1000 && (*en)->getPos().y > -100) {
			this->enemy_missiles.emplace_back(new Enemy_missile(this->textures["bomb"], (*en)->getPos().x + 26, (*en)->getPos().y + (*en)->getBounds().height / 1.8));
			(*en)->restetCzas();
		}

		for (auto mis = missiles.begin(); mis != missiles.end(); ) {
			if ((*en)->getBounds().intersects((*mis)->getBounds())) {
				int wartosc_damage = 5 * this->power;
				enemy->HP -= wartosc_damage;

				// Usuniêcie obiektu z wektora enemies
				if (enemy->HP <= 0) {
					sound_boom.setBuffer(this->buffer_boom);
					sound_boom.play();
					if (rand() % 20 < this->szansa) { // SZANSA NA BONUS!!!
						this->bonuses_power.emplace_back(new Bonus(this->textures["power"], (*en)->getPos().x - ((80 - (*en)->getBounds().width) / 2), (*en)->getPos().y - ((80 - (*en)->getBounds().height) / 2)));
					}
					else if (rand() % 20 < this->szansa) {
						this->bonuses_health.emplace_back(new Bonus(this->textures["heart"], (*en)->getPos().x - ((80 - (*en)->getBounds().width) / 2), (*en)->getPos().y - ((80 - (*en)->getBounds().height) / 2)));
					}
					else if (rand() % 20 < this->szansa) {
						this->bonuses_rof.emplace_back(new Bonus(this->textures["speed"], (*en)->getPos().x - ((80 - (*en)->getBounds().width) / 2), (*en)->getPos().y - ((80 - (*en)->getBounds().height) / 2)));
					}
					else if (rand() % 20 < this->szansa) {
						this->bonuses_x2.emplace_back(new Bonus(this->textures["x2"], (*en)->getPos().x - ((80 - (*en)->getBounds().width) / 2), (*en)->getPos().y - ((80 - (*en)->getBounds().height) / 2)));
					}
					else {
						this->coins.emplace_back(new Coin(this->textures["coin"], (*en)->getPos().x - ((80 - (*en)->getBounds().width) / 2), (*en)->getPos().y - ((80 - (*en)->getBounds().height) / 2)));
					}
					int wartosc_money = 20 * this->mnoznik;

					stringstream ind;
					ind << "+" << wartosc_money;

					this->indicators.emplace_back(new Indicator((*en)->getPos().x - ((80 - (*en)->getBounds().width) / 2) + 80, (*en)->getPos().y - ((80 - (*en)->getBounds().height) / 2) + 20, ind.str(), Color(252, 194, 0, 1)));

					this->money += wartosc_money;
					this->explosions.emplace_back(new Boom(this->textures["boom"], (*en)->getPos().x - ((120 - (*en)->getBounds().width) / 2), (*en)->getPos().y - ((200 - (*en)->getBounds().height) / 2)));
					delete* en;
					en = enemies_2.erase(en);
				}
				else {
					stringstream ind;
					ind << "-" << wartosc_damage;

					this->indicators.emplace_back(new Indicator((*en)->getPos().x - ((80 - (*en)->getBounds().width) / 2) + 80, (*en)->getPos().y - ((80 - (*en)->getBounds().height) / 2) - 20, ind.str(), Color(255, 71, 73, 1)));
				}
				// Usuniêcie obiektu z wektora missiles
				this->explosions.emplace_back(new Boom(this->textures["boom"], (*mis)->getPos().x - ((*mis)->getBounds().width / 2), (*mis)->getPos().y - ((*mis)->getBounds().height / 2) - 22, 0.4f));
				delete* mis;
				mis = missiles.erase(mis);
				collisionDetected = true;

				break;
			}
			else {
				++mis;
			}
		}
		if (!collisionDetected) {
			++en;
		}
	}

	Boss* boss = dynamic_cast<Boss*>(this->boss_enemy);

	if (boss != nullptr) {
		for (auto mis = missiles.begin(); mis != missiles.end();) {
			if ((*mis)->getBounds().intersects(boss->getBounds()) && boss->getCzas() > 1000) {
				int wartosc_damage = 10 * this->power;
				boss->HP -= wartosc_damage;

				// Usuniêcie obiektu
				if (boss->HP <= 0) {
					sound_boom.setBuffer(this->buffer_boom);
					sound_boom.play();

					int wartosc_money = 200 * this->mnoznik;

					stringstream ind;
					ind << "+" << wartosc_money;

					this->indicators.emplace_back(new Indicator(boss->getPos().x - ((200 - boss->getBounds().width) / 2) + 160, boss->getPos().y - ((200 - boss->getBounds().height) / 2) -40, ind.str(), Color(252, 194, 0, 1)));

					this->money += wartosc_money;
					this->explosions.emplace_back(new Boom(this->textures["boom"], boss->getPos().x - ((120 - boss->getBounds().width) / 2), boss->getPos().y - ((200 - boss->getBounds().height) / 2)));
					delete boss;
				}
				else {
					stringstream ind;
					ind << "-" << wartosc_damage;

					this->indicators.emplace_back(new Indicator(boss->getPos().x - ((200 - boss->getBounds().width) / 2) + 160, boss->getPos().y - ((200 - boss->getBounds().height) / 2) - 40, ind.str(), Color(255, 71, 73, 1)));
				}
				// Usuniêcie obiektu z wektora missiles
				this->explosions.emplace_back(new Boom(this->textures["boom"], (*mis)->getPos().x - ((*mis)->getBounds().width / 2), (*mis)->getPos().y - ((*mis)->getBounds().height / 2) - 22, 0.4f));
				delete* mis;
				mis = missiles.erase(mis);
			}
			else {
				++mis;
			}

		}
	}

	//POCISK
	for (auto mis = missiles.begin(); mis != missiles.end(); ) {
        if ((*mis)->getPos().y < -200) {
            delete *mis;
            mis = missiles.erase(mis);
        } else {
            ++mis;
        }
    }
	for (auto mis = enemy_missiles.begin(); mis != enemy_missiles.end(); ) {
		if ((*mis)->getPos().y >800) {
			delete* mis;
			mis = enemy_missiles.erase(mis);
		}
		else {
			++mis;
		}
	}

	//MONETA
	for (auto* el : this->coins) {
		if (el->getBounds().intersects(this->player->getBounds())) {

			int wartosc_money = 5 * this->mnoznik;
			stringstream ind;
			ind << "+" << wartosc_money << "$";

			this->indicators.emplace_back(new Indicator(el->getPos().x + 25, el->getPos().y, ind.str(), Color(252, 194, 0, 1)));
			coins.erase(std::remove(coins.begin(), coins.end(), el), coins.end());
			delete el;
			this->money += 5 * this->mnoznik;;
			if (this->sounds_money.size() > 5) {
				this->sounds_money.erase(this->sounds_money.begin());
			}
			Sound* dzwiek = new Sound;
			this->sounds_money.emplace_back(dzwiek);
			(*this->sounds_money.back()).setBuffer(this->buffer_money);
			(*this->sounds_money.back()).play();
		}
	}

	if (this->player->getCzas() > 2000) {

		for (auto el : this->enemy_missiles) {
			if (el->getBounds().intersects(this->player->getBounds())) {

				this->explosions.emplace_back(new Boom(this->textures["boom"], player->getPos().x - player->getBounds().width / 2, player->getPos().y - player->getBounds().height / 2));
				enemy_missiles.erase(std::remove(enemy_missiles.begin(), enemy_missiles.end(), el), enemy_missiles.end());
				delete el;
				this->HP -= 25;
				this->player->restetCzas();
				this->indicators.emplace_back(new Indicator(player->getPos().x + 80, player->getPos().y - 20, "-25HP", Color(255, 71, 73, 1)));

				Vector2i start_position(this->okno->getSize().x / 2 - this->player->getBounds().width / 2,
					this->okno->getSize().y / 2 - this->player->getBounds().height / 2 + 260);
				Mouse::setPosition(start_position, *this->okno);

				sound_boom.setBuffer(this->buffer_boom);
				sound_boom.play();
			}
		}


		//BONUS
		for (auto* el : this->bonuses_power) {
			if (el->getBounds().intersects(this->player->getBounds())) {
				this->indicators.emplace_back(new Indicator(el->getPos().x + 25, el->getPos().y, "+POWER", Color(134, 249, 86, 1)));
				bonuses_power.erase(std::remove(bonuses_power.begin(), bonuses_power.end(), el), bonuses_power.end());
				delete el;
				this->power++;
				sound_effect.setBuffer(this->buffer_effect);
				sound_effect.play();
			}
		}

		for (auto* el : this->bonuses_health) {
			if (el->getBounds().intersects(this->player->getBounds())) {
				this->indicators.emplace_back(new Indicator(el->getPos().x + 25, el->getPos().y, "+25HP", Color(134, 249, 86, 1)));
				bonuses_health.erase(std::remove(bonuses_health.begin(), bonuses_health.end(), el), bonuses_health.end());
				delete el;
				this->HP += 25;
				if (this->HP > 100) { this->HP = 100; }
				sound_effect.setBuffer(this->buffer_effect);
				sound_effect.play();
			}
		}

		for (auto* el : this->bonuses_rof) {
			if (el->getBounds().intersects(this->player->getBounds())) {
				this->indicators.emplace_back(new Indicator(el->getPos().x + 25, el->getPos().y, "+5ROF", Color(134, 249, 86, 1)));
				bonuses_rof.erase(std::remove(bonuses_rof.begin(), bonuses_rof.end(), el), bonuses_rof.end());
				delete el;
				this->rof += 5;
				sound_effect.setBuffer(this->buffer_effect);
				sound_effect.play();
			}
		}

		for (auto* el : this->bonuses_x2) {
			if (el->getBounds().intersects(this->player->getBounds())) {
				this->indicators.emplace_back(new Indicator(el->getPos().x + 25, el->getPos().y, "+BONUS", Color(134, 249, 86, 1)));
				bonuses_x2.erase(std::remove(bonuses_x2.begin(), bonuses_x2.end(), el), bonuses_x2.end());
				delete el;
				this->mnoznik = 2;
				this->BonusX2.setFillColor(Color(255, 255, 255, 128));
				this->bonus_clock.restart();
				sound_effect.setBuffer(this->buffer_effect);
				sound_effect.play();
			}
		}



		//ASTEROIDA 
		for (auto* ast : this->asteroids) {
			if (ast->getPos().y > 720 + ast->getBounds().height) {
				asteroids.erase(std::remove(asteroids.begin(), asteroids.end(), ast), asteroids.end());
				delete ast;
			}
			//ASTEROIDA + GRACZ
			else if (ast->getBounds().intersects(this->player->getBounds())) {
				this->explosions.emplace_back(new Boom(this->textures["boom"], player->getPos().x - player->getBounds().width / 2, player->getPos().y - player->getBounds().height / 2));
				asteroids.erase(std::remove(asteroids.begin(), asteroids.end(), ast), asteroids.end());
				delete ast;
				this->HP -= 25;
				this->player->restetCzas();
				this->indicators.emplace_back(new Indicator(player->getPos().x + 80, player->getPos().y - 20, "-25HP", Color(255, 71, 73, 1)));

				Vector2i start_position(this->okno->getSize().x / 2 - this->player->getBounds().width / 2,
					this->okno->getSize().y / 2 - this->player->getBounds().height / 2 + 260);
				Mouse::setPosition(start_position, *this->okno);

				sound_boom.setBuffer(this->buffer_boom);
				sound_boom.play();
			}
		}
		for (auto en = enemies.begin(); en != enemies.end(); ) {
			bool collisionDetected = false;
			Enemy* enemy = dynamic_cast<Enemy*>(*en);
			if ((*en)->getBounds().intersects(this->player->getBounds())) {
				enemy->HP -= 25;
				this->explosions.emplace_back(new Boom(this->textures["boom"], player->getPos().x - player->getBounds().width / 2, player->getPos().y - player->getBounds().height / 2));
				this->HP -= 25;
				this->player->restetCzas();
				this->indicators.emplace_back(new Indicator(player->getPos().x + 80, player->getPos().y - 20, "-25HP", Color(255, 71, 73, 1)));
				if (enemy->HP <= 0) {
					sound_boom.setBuffer(this->buffer_boom);
					sound_boom.play();
					this->coins.emplace_back(new Coin(this->textures["coin"], (*en)->getPos().x - ((80 - (*en)->getBounds().width) / 2), (*en)->getPos().y - ((80 - (*en)->getBounds().height) / 2)));  //WYMIARY ENEMY
					this->explosions.emplace_back(new Boom(this->textures["boom"], (*en)->getPos().x - ((120 - (*en)->getBounds().width) / 2), (*en)->getPos().y - ((160 - (*en)->getBounds().height) / 2)));  //WYMIARY EKSPLOZJI
					delete* en;
					en = enemies.erase(en);
				}
				Vector2i start_position(this->okno->getSize().x / 2 - this->player->getBounds().width / 2,
					this->okno->getSize().y / 2 - this->player->getBounds().height / 2 + 260);
				Mouse::setPosition(start_position, *this->okno);

				sound_boom.setBuffer(this->buffer_boom);
				sound_boom.play();

				collisionDetected = true;
				break;
			}
			if (!collisionDetected) {
				++en;
			}
		}

		for (auto en = enemies_2.begin(); en != enemies_2.end(); ) {
			bool collisionDetected = false;
			Enemy* enemy = dynamic_cast<Enemy*>(*en);
			if ((*en)->getBounds().intersects(this->player->getBounds())) {
				enemy->HP -= 25;
				this->explosions.emplace_back(new Boom(this->textures["boom"], player->getPos().x - player->getBounds().width / 2, player->getPos().y - player->getBounds().height / 2));
				this->HP -= 25;
				this->player->restetCzas();
				this->indicators.emplace_back(new Indicator(player->getPos().x + 80, player->getPos().y - 20, "-25HP", Color(255, 71, 73, 1)));
				if (enemy->HP <= 0) {
					sound_boom.setBuffer(this->buffer_boom);
					sound_boom.play();
					this->coins.emplace_back(new Coin(this->textures["coin"], (*en)->getPos().x - ((80 - (*en)->getBounds().width) / 2), (*en)->getPos().y - ((80 - (*en)->getBounds().height) / 2)));  //WYMIARY ENEMY
					this->explosions.emplace_back(new Boom(this->textures["boom"], (*en)->getPos().x - ((120 - (*en)->getBounds().width) / 2), (*en)->getPos().y - ((160 - (*en)->getBounds().height) / 2)));  //WYMIARY EKSPLOZJI
					delete* en;
					en = enemies_2.erase(en);
				}
				Vector2i start_position(this->okno->getSize().x / 2 - this->player->getBounds().width / 2,
					this->okno->getSize().y / 2 - this->player->getBounds().height / 2 + 260);
				Mouse::setPosition(start_position, *this->okno);

				sound_boom.setBuffer(this->buffer_boom);
				sound_boom.play();

				collisionDetected = true;
				break;
			}
			if (!collisionDetected) {
				++en;
			}
		}

		if (boss_enemy != nullptr && boss->getBounds().intersects(this->player->getBounds())) {
			boss->HP -= 25;
			this->explosions.emplace_back(new Boom(this->textures["boom"], player->getPos().x - player->getBounds().width / 2, player->getPos().y - player->getBounds().height / 2));
			this->HP -= 25;
			this->player->restetCzas();
			this->indicators.emplace_back(new Indicator(player->getPos().x + 80, player->getPos().y - 20, "-25HP", Color(255, 71, 73, 1)));
			if (boss->HP <= 0) {
				sound_boom.setBuffer(this->buffer_boom);
				sound_boom.play();
				this->coins.emplace_back(new Coin(this->textures["coin"], boss->getPos().x - ((80 - boss->getBounds().width) / 2), boss->getPos().y - ((80 - boss->getBounds().height) / 2)));  //WYMIARY ENEMY
				this->explosions.emplace_back(new Boom(this->textures["boom"], boss->getPos().x - ((120 - boss->getBounds().width) / 2), boss->getPos().y - ((160 - boss->getBounds().height) / 2)));  //WYMIARY EKSPLOZJI
				delete boss;
			}
			Vector2i start_position(this->okno->getSize().x / 2 - this->player->getBounds().width / 2,
				this->okno->getSize().y / 2 - this->player->getBounds().height / 2 + 260);
			Mouse::setPosition(start_position, *this->okno);

			sound_boom.setBuffer(this->buffer_boom);
			sound_boom.play();
		}
	}
}

void SilnikGry::update()
{
	delta_time = delta_clock.restart();
	float dt = delta_time.asMilliseconds();

	this->frame++;


	this->updateGui();
	this->updateCollision();

	this->player->update(dt);

	if(boss_enemy != nullptr)
	this->boss_enemy->update(dt);

	for (auto el : this->coins) {
		el->update(dt);
	}
	for (auto el : this->asteroids) {
		el->update(dt);
	}
	for (auto el : this->missiles) {
		el->update(dt);
	}
	for (auto el : this->enemy_missiles) {
		el->update(dt);
	}
	for (auto el : this->explosions) {
		el->update(dt);
	}
	for (auto el : this->enemies) {
		el->update(dt);
	}
	for (auto el : this->enemies_2) {
		el->update(dt);
	}
	for (auto el : this->bonuses_power) {
		el->update(dt);
	}
	for (auto el : this->bonuses_health) {
		el->update(dt);
	}
	for (auto el : this->bonuses_rof) {
		el->update(dt);
	}
	for (auto el : this->bonuses_x2) {
		el->update(dt);
	}
	for (auto el : this->indicators) {
		el->update();
		if (el->getCzas() >= el->getCzasTrwania()){
			indicators.erase(std::remove(indicators.begin(), indicators.end(), el), indicators.end());
		}
	}

	if (this->bonus_clock.getElapsedTime().asSeconds() > 20 && this->mnoznik != 1) {
		this->mnoznik = 1;
		this->BonusX2.setFillColor(Color(255, 255, 255, 0));
	}


	if (frame > 960) { frame = 0; }
	this->spriteTlo.setTextureRect(IntRect(0, 480 - int(frame / 2), 1280,720));


	for (auto asset = explosions.begin(); asset != explosions.end();) {
		// SprawdŸ, czy wskaŸnik wskazuje na obiekt klasy Boom
		if (Boom *boom = dynamic_cast<Boom*>(*asset)) {
			if (boom->getCzas() >= boom->getCzasTrwania()) {
				asset = explosions.erase(asset);
			}
			else {
				++asset;
			}
		}
	}
}

void SilnikGry::renderGui()
{
	this->okno->draw(this->punkty);
	this->okno->draw(this->zdrowie);
	this->okno->draw(this->sila);
	this->okno->draw(this->ROF);
	this->okno->draw(this->BonusX2);
	this->okno->draw(this->rectangle);
	this->okno->draw(this->HP_bar);
}

void SilnikGry::render()
{
	this->okno->clear();
	this->okno->draw(this->spriteTlo);
	
	for (auto el : this->coins) {
		el->render(this->okno);
	}
	for (auto el : this->enemy_missiles) {
		el->render(this->okno);
	}
	for (auto el : this->asteroids) {
		el->render(this->okno);
	}
	for (auto el : this->missiles) {
		el->render(this->okno);
	}
	for (auto el : this->bonuses_power) {
		el->render(this->okno);
	}
	for (auto el : this->bonuses_health) {
		el->render(this->okno);
	}
	for (auto el : this->bonuses_rof) {
		el->render(this->okno);
	}
	for (auto el : this->bonuses_x2) {
		el->render(this->okno);
	}
	

	for (auto asset = enemies.begin(); asset != enemies.end();) {
		if (Enemy* enemy = dynamic_cast<Enemy*>(*asset)) {
			enemy->render(this->okno);
		}
		++asset;
	}

	for (auto asset = enemies_2.begin(); asset != enemies_2.end();) {
		if (Enemy* enemy = dynamic_cast<Enemy*>(*asset)) {
			enemy->render(this->okno);
		}
		++asset;
	}


	if (boss_enemy != nullptr) {
		Boss* el = dynamic_cast<Boss*>(boss_enemy);
		el->render(this->okno);
	}
	

	this->player->render(this->okno);


	for (auto el : this->explosions) {
		el->render(this->okno);
	}
	for (auto el : this->indicators) {
		el->render(this->okno);
	}

	this->renderGui();

	if (gamePaused) {
		this->okno->draw(this->tloMenu);
		this->okno->draw(this->pauza);
		this->okno->draw(this->wznow);
		this->okno->draw(this->wyjdz);

	}

	this->okno->display();
}

void SilnikGry::rozgrywka()
{
	if (flaga == 0 && time.asSeconds() > 1) {
		flaga++;
		for (int i = 0; i < rand() % 6 + 4; i++) {
			this->asteroids.emplace_back(new Asteroid(this->textures["asteroid"], rand() % (this->okno->getSize().x - 200) + 100, rand()% 800 - 1000));
			//boss_enemy = new Boss(this->textures["boss"], rand() % (this->okno->getSize().x - 200) + 100, rand() % 800 - 1000);
		}
	}
	if (flaga == 1 && time.asSeconds() > 8 && this->asteroids.empty()) {
		flaga++;
		for (int i = 0; i < rand() % 6 + 4; i++) {
			this->enemies.emplace_back(new Enemy(this->textures["enemy"], rand() % (this->okno->getSize().x-200) + 100, rand() % 800 - 1000));
		}
	}
	if (flaga == 2 && time.asSeconds() > 18 && this->enemies.empty()) {
		flaga++;
		for (int i = 0; i < rand() % 8 + 4; i++) {
			this->enemies.emplace_back(new Enemy(this->textures["enemy_2"], rand() % (this->okno->getSize().x - 200) + 100, rand() % 800 - 1000));
			/*for (int j = 0; j < i; j++) { 
				while (this->enemies[j]->getBounds().intersects(this->enemies[i]->getBounds()) || this->enemies[j]->getBounds().intersects(this->player->getBounds())) {
					this->enemies[i]->setPosition(rand() % (this->okno->getSize().x - 200) + 100, -200);
				}
			}*/  
		}
	}
	if (flaga == 3 && time.asSeconds() > 24 && this->enemies.empty()) {
		flaga++;
		for (int i = 0; i < rand() % 2 + 2; i++) {
			this->enemies_2.emplace_back(new Enemy(this->textures["enemy_2"], rand() % (this->okno->getSize().x - 200) + 100, rand() % 800 - 1000));
		}
	}
	if (flaga == 4 && time.asSeconds() > 48) {
		flaga++;
		for (int i = 0; i < rand() % 4 + 4; i++) {
			this->asteroids.emplace_back(new Asteroid(this->textures["asteroid"], rand() % (this->okno->getSize().x - 200) + 100, rand() % 800 - 1000));
		}
	}
	if (flaga == 5 && time.asSeconds() > 52) {
		flaga++;
		if (rand() % 20 < 5) {
			for (int i = 0; i < rand() % 8 + 4; i++) {
				this->enemies.emplace_back(new Enemy(this->textures["enemy"], rand() % (this->okno->getSize().x - 200) + 100, rand() % 800 - 1000));
			}
		}
		else {
			for (int i = 0; i < rand() % 4 + 2; i++) {
				this->enemies.emplace_back(new Enemy(this->textures["enemy_2"], rand() % (this->okno->getSize().x - 200) + 100, rand() % 800 - 1000));
			}
		}
	}
	if (flaga == 6 && time.asSeconds() > 62 && this->enemies.empty() && this->enemies_2.empty() && this->asteroids.empty() && boss_enemy == nullptr) {
		koniecGry = 1;
	}
}
