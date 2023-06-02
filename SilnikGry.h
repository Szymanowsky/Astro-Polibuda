#include<iostream>
#include<vector>

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include "AnimowaneAssety.h"
#include "Gracz.h"
#include "Coin.h"
#include "Asteroid.h"
#include "Missile.h"
#include "Boom.h"
#include "Enemy.h"

#include <string>
#include <sstream>

using namespace sf;
using namespace std;

class SilnikGry
{
private:
	Event e;

	//Okno gry
	RenderWindow* okno;
	Texture textureTlo;
	Sprite spriteTlo;

	//Czas w grze
	Clock clock;
	Time time;

	//Zmienne kontrolne
	Clock cooldown_clock;
	bool stopper;
	Time cooldown;
	

	AnimowaneAssety* player;
	vector<AnimowaneAssety*> coins;
	vector<AnimowaneAssety*> asteroids;
	vector<AnimowaneAssety*> missiles;
	vector<AnimowaneAssety*> explosions;
	vector<AnimowaneAssety*> enemies;

	//System
	void stworzokno();
	void stworzGui();
	void stworzObiekty();
	void stworzTlo();
	void stworzDzwieki();

	Font font;

	Text punkty;
	Text zdrowie;
	Text sila;

	RectangleShape rectangle;
	RectangleShape HP_bar;

	Sound sound;
	Sound sound_boom;
	Sound sound_money;
	SoundBuffer buffer_shoot;
	SoundBuffer buffer_boom;
	SoundBuffer buffer_money;

	int HP = 100;
	int money = 0;
	int power = 1;
	int frame;
	int flaga = 0;

public:
	SilnikGry();
	virtual ~SilnikGry();

	//Funkcje
	void run();

	void updatePollEvents();
	void updateInput();
	void updateGui();
	void updateCollision();
	void update();
	void renderGui();
	void render();
	void rozgrywka();
};

