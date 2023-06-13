#include<iostream>
#include<vector>
#include<map>

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
#include "Enemy_missile.h"
#include "Boom.h"
#include "Enemy.h"
#include "Bonus.h"
#include "Indicator.h"
#include "Boss.h"

#include <string>
#include <sstream>

using namespace sf;
using namespace std;

class SilnikGry
{
private:
	Vector2i mouse_pos;
	Vector2i saved_mouse_pos;
	Vector2f translated_pos;


	Event e;

	//Okno gry
	RenderWindow* okno;
	Texture textureTlo;
	Sprite spriteTlo;

	//Czas w grze
	Clock clock;
	Clock delta_clock;

	Time time;
	Time delta_time;
	float dt;

	Clock bonus_clock;

	//Zmienne kontrolne
	Clock cooldown_clock;
	Time cooldown;
	

	map<std::string, Texture*> textures;

	AnimowaneAssety* player;
	vector<AnimowaneAssety*> coins;
	vector<AnimowaneAssety*> asteroids;
	vector<AnimowaneAssety*> missiles;
	vector<AnimowaneAssety*> enemy_missiles;
	vector<AnimowaneAssety*> explosions;
	vector<AnimowaneAssety*> enemies;
	vector<AnimowaneAssety*> enemies_2;
	vector<AnimowaneAssety*> bonuses_power;
	vector<AnimowaneAssety*> bonuses_health;
	vector<AnimowaneAssety*> bonuses_x2;
	vector<AnimowaneAssety*> bonuses_rof;
	AnimowaneAssety* boss_enemy;
	

	//System
	void stworzOkno();
	void stworzTekstury();
	void stworzGui();
	void stworzObiekty();
	void stworzTlo();
	void stworzDzwieki();

	Font font;

	Text punkty;
	Text zdrowie;
	Text sila;
	Text ROF;
	Text BonusX2;
	Text pauza;
	Text wznow;
	Text wyjdz;
	Text start;
	Text latwy;
	Text trudny;
	Text napisKoncowy;

	vector<Indicator*> indicators;

	RectangleShape rectangle;
	RectangleShape HP_bar; 
	RectangleShape tloMenu;
	RectangleShape tloGlowneMenu;

	Sound sound;
	Sound sound_boom;
	Sound sound_effect;
	SoundBuffer buffer_shoot;
	SoundBuffer buffer_boom;
	SoundBuffer buffer_money;
	SoundBuffer buffer_effect;

	vector<Sound*> sounds_money;

	int HP = 100;
	int money = 0;
	int power = 1;
	int mnoznik = 1;
	int rof = 10;
	int frame;
	int flaga = 0;
	int szansa = 1; // 20 - 100%  <-- 10 - 50% -->   0 - 0%

	bool wstep = 1;
	bool koniecGry = 0;
	bool gamePaused = 0;

public:
	SilnikGry();
	virtual ~SilnikGry();

	//Funkcje
	void run();

	void updatePollEvents();
	void updateGui();
	void updateCollision();
	void update();
	void renderGui();
	void render();
	void rozgrywka();
};

