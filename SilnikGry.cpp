#include "SilnikGry.h"

void SilnikGry::stworzokno()
{
	this->okno = new RenderWindow(VideoMode(1280, 720), "Game", Style::Close | Style::Titlebar);
	this->okno->setActive(true);
	this->okno->setFramerateLimit(60);
	this->okno->setKeyRepeatEnabled(false);
	this->okno->setMouseCursorGrabbed(false);
	this->okno->setMouseCursorVisible(false);
	this->okno->setVerticalSyncEnabled(false);
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

	rectangle.setSize(sf::Vector2f(200, 20));
	rectangle.setFillColor(sf::Color::White);
	rectangle.setPosition(110, 672);
	HP_bar.setSize(sf::Vector2f(200, 20));
	HP_bar.setFillColor(sf::Color::Red);
	HP_bar.setPosition(110, 672);
}

void SilnikGry::stworzObiekty()
{
	player = new Gracz("textures/rocket.png",0,0);  //TEKSTURA GRACZA

	Vector2i start_position(this->okno->getSize().x / 2 - this->player->getBounds().width / 2,
		this->okno->getSize().y / 2 - this->player->getBounds().height / 2 + 260);

	Mouse::setPosition(start_position, *this->okno);  // TOTALNIE CZARODZIEJSKIE TAJNIKI �RODKOWANIA I POZYCJONOWANIA XD

	/*for (int i = 0; i < (rand() % 4 + 4); i++) {
		this->coins.emplace_back(new Coin("textures/coin.png", rand() % this->okno->getSize().x, rand() % (this->okno->getSize().y/3)));

		for (int j = 0; j < i; j++) {
			while (this->coins[j]->getBounds().intersects(this->coins[i]->getBounds()) || this->coins[j]->getBounds().intersects(this->player->getBounds())) {
				this->coins[i]->setPosition(rand() % this->okno->getSize().x, rand() % this->okno->getSize().y);
			}
		}
	}
	
	for (int i = 0; i < 4; i++) {
		this->asteroids.emplace_back(new Asteroid("textures/asteroid.png", rand() % this->okno->getSize().x, rand() % (this->okno->getSize().y/4)));

		for (int j = 0; j < i; j++) {
			while (this->asteroids[j]->getBounds().intersects(this->asteroids[i]->getBounds()) || this->asteroids[j]->getBounds().intersects(this->player->getBounds())) {
				this->asteroids[i]->setPosition(rand() % this->okno->getSize().x, rand() % this->okno->getSize().y);
			}
		}
	}*/
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
	/*
	if (!buffer_shoot.loadFromFile("sounds/shoot.ogg")) {
		cout << "Error: Sound not load!" << endl;
	}*/
}


SilnikGry::SilnikGry()
{
	this->stworzokno();
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
		this->update();
		this->render();
		this->rozgrywka();

		this->time = clock.getElapsedTime();
		this->cooldown = cooldown_clock.getElapsedTime();

		if (Keyboard::isKeyPressed(Keyboard::E))
		{
			stopper = 1;
			while (stopper == 1)
			{
				this->render();
				updatePollEvents();

				if (Keyboard::isKeyPressed(Keyboard::E))
				{
					stopper = 0;
				}
			}
		}
	}
}

void SilnikGry::updatePollEvents()
{
	while (this->okno->pollEvent(e))
	{
		auto mouse_pos = Mouse::getPosition(*okno);
		auto translated_pos = this->okno->mapPixelToCoords(mouse_pos);

		this->player->setPosition(translated_pos.x - this->player->getBounds().width / 2, translated_pos.y - this->player->getBounds().height / 2);

		if (e.Event::type == Event::Closed)
			this->okno->close();
		if (e.Event::KeyPressed && e.Event::key.code == Keyboard::Escape)
			this->okno->close();
		if (e.Event::KeyPressed && e.Event::key.code == Mouse::Left && Mouse::isButtonPressed(Mouse::Left) && this->cooldown.asMilliseconds() > 100) {
			this->missiles.emplace_back(new Missile("textures/missile.png", translated_pos.x - 8, translated_pos.y - this->player->getBounds().height / 2));
			sound.setBuffer(this->buffer_shoot);
			sound.play();
			this->cooldown = cooldown_clock.restart();
		}
			

	}
}

void SilnikGry::updateInput()
{
	/*if (Keyboard::isKeyPressed(Keyboard::A))
		this->gracz->move(-1.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::D))
		this->gracz->move(1.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::W))
		this->gracz->move(0.f, -1.f);
	if (Keyboard::isKeyPressed(Keyboard::S))
		this->gracz->move(0.f, 1.f);*/

	//RUCH MYSZKI
	/*auto mouse_pos = Mouse::getPosition(*okno);
	auto translated_pos = this->okno->mapPixelToCoords(mouse_pos);*/
	
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

	HP_bar.setSize(sf::Vector2f(2*(this->HP), 20));

	if (this->HP < 0) { this->HP = 0; }
}

void SilnikGry::updateCollision()
{
	/*for (auto* mis : this->missiles)
	{
		for (auto *ast : this->asteroids) {
			if (ast->getBounds().intersects(mis->getBounds())) {
				//missiles.erase(std::remove(missiles.begin(), missiles.end(), mis), missiles.end());
				//delete mis;
				asteroids.erase(std::remove(asteroids.begin(), asteroids.end(), ast), asteroids.end());
				delete ast;
				sound_boom.setBuffer(this->buffer_boom);
				sound_boom.play();
				break;
			}
		}
		if (mis->getPos().y < -20) {
			auto it = std::find(missiles.begin(), missiles.end(), mis);  //  D�U�SZA METODA
			if (it != missiles.end()) {
				missiles.erase(it);
				delete mis;
			}
			
			missiles.erase(std::remove(missiles.begin(), missiles.end(), mis), missiles.end());
			delete mis;
		}
	}*/

	for (auto ast = asteroids.begin(); ast != asteroids.end(); ) {
		bool collisionDetected = false;

		for (auto mis = missiles.begin(); mis != missiles.end(); ) {
			if ((*ast)->getBounds().intersects((*mis)->getBounds())) {
				sound_boom.setBuffer(this->buffer_boom);
				sound_boom.play();
				this->coins.emplace_back(new Coin("textures/coin.png", (*mis)->getPos().x, (*mis)->getPos().y));
				this->explosions.emplace_back(new Boom("textures/boom.png", (*ast)->getPos().x - (*ast)->getBounds().width / 2, (*ast)->getPos().y - (*ast)->getBounds().height / 2));

				// Usuni�cie obiektu z wektora asteroids
				delete* ast;
				ast = asteroids.erase(ast);
				// Usuni�cie obiektu z wektora missiles
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

	
	for (auto mis = missiles.begin(); mis != missiles.end(); ) {
        if ((*mis)->getPos().y < -20) {
            delete *mis;
            mis = missiles.erase(mis);
        } else {
            ++mis;
        }
    }

	if (time.asSeconds() > 2){
		for (auto* el : this->coins) {
			if (el->getBounds().intersects(this->player->getBounds())) {
				coins.erase(std::remove(coins.begin(), coins.end(), el), coins.end());
				delete el;
				this->money += 5;
				sound_money.setBuffer(this->buffer_money);
				sound_money.play();
			}
		}

		for (auto* ast : this->asteroids) {
			if (ast->getPos().y > 720 + ast->getBounds().height) {
				asteroids.erase(std::remove(asteroids.begin(), asteroids.end(), ast), asteroids.end());
				delete ast;
			}
			else if (ast->getBounds().intersects(this->player->getBounds())) {
				this->explosions.emplace_back(new Boom("textures/boom.png", player->getPos().x-player->getBounds().width/2, player->getPos().y - player->getBounds().height / 2));
				asteroids.erase(std::remove(asteroids.begin(), asteroids.end(), ast), asteroids.end());
				delete ast;
				this->HP -= 10;

				Vector2i start_position(this->okno->getSize().x / 2 - this->player->getBounds().width / 2,
					this->okno->getSize().y / 2 - this->player->getBounds().height / 2 + 260);
				Mouse::setPosition(start_position, *this->okno);

				sound_boom.setBuffer(this->buffer_boom);
				sound_boom.play();
			}
		}
	}
}

void SilnikGry::update()
{
	this->frame++;
	//cout << time.asSeconds() << endl;

	this->updateInput();
	this->updateGui();
	this->updateCollision();
	this->player->update();
	for (auto el : this->coins) {
		el->update();
	}
	for (auto el : this->asteroids) {
		el->update();
	}
	for (auto el : this->missiles) {
		el->update();
	}
	for (auto el : this->explosions) {
		el->update();
	}
	if (frame > 960) { frame = 0; }
	this->spriteTlo.setTextureRect(IntRect(0, 480 - int(frame / 2), 1280,720));

	for (auto asset = explosions.begin(); asset != explosions.end();) {
		// Sprawd�, czy wska�nik wskazuje na obiekt klasy Boom
		if (Boom *boom = dynamic_cast<Boom*>(*asset)) {
			if (boom->getCzas() >= boom->getCzasTrwania()) {
				asset = explosions.erase(asset);
			}
			else {
				++asset;
			}
		}
		else {
		}
	}
}

void SilnikGry::renderGui()
{
	this->okno->draw(this->punkty);
	this->okno->draw(this->zdrowie);
	this->okno->draw(this->sila);
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
	for (auto el : this->asteroids) {
		el->render(this->okno);
	}
	for (auto el : this->missiles) {
		el->render(this->okno);
	}

	this->player->render(this->okno);


	for (auto el : this->explosions) {
		el->render(this->okno);
	}

	this->renderGui();
	this->okno->display();
}

void SilnikGry::rozgrywka()
{
	if (flaga == 0 && time.asSeconds() > 1) {
		flaga++;
		for (int i = 0; i < 4; i++) {
			this->asteroids.emplace_back(new Asteroid("textures/asteroid.png", rand() % this->okno->getSize().x - 100, (rand() % this->okno->getSize().y)/4));

			
			for (int j = 0; j < i; j++) {
				while (this->asteroids[j]->getBounds().intersects(this->asteroids[i]->getBounds()) || this->asteroids[j]->getBounds().intersects(this->player->getBounds())) {
					this->asteroids[i]->setPosition(rand() % this->okno->getSize().x - 100, (rand() % this->okno->getSize().y)/4);
				}
			}
		}
	
	}
}