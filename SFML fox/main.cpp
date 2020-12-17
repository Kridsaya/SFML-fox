#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <utility>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <fstream>
#include "stdlib.h"
#include "Player.h"
#include "Platform.h"
#include "Bullet.h"
#include "sun.h"
#include "Enemy.h"
#include "Bloodup.h"

using namespace std;

int bulletCheck;

int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Sunshine Fox");
	sf::View view(sf::Vector2f(1.0f, 1.0f), sf::Vector2f(1080.0f, 720.0f));

	//BGMENU1
	sf::RectangleShape bg(sf::Vector2f(1080.0f, 720.0f));
	bg.setPosition(0.0f, 0.0f);
	sf::Texture s;
	s.loadFromFile("arts/MENU bg.png");
	bg.setTexture(&s);

	//BGMENU2
	sf::RectangleShape bg1(sf::Vector2f(1080.0f, 720.0f));
	bg1.setPosition(0.0f, 0.0f);
	sf::Texture s1;
	s1.loadFromFile("arts/bt1.png");
	bg1.setTexture(&s1);

	//BGMENU3
	sf::RectangleShape bg2(sf::Vector2f(1080.0f, 720.0f));
	bg2.setPosition(0.0f, 0.0f);
	sf::Texture s2;
	s2.loadFromFile("arts/bt2.png");
	bg2.setTexture(&s2);

	//BGMENU3
	sf::RectangleShape bg3(sf::Vector2f(1080.0f, 720.0f));
	bg3.setPosition(0.0f, 0.0f);
	sf::Texture s3;
	s3.loadFromFile("arts/bt3.png");
	bg3.setTexture(&s3);

	//BGMENU4
	sf::RectangleShape bg4(sf::Vector2f(1080.0f, 720.0f));
	bg4.setPosition(0.0f, 0.0f);
	sf::Texture s4;
	s4.loadFromFile("arts/bt4.png");
	bg4.setTexture(&s4);

	//ด่าน1
	sf::RectangleShape background(sf::Vector2f(10000.0f, 720.0f));
	background.setPosition(0.0f, 0.0f);
	sf::Texture space;
	space.loadFromFile("arts/BG5.png");
	background.setTexture(&space);

	//ด่าน2
	sf::RectangleShape background1(sf::Vector2f(10000.0f, 720.0f));
	background1.setPosition(10000.0f, 0.0f);
	sf::Texture space1;
	space1.loadFromFile("arts/BG4.png");
	background1.setTexture(&space1);

	//ด่าน3
	sf::RectangleShape background2(sf::Vector2f(10000.0f, 720.0f));
	background2.setPosition(20000.0f, 0.0f);
	sf::Texture space2;
	space2.loadFromFile("arts/BG6.png");
	background2.setTexture(&space2);

	//ชนะ
	sf::RectangleShape mission(sf::Vector2f(1080.0f, 720.0f));
	mission.setPosition(0.0f, 0.0f);
	sf::Texture complete;
	complete.loadFromFile("arts/comple.png");
	mission.setTexture(&complete);

	sf::RectangleShape back1(sf::Vector2f(1080.0f, 720.0f));
	back1.setPosition(0.0f, 0.0f);
	sf::Texture backmenu1;
	backmenu1.loadFromFile("arts/back02.png");
	back1.setTexture(&backmenu1);

	sf::RectangleShape back2(sf::Vector2f(1080.0f, 720.0f));
	back2.setPosition(0.0f, 0.0f);
	sf::Texture backmenu2;
	backmenu2.loadFromFile("arts/back01.png");
	back2.setTexture(&backmenu2);

	//keyname
	sf::RectangleShape key(sf::Vector2f(1080.0f, 720.0f));
	key.setPosition(0.0f, 0.0f);
	sf::Texture kk;
	kk.loadFromFile("arts/keynamehowto.png");
	key.setTexture(&kk);

	//------------------------------------------------------------- Music & Sound ------------------------------------------------------------//
	sf::SoundBuffer sound2;
	if (!sound2.loadFromFile("arts/sound test 01.ogg"))
		return -1;

	sf::Sound Sound1;
	Sound1.setBuffer(sound2);

	//soundjump
	sf::SoundBuffer soundjump;
	soundjump.loadFromFile("arts/jump.ogg");
	sf::Sound Sound2;
	Sound2.setBuffer(soundjump);

	//soundjump
	sf::SoundBuffer soundc;
	soundc.loadFromFile("arts/whoose.WAV");
	sf::Sound Soundch;
	Soundch.setBuffer(soundc);

	//sounditemup
	sf::SoundBuffer soundup;
	soundup.loadFromFile("arts/up.ogg");
	sf::Sound SoundUp;
	SoundUp.setBuffer(soundup);

	//sounditemdown
	sf::SoundBuffer sounddown;
	sounddown.loadFromFile("arts/down.ogg");
	sf::Sound Sounddown;
	Sounddown.setBuffer(sounddown);

	//soundjump
	sf::SoundBuffer soundwrap;
	soundwrap.loadFromFile("arts/warp.ogg");
	sf::Sound Sound3;
	Sound3.setBuffer(soundwrap);

	//soundmenu
	sf::Music music;
	music.openFromFile("arts/bd music.ogg");
	music.setLoop(true);
	music.setVolume(20.f);

	//soundmap
	sf::Music music1;
	music1.openFromFile("arts/bd music.ogg");
	music1.setLoop(true);
	music1.setVolume(20.f);

	//soundover
	sf::Music musicend;
	musicend.openFromFile("arts/game over.ogg");
	musicend.setLoop(true);
	musicend.setVolume(20.f);

	//soundover
	sf::Music musicwin;
	musicwin.openFromFile("arts/win.ogg");
	musicwin.setLoop(true);
	musicwin.setVolume(50.f);

	//----------------------------------------------------------- Font -------------------------------------------------------------//
	sf::Font font;
	font.loadFromFile("arts/MilkyNice.ttf");
	std::ostringstream score;
	sf::Text Score;
	Score.setCharacterSize(30);
	Score.setString(score.str());
	Score.setFont(font);
	Score.setFillColor(sf::Color(129, 119, 95));

	//scoregame
	int countscore = 0;
	sf::Font SCORE;
	SCORE.loadFromFile("arts/MilkyNice.ttf");
	std::ostringstream score1;
	sf::Text scoregame;
	scoregame.setCharacterSize(50);
	scoregame.setString(score1.str());
	scoregame.setFont(SCORE);
	scoregame.setFillColor(sf::Color(129, 119, 95));

	//hp font
	sf::Font Hppush;
	Hppush.loadFromFile("arts/MilkyNice.ttf");
	std::ostringstream hppush;
	sf::Text Hpblood;
	Hpblood.setCharacterSize(30);
	Hpblood.setString(hppush.str());
	Hpblood.setFont(font);
	Hpblood.setFillColor(sf::Color(96, 168, 48));
	sf::Text Hpblood2;
	Hpblood2.setCharacterSize(30);
	Hpblood2.setString(hppush.str());
	Hpblood2.setFont(font);
	Hpblood2.setFillColor(sf::Color::Red);
	sf::Text bulA;
	bulA.setCharacterSize(30);
	bulA.setString(hppush.str());
	bulA.setFont(font);
	bulA.setFillColor(sf::Color::Red);
	sf::Text bulA1;
	bulA1.setCharacterSize(30);
	bulA1.setString(hppush.str());
	bulA1.setFont(font);
	bulA1.setFillColor(sf::Color::Red);
	sf::Text bulA2;
	bulA2.setCharacterSize(30);
	bulA2.setString(hppush.str());
	bulA2.setFont(font);
	bulA2.setFillColor(sf::Color::Red);
	sf::Text HighScore;
	HighScore.setCharacterSize(30);
	HighScore.setString(hppush.str());
	HighScore.setFont(font);
	HighScore.setFillColor(sf::Color(129, 119, 95));

	//Player
	sf::Texture playertexture;
	playertexture.loadFromFile("arts/fox 1.png");
	Player player(&playertexture, sf::Vector2u(3, 2), 0.3f, 150.0f, 180.0f);

	//ITEM
	//Bloodup
	sf::Texture BLOODUP;
	BLOODUP.loadFromFile("arts/bloodup.png");
	std::vector <Bloodup> BloodupVector;
	//Blooddown
	sf::Texture BLOODDOWN;
	BLOODDOWN.loadFromFile("arts/blooddown.png");
	std::vector <Bloodup> BlooddownVector;

	//endscore
	int EndScore = 0;
	sf::Text Send;
	Send.setCharacterSize(40);
	Send.setFont(font);
	Send.setFillColor(sf::Color(129, 119, 95));

	//endscorestar
	int EndNumStar = 0;
	sf::Text CSTER;
	sf::Font gameover;
	gameover.loadFromFile("arts/MilkyNice.ttf");
	CSTER.setCharacterSize(40);
	CSTER.setString(hppush.str());
	CSTER.setFont(gameover);
	CSTER.setFillColor(sf::Color(129, 119, 95));

	//newscore
	sf::Text NewScore;
	NewScore.setCharacterSize(60);
	NewScore.setString(hppush.str());
	NewScore.setFont(font);
	NewScore.setFillColor(sf::Color(129, 119, 95));

	//HPbar
	sf::Texture HPbar;
	HPbar.loadFromFile("arts/hp bar.png");
	sf::Sprite hpbar;
	hpbar.setTexture(HPbar);
	hpbar.setPosition(300, -100);

	sf::Texture load;
	load.loadFromFile("arts/keynameload.png");
	sf::RectangleShape ll(sf::Vector2f(1080, 720));
	ll.setPosition(sf::Vector2f(0, 0));
	ll.setTexture(&load); 

	float MyHP = 78000;
	hpbar.setTexture(HPbar);
	sf::RectangleShape HP(sf::Vector2f(MyHP / 250.0f, 30));
	HP.setPosition(sf::Vector2f(450, 46));
	HP.setFillColor(sf::Color::White);
	HP.setSize(sf::Vector2f(MyHP / 320.f, 15));

	float Downlaod = 0;
	sf::RectangleShape DL(sf::Vector2f(Downlaod / 50.0f, 20));
	DL.setPosition(sf::Vector2f(285, 647.5f));
	DL.setFillColor(sf::Color::White);
	DL.setSize(sf::Vector2f(Downlaod / 150.f, 19));

	sf::Texture LOAD;
	LOAD.loadFromFile("arts/load.png");
	sf::RectangleShape LL(sf::Vector2f(1080, 720));
	LL.setPosition(sf::Vector2f(0, 0));
	LL.setTexture(&LOAD);

	//item
	sf::Texture SUN;
	SUN.loadFromFile("arts/Sunshine 001.png");
	std::vector <sun*> starVector;

	//Alien
	sf::Texture alien;
	alien.loadFromFile("arts/Ghost 01.png");
	std::vector <Enemy> alienVector;

	sf::Texture alien1;
	alien1.loadFromFile("arts/Ghost 02.png");
	std::vector <Enemy> alien1Vector;

	sf::Texture alien2;
	alien2.loadFromFile("arts/Ghost 02.png");
	std::vector <Enemy> alien2Vector;

	sf::Texture alienamong1;
	alienamong1.loadFromFile("arts/Ghost 01.png");
	std::vector <Enemy> alienamong1Vector;

	sf::Texture alienamong2;
	alienamong2.loadFromFile("arts/Ghost 01.png");
	std::vector <Enemy> alienamong2Vector;

	//Bullet
	sf::Texture BULLET;
	BULLET.loadFromFile("arts/Sunshine 001.png");
	Bullet bullet1(&BULLET, sf::Vector2u(2, 1), 0.15f, 600.0f, player.GetPosition());

	//Platform
	std::vector<Platform> platforms;
	
	//ด่าน1
	platforms.push_back(Platform(nullptr, sf::Vector2f(160.0f, 120.0f), sf::Vector2f(716.0f, 600.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(340.0f, 390.0f), sf::Vector2f(910.0f, 600.0f)));

	platforms.push_back(Platform(nullptr, sf::Vector2f(220.0f, 120.0f), sf::Vector2f(2020.0f, 600.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(600.0f, 320.0f), sf::Vector2f(2360.0f, 600.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(180.0f, 590.0f), sf::Vector2f(2230.0f, 600.0f)));

	platforms.push_back(Platform(nullptr, sf::Vector2f(560.0f, 570.0f), sf::Vector2f(3570.0f, 600.0f)));

	platforms.push_back(Platform(nullptr, sf::Vector2f(160.0f, 120.0f), sf::Vector2f(5150.0f, 600.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(340.0f, 390.0f), sf::Vector2f(5350.0f, 600.0f)));

	platforms.push_back(Platform(nullptr, sf::Vector2f(240.0f, 120.0f), sf::Vector2f(6470.0f, 600.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(660.0f, 320.0f), sf::Vector2f(6760.0f, 600.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 590.0f), sf::Vector2f(6620.0f, 600.0f)));

	platforms.push_back(Platform(nullptr, sf::Vector2f(560.0f, 570.0f), sf::Vector2f(8010.0f, 600.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(340.0f, 390.0f), sf::Vector2f(7740.0f, 600.0f)));
		//ลอย
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 30.072f), sf::Vector2f(2822.00f, 330.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 30.072f), sf::Vector2f(2996.00f, 260.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 30.072f), sf::Vector2f(7255.00f, 330.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 30.072f), sf::Vector2f(7430.00f, 260.0f)));

		//พืน
	platforms.push_back(Platform(nullptr, sf::Vector2f(10000.0f, 100.0f), sf::Vector2f(1250.0f, 700.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 100.0f), sf::Vector2f(3650.0f, 700.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1500.0f, 100.0f), sf::Vector2f(4100.0f, 700.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(2000.0f, 100.0f), sf::Vector2f(5100.0f, 700.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(10000.0f, 100.0f), sf::Vector2f(8800.0f, 700.0f))); 
/*	platforms.push_back(Platform(nullptr, sf::Vector2f(325.0f, 220.0f), sf::Vector2f(1000.0f, 400.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(260.0f, 360.0f), sf::Vector2f(2080.0f, 400.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(240.0f, 30.0f), sf::Vector2f(1955.0f, 400.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(270.0f, 170.0f), sf::Vector2f(2350.0f, 400.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(505.0f, 350.0f), sf::Vector2f(3280.0f, 400.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(505.0f, 220.0f), sf::Vector2f(3100.0f, 400.0f)));

	platforms.push_back(Platform(nullptr, sf::Vector2f(5120.0f, 90.0f), sf::Vector2f(7500.0f, 450.0f)));

	//Platform for ปิดหัวท้าย
	platforms.push_back(Platform(nullptr, sf::Vector2f(20.0f, 520.0f), sf::Vector2f(5130.0f, 256.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(20.0f, 520.0f), sf::Vector2f(-10.0f, 256.0f))); */

	//map2
	//platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 687.072f), sf::Vector2f(11700.0f, 143.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(700.0f, 50.0f), sf::Vector2f(12900.0f, 490.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 100.0f), sf::Vector2f(16693.0f, 250.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(82.0f, 90.0f), sf::Vector2f(14793.0f, 550.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(700.0f, 20.0f), sf::Vector2f(17500.0f, 480.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(140.0f, 20.0f), sf::Vector2f(15790.0f, 470.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 20.0f), sf::Vector2f(16100.0f, 450.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(500.0f, 50.0f), sf::Vector2f(16700.0f, 355.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 687.072f), sf::Vector2f(14050.00f, 143.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(2500.0f, 100.0f), sf::Vector2f(11250.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(800.0f, 100.0f), sf::Vector2f(13650.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1500.0f, 100.0f), sf::Vector2f(14100.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1090.0f, 100.0f), sf::Vector2f(15100.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(2000.0f, 100.0f), sf::Vector2f(18800.0f, 670.0f)));

	//map3
	//platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 687.072f), sf::Vector2f(21700.0f, 143.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(700.0f, 20.0f), sf::Vector2f(22900.0f, 450.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 20.0f), sf::Vector2f(25700.0f, 450.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 20.0f), sf::Vector2f(26100.0f, 450.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(500.0f, 50.0f), sf::Vector2f(26700.0f, 365.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 687.072f), sf::Vector2f(24050.00f, 143.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(2500.0f, 100.0f), sf::Vector2f(21250.0f, 670.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(800.0f, 100.0f), sf::Vector2f(23650.0f, 670.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(1500.0f, 100.0f), sf::Vector2f(24100.0f, 670.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(1090.0f, 100.0f), sf::Vector2f(25100.0f, 670.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(4000.0f, 100.0f), sf::Vector2f(29000.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(10000.0f, 100.0f), sf::Vector2f(25000.0f, 670.0f)));

	sf::Texture doorwarp;
	doorwarp.loadFromFile("arts/gate1.png");

	sf::Texture doorwarp1;
	doorwarp1.loadFromFile("arts/gate2.png");

	//เปลี่ยนด่าน
	sf::RectangleShape warpPoint(sf::Vector2f(400, 200));
	warpPoint.setPosition(sf::Vector2f(9221.67, 320));
	warpPoint.setTexture(&doorwarp);

	sf::RectangleShape warpPoint1(sf::Vector2f(400, 400));
	warpPoint1.setPosition(sf::Vector2f(18805, 220));
	warpPoint1.setTexture(&doorwarp1);

	//starup
	sf::Texture starup;
	starup.loadFromFile("arts/sun.png");
	sf::RectangleShape starPoint(sf::Vector2f(50, 50));
	starPoint.setPosition(sf::Vector2f(80, 80));
	starPoint.setTexture(&starup);

	//pause
	sf::Texture pause;
	pause.loadFromFile("arts/pause test.png");
	sf::RectangleShape pp(sf::Vector2f(1080, 720));
	pp.setTexture(&pause);

	//pauseresume
	sf::Texture pauseresume;
	pauseresume.loadFromFile("arts/pm resume.png");
	sf::RectangleShape pr(sf::Vector2f(1080, 720));
	pr.setTexture(&pauseresume);

	//pausemenu
	sf::Texture pausemenu;
	pausemenu.loadFromFile("arts/pm menu.png");
	sf::RectangleShape pm(sf::Vector2f(1080, 720));
	pm.setTexture(&pausemenu);

	//pauseexit
	sf::Texture pauseexit;
	pauseexit.loadFromFile("arts/pm exit.png");
	sf::RectangleShape pe(sf::Vector2f(1080, 720));
	pe.setTexture(&pauseexit);

	//End
	sf::Texture end;
	end.loadFromFile("arts/g over.png");
	sf::RectangleShape ee(sf::Vector2f(1080, 720));
	ee.setTexture(&end);

	sf::Texture High;
	High.loadFromFile("arts/highscore1.png");
	sf::RectangleShape hh(sf::Vector2f(1080, 720));
	hh.setTexture(&High);

	sf::Texture backHigh;
	backHigh.loadFromFile("arts/back01.png");
	sf::RectangleShape bh(sf::Vector2f(1080, 720));
	bh.setTexture(&High);

	sf::String playerInput;
	std::ofstream fileWriter;
	std::ostringstream keyname;
	sf::Text Keyname;
	Keyname.setCharacterSize(40);
	Keyname.setString(" ");
	Keyname.setFont(font);
	Keyname.setFillColor(sf::Color::White);

	int i = 0;
	int q = 0;
	int Bul = 0;
	int count = 0;
	int state = 0;
	int countloop = 0;
	int soundcount = 0;

	float deltaTime = 0.0f;
	float countTimeAdd = 0;
	float countTimeSub = 0;
	float countTimeBul = 0;
	float countTimeBul1 = 0;
	float countTimeBul2 = 0;
	float countTimex2 = 0;

	sf::Clock clock;
	sf::Clock timerpausemenu;
	sf::Clock timer;
	sf::Clock timercoli;

	bool slide;
	bool checkdraw = false;
	bool checkmap1 = false;
	bool checkmap2 = false;
	bool checkcoli = false;
	bool checkBul1 = false;
	bool checkBul2 = false;
	bool checkAdd = false;
	bool checkSub = false;
	bool checkBul = false;
	bool checkx2 = false;
	bool Cload = false;
	bool START = true;
	bool MENU = true;
	bool Rank = false;
	bool SCORE1 = true;
	bool endGame = false;
	bool MemScore = false;
	bool sound_over = false;
	bool checkpause = false;
	bool cheakhighscore = false;

	std::map<int, std::string> keepscore;
	std::ifstream fileReader;
	std::string word;

	/*Modify textbox*/
	char last_char = ' ';
	sf::RectangleShape cursor;
	cursor.setSize(sf::Vector2f(5.0f, 30.0f));
	cursor.setOrigin(sf::Vector2f(2.5f, 15.0f));
	cursor.setFillColor(sf::Color::Black);
	sf::Text text("", font);
	Keyname.setPosition(300, 500);
	text.setFillColor(sf::Color::White);
	text.setPosition(545, 535);
	cursor.setPosition(545.0f + text.getGlobalBounds().width + 10, 555.0f);
	float totalTime_cursor = 0;
	sf::Clock clock_cursor;
	bool state_cursor = false;

	std::string user_name = "";
	fstream myFile;

	while (window.isOpen())
	{
		music.play();
		while (MENU == true)
		{
			sf::Event event;
			while (window.pollEvent(event)) {
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
			sf::Vector2f mouesPosition = sf::Vector2f(0.0f, 0.0f);
			mouesPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			//cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y  << endl;

			deltaTime = clock.restart().asSeconds();
			if (cheakhighscore == false) {
				window.draw(bg);
				window.draw(bg1);
			}
			if (sf::Mouse::getPosition(window).x >= 427 &&
				sf::Mouse::getPosition(window).y >= 275 &&
				sf::Mouse::getPosition(window).x <= 660 &&
				sf::Mouse::getPosition(window).y <= 348)
			{
				window.draw(bg2);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					Soundch.play();
					MENU = false;
					START = false;
					MemScore = true;
				}
			}
			else if (sf::Mouse::getPosition(window).x >= 427 &&
				sf::Mouse::getPosition(window).y >= 395 &&
				sf::Mouse::getPosition(window).x <= 660 &&
				sf::Mouse::getPosition(window).y <= 466)
			{
				window.draw(bg3);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (timerpausemenu.getElapsedTime().asSeconds() >= 0.3))
				{
					Soundch.play();
					MENU = false;
					START = false;
					Rank = true;
				}
			}
			else if (sf::Mouse::getPosition(window).x >= 427 &&
				sf::Mouse::getPosition(window).y >= 515 &&
				sf::Mouse::getPosition(window).x <= 660 &&
				sf::Mouse::getPosition(window).y <= 584)
			{
				window.draw(bg4);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					Soundch.play();
					window.close();
					break;
				}
			}
			window.display();
		}
		while (Rank == true) {

			if (countloop == 0) {
				view.setCenter(540, 360);
			}
			sf::Vector2f mouesPosition = sf::Vector2f(0.0f, 0.0f);
			mouesPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << endl;

			window.clear();
			window.draw(hh);
			sf::Text text1("", font);
			text1.setCharacterSize(30);
			text1.setFillColor(sf::Color(129, 119, 95));
			fileReader.open("data/highscore.txt");
			do {
				fileReader >> word;
				std::string first_token = word.substr(0, word.find(','));
				int second_token = std::stoi(word.substr(word.find(',') + 1, word.length()));
				keepscore[second_token] = first_token;
			} while (fileReader.good());
			fileReader.close();
			std::map<int, std::string>::iterator end = keepscore.end();
			std::map<int, std::string>::iterator beg = keepscore.begin();
			end--;
			beg--;
			int currentDisplay = 0;
			for (std::map<int, std::string>::iterator it = end; it != beg; it--) {
				text1.setString(it->second);
				text1.setPosition(view.getCenter().x - 170, 210 + 80 * currentDisplay);
				window.draw(text1);
				text1.setString(std::to_string(it->first));
				text1.setPosition(view.getCenter().x + 95, 210 + 80 * currentDisplay);
				window.draw(text1);
				currentDisplay++;
				if (currentDisplay == 5)
				{
					break;
				}
			}
			if (sf::Mouse::getPosition(window).x >= 416 &&
				sf::Mouse::getPosition(window).y >= 636 &&
				sf::Mouse::getPosition(window).x <= 665 &&
				sf::Mouse::getPosition(window).y <= 685)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Soundch.play();
					Rank = false;
					MENU = true;
				}
			}
			window.display();
		}

		while (MemScore == true) {

			countTimeAdd += deltaTime;
			sf::Event event;
			while (window.pollEvent(event)) {
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}

			if (event.type == sf::Event::TextEntered && last_char != event.text.unicode)
			{
				if (event.text.unicode == 13) { //enter
					user_name = playerInput;
					playerInput.clear();
					MENU = true;
				}
				else if (event.text.unicode == 8 && playerInput.getSize() > 0) { // backspace delete
					playerInput = playerInput.substring(0, playerInput.getSize() - 1);
				}
				else {
					if (playerInput.getSize() < 10) {
						if (countTimeAdd > 0.2) {
							playerInput += event.text.unicode;
							countTimeAdd = 0;
						}
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					MENU = false;
					Rank = false;
					Cload = true;
					soundcount = 0;
				}
				last_char = event.text.unicode;
				text.setString(playerInput);
				cursor.setPosition(545.0f + text.getGlobalBounds().width + 10, 555.0f);
			}
			else if (event.type == sf::Event::EventType::KeyReleased && last_char != ' ') {
				last_char = ' ';
			}
			window.clear();
			window.draw(key);
			window.draw(Keyname);

			totalTime_cursor += clock_cursor.restart().asSeconds();
			if (totalTime_cursor >= 0.5) {
				totalTime_cursor = 0;
				state_cursor = !state_cursor;
			}
			if (state_cursor == true) {
				window.draw(cursor);
			}
			window.draw(text);
			if (Cload == true) {
				window.draw(ll);
				window.draw(LL);
				Downlaod += 95;
				DL.setSize(sf::Vector2f(Downlaod / 150.f, 19));
				window.draw(DL);
				if (Downlaod > 80000) {
					Downlaod = 80000;
					MemScore = false;
					START = true;
					music1.play();
					Cload = false;
				}
			}
			window.display();
		}

		deltaTime = 0;
		clock.restart();
		cout << user_name << endl;

		Downlaod = 0;
		MyHP = 78000;
		state = 0;
		EndNumStar = 0;
		//Dog rakai(&DOGRAKAI, sf::Vector2u(4, 9), 0.15f, player.GetPosition());

		//star
		//map1
		for (int posi = 0; posi < 200; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 800.0f + posi, 350.0f));
		}
		for (int posi = 0; posi < 700; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 1200.0f + posi, 500.0f));
		}
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 2850.0f, 220.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 2900.0f, 200.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 2950.0f, 180.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 3000.0f, 200.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 3050.0f, 220.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 3100.0f, 270.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 3150.0f, 270.0f));
		for (int posi = 0; posi < 1000; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 1.08f, 4000.0f + posi, 550.0f));
		}
		/*for (int posi = 0; posi < 900; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 4700.0f + posi, 550.0f));
		} */
		/*starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 5743.0f, 370.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 5770.0f, 330.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 5800.0f, 290.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 5850.0f, 260.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 5900.0f, 240.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 5950.0f, 260.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 6000.0f, 290.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 6030.0f, 330.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 6070.0f, 370.0f)); */
		for (int posi = 0; posi < 350; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 6570.0f + posi, 265.0f));
		}
		/*starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 6167.0f, 370.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 6180.0f, 340.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 6210.0f, 310.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 6250.0f, 305.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 6300.0f, 280.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 6340.0f, 250.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 6400.0f, 280.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 6451.0f, 310.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 6340.0f, 290.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 6400.0f, 280.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 6451.0f, 280.0f)); */
		for (int posi = 0; posi < 600; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 7250.0f + posi, 200.0f));
		}
		for (int posi = 0; posi < 1000; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 8500.0f + posi, 550.0f));
		}

		//map2
		for (int posi = 0; posi < 1550; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 10800.0f + posi, 550.0f));
		}
		for (int posi = 0; posi < 200; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 12630.0f + posi, 370.0f));
		}
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 12850.0f, 320.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 12900.0f, 300.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 12950.0f, 280.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 13000.0f, 300.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 13050.0f, 320.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 13100.0f, 370.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 13150.0f, 370.0f));
		for (int posi = 0; posi < 1200; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 13500.0f + posi, 550.0f));
		}
		for (int posi = 0; posi < 400; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 15124.0f + posi, 550.0f));
		}
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 15743.0f, 370.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 15770.0f, 330.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 15800.0f, 290.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 15850.0f, 260.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 15900.0f, 240.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 15950.0f, 260.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 16000.0f, 290.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 16030.0f, 330.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 16070.0f, 370.0f));
		for (int posi = 0; posi < 350; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 16570.0f + posi, 265.0f));
		}
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 16167.0f, 370.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 16180.0f, 340.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 16210.0f, 310.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 16250.0f, 300.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 16300.0f, 280.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 16400.0f, 280.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 16451.0f, 310.0f));
		//starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 16340.0f, 290.0f));
		//starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 16400.0f, 280.0f));
		//starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 16451.0f, 280.0f));
		for (int posi = 0; posi < 600; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 17250.0f + posi, 370.0f));
		}
		for (int posi = 0; posi < 650; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 18012.0f + posi, 550.0f));
		}

		//map3
		for (int posi = 0; posi < 1550; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 20800.0f + posi, 550.0f));
		}
		for (int posi = 0; posi < 200; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 22630.0f + posi, 370.0f));
		}
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 22850.0f, 520.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 22900.0f, 500.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 22950.0f, 480.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 23000.0f, 500.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 23050.0f, 520.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 23100.0f, 570.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 23150.0f, 590.0f));
		for (int posi = 0; posi < 1300; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 23500.0f + posi, 550.0f));
		}
		for (int posi = 0; posi < 500; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 24700.0f + posi, 550.0f));
		}
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 25743.0f, 570.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 25770.0f, 530.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 25800.0f, 490.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 25850.0f, 460.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 25900.0f, 440.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 25950.0f, 460.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 26000.0f, 490.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 26030.0f, 530.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 26070.0f, 570.0f));

		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 26167.0f, 570.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 26180.0f, 540.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 26210.0f, 510.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 26250.0f, 500.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 26300.0f, 480.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 26340.0f, 450.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 26400.0f, 430.0f));
		for (int posi = 0; posi < 350; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 26570.0f + posi, 550.0f));
		}
		for (int posi = 0; posi < 1500; posi += 60) {
			starVector.push_back(new sun(&SUN, sf::Vector2u(2, 1), 0.08f, 27365.0f + posi, 550.0f));
		}
		/*starVector.push_back(new sun(&SUN, sf::Vector2u(9, 1), 0.08f, 6451.0f, 310.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(9, 1), 0.08f, 6340.0f, 290.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(9, 1), 0.08f, 6400.0f, 280.0f));
		starVector.push_back(new sun(&SUN, sf::Vector2u(9, 1), 0.08f, 6451.0f, 280.0f));*/

		//ghost
		alienVector.push_back(Enemy(&alien, sf::Vector2u(2, 1), 1.00f, 90.0f, 108.0f, rand() % 50 + 2331.0f, -10.0f));
		alienVector.push_back(Enemy(&alien, sf::Vector2u(2, 1), 1.00f, 90.0f, 108.0f, rand() % 50 + 3071.0f, -10.0f));
		alienVector.push_back(Enemy(&alien, sf::Vector2u(2, 1), 1.00f, 90.0f, 108.0f, rand() % 50 + 5337.0f, -10.0f));
		alienVector.push_back(Enemy(&alien, sf::Vector2u(2, 1), 1.00f, 90.0f, 108.0f, rand() % 50 + 6815.0f, -10.0f));
		alienVector.push_back(Enemy(&alien, sf::Vector2u(2, 1), 1.00f, 90.0f, 108.0f, rand() % 50 + 8928.0f, -10.0f));
		
		alien1Vector.push_back(Enemy(&alien1, sf::Vector2u(2, 1), 1.08f, 90.0f, 108.0f, rand() % 50 + 11580.0f, -10.0f));
		alien1Vector.push_back(Enemy(&alien1, sf::Vector2u(2, 1), 1.08f, 90.0f, 108.0f, rand() % 50 + 15504.0f, -10.0f));
		alien1Vector.push_back(Enemy(&alien1, sf::Vector2u(2, 1), 1.08f, 90.0f, 108.0f, rand() % 50 + 16943.0f, -10.0f));

		alien2Vector.push_back(Enemy(&alien2, sf::Vector2u(2, 1), 1.08f, 90.0f, 108.0f, rand() % 50 + 22955.0f, -10.0f));
		alien2Vector.push_back(Enemy(&alien2, sf::Vector2u(2, 1), 1.08f, 90.0f, 108.0f, rand() % 50 + 25416.0f, -10.0f));
		alien2Vector.push_back(Enemy(&alien2, sf::Vector2u(2, 1), 1.08f, 90.0f, 108.0f, rand() % 50 + 26000.0f, -10.0f));
		alien2Vector.push_back(Enemy(&alien2, sf::Vector2u(2, 1), 1.08f, 90.0f, 108.0f, rand() % 50 + 26500.0f, -10.0f));
		alien2Vector.push_back(Enemy(&alien2, sf::Vector2u(2, 1), 1.08f, 90.0f, 108.0f, rand() % 50 + 27000.0f, -10.0f));
		alien2Vector.push_back(Enemy(&alien2, sf::Vector2u(2, 1), 1.08f, 90.0f, 108.0f, rand() % 50 + 27500.0f, -10.0f));
		alien2Vector.push_back(Enemy(&alien2, sf::Vector2u(2, 1), 1.08f, 90.0f, 108.0f, rand() % 50 + 28000.0f, -10.0f));
		alien2Vector.push_back(Enemy(&alien2, sf::Vector2u(2, 1), 1.08f, 90.0f, 108.0f, rand() % 50 + 28500.0f, -10.0f));
		
		alienamong1Vector.push_back(Enemy(&alienamong1, sf::Vector2u(2, 1), 1.3f, 80.0f, 98.0f, 25697.0f, -10.0f));
		alienamong1Vector.push_back(Enemy(&alienamong1, sf::Vector2u(2, 1), 1.3f, 80.0f, 98.0f, 27753.0f, -10.0f));
		alienamong1Vector.push_back(Enemy(&alienamong1, sf::Vector2u(2, 1), 1.3f, 80.0f, 98.0f, 22653.0f, -10.0f));
		alienamong1Vector.push_back(Enemy(&alienamong1, sf::Vector2u(2, 1), 1.3f, 80.0f, 98.0f, 28562.0f, -10.0f));
		alienamong1Vector.push_back(Enemy(&alienamong1, sf::Vector2u(2, 1), 1.3f, 80.0f, 98.0f, 21460.0f, -10.0f));

		alienamong2Vector.push_back(Enemy(&alienamong2, sf::Vector2u(2, 1), 1.3f, 80.0f, 98.0f, 15697.0f, -10.0f));
		alienamong2Vector.push_back(Enemy(&alienamong2, sf::Vector2u(2, 1), 1.3f, 80.0f, 98.0f, 17753.0f, -10.0f));
		alienamong2Vector.push_back(Enemy(&alienamong2, sf::Vector2u(2, 1), 1.3f, 80.0f, 98.0f, 12653.0f, -10.0f));
		alienamong2Vector.push_back(Enemy(&alienamong2, sf::Vector2u(2, 1), 1.3f, 80.0f, 98.0f, 18562.0f, -10.0f));

		//bloodup
		BloodupVector.push_back(Bloodup(&BLOODUP, sf::Vector2u(1, 1), 0.08f, 3456.0f, 180.0f));
		BloodupVector.push_back(Bloodup(&BLOODUP, sf::Vector2u(1, 1), 0.08f, 8474.0f, 540.0f));
		BloodupVector.push_back(Bloodup(&BLOODUP, sf::Vector2u(1, 1), 0.08f, 12033.0f, 370.0f));
		BloodupVector.push_back(Bloodup(&BLOODUP, sf::Vector2u(1, 1), 0.08f, 14818.0f, 390.0f));
		BloodupVector.push_back(Bloodup(&BLOODUP, sf::Vector2u(1, 1), 0.08f, 23532.0f, 470.0f));
		BloodupVector.push_back(Bloodup(&BLOODUP, sf::Vector2u(1, 1), 0.08f, 27265.0f, 480.0f));
		BloodupVector.push_back(Bloodup(&BLOODUP, sf::Vector2u(1, 1), 0.08f, 2740.0f, 280.0f));
		BloodupVector.push_back(Bloodup(&BLOODUP, sf::Vector2u(1, 1), 0.08f, 6122.9f, 365.0f));
		BloodupVector.push_back(Bloodup(&BLOODUP, sf::Vector2u(1, 1), 0.08f, 10728.0f, 545.0f));
		BloodupVector.push_back(Bloodup(&BLOODUP, sf::Vector2u(1, 1), 0.08f, 18198.0f, 545.0f));
		BloodupVector.push_back(Bloodup(&BLOODUP, sf::Vector2u(1, 1), 0.08f, 22663.0f, 365.0f));

		//blooddown
		BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(1, 1), 0.08f, 2192.0f, 230.0f));
		BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(1, 1), 0.08f, 3249.0f, 370.0f));
		BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(1, 1), 0.08f, 6840.0f, 280.0f));
		BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(1, 1), 0.08f, 4655.0f, 545.0f));
		BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(1, 1), 0.08f, 8003.0f, 200.0f));
		
		BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(1, 1), 0.08f, 14090.0f, 545.0f));
		BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(1, 1), 0.08f, 12527.0f, 350.0f));
		BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(1, 1), 0.08f, 15540.0f, 345.0f));
		BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(1, 1), 0.08f, 16473.0f, 280.0f));
		
		BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(1, 1), 0.08f, 22500.0f, 545.0f));
		BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(1, 1), 0.08f, 25206.0f, 545.0f));
		BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(1, 1), 0.08f, 27200.0f, 545.0f));
		BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(1, 1), 0.08f, 25900.0f, 420.0f));
		BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(1, 1), 0.08f, 21981.0f, 470.0f));
		BlooddownVector.push_back(Bloodup(&BLOODDOWN, sf::Vector2u(1, 1), 0.08f, 26445.0f, 480.0f));

		while (START == true) {

			//std::cout << "player pos :" << player.GetPosition().y << std::endl;
			music.pause();
			slide = false;
			count = 10;
			deltaTime = clock.restart().asSeconds();
			sf::Vector2f pos = player.GetPosition();
			std::cout << pos.x << ' ' << pos.y << '\n';
			sf::Vector2f mouesPosition = sf::Vector2f(0.0f, 0.0f);
			mouesPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			//std::cout << mouesPosition.x << ' ' << mouesPosition.y << '\n';

			if ((checkpause == false && endGame == false) && state != 3) {
				player.update(deltaTime, starVector);
				//rakai.update(deltaTime, player, player.GetPosition());
			} 
			sf::Event event;
			while (window.pollEvent(event)) {
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
			//Star
			for (int i = 0; i < starVector.size(); i++) {
				starVector[i]->update(deltaTime);
			} 
			//Bloodup
			for (int i = 0; i < BloodupVector.size(); i++) {
				BloodupVector[i].update(deltaTime, player);
			}
			//Blooddown
			for (int i = 0; i < BlooddownVector.size(); i++) {
				BlooddownVector[i].update(deltaTime, player);
			}

			//Alien
			for (int i = 0; i < alienVector.size(); i++) {
				alienVector[i].update1(deltaTime, bullet1);
				if (checkpause == false) {
					alienVector[i].update2(deltaTime, player);
				}
			}
			for (int i = 0; i < alien1Vector.size(); i++) {
				alien1Vector[i].update1(deltaTime, bullet1);
				if (checkpause == false) {
					alien1Vector[i].update2(deltaTime, player);
				}
			}
			for (int i = 0; i < alien2Vector.size(); i++) {
				alien2Vector[i].update1(deltaTime, bullet1);
				if (checkpause == false) {
					alien2Vector[i].update2(deltaTime, player);
				}
			}
			for (int i = 0; i < alienamong1Vector.size(); i++) {
				alienamong1Vector[i].updateamong1(deltaTime, bullet1);
				if (checkpause == false) {
					alienamong1Vector[i].updateamong2(deltaTime, player);
				}
			}
			for (int i = 0; i < alienamong2Vector.size(); i++) {
				alienamong2Vector[i].updateamong1(deltaTime, bullet1);
				if (checkpause == false) {
					alienamong2Vector[i].updateamong2(deltaTime, player);
				}
			}
			sf::Vector2f direction;
			for (Platform& platform : platforms)
				if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f)) {
					player.OnCollision(direction);
				}
			for (i = 0; i < alienVector.size(); i++) {
				for (Platform& platform : platforms)
					if (platform.GetCollider().CheckCollision(alienVector[i].GetCollider(), direction, 1.0f)) {
						alienVector[i].OnCollision(direction);
					}
			}
			for (i = 0; i < alien1Vector.size(); i++) {
				for (Platform& platform : platforms)
					if (platform.GetCollider().CheckCollision(alien1Vector[i].GetCollider(), direction, 1.0f)) {
						alien1Vector[i].OnCollision(direction);
					}
			}
			for (i = 0; i < alien2Vector.size(); i++) {
				for (Platform& platform : platforms)
					if (platform.GetCollider().CheckCollision(alien2Vector[i].GetCollider(), direction, 1.0f)) {
						alien2Vector[i].OnCollision(direction);
					}
			}
			for (i = 0; i < alienamong1Vector.size(); i++) {
				for (Platform& platform : platforms)
					if (platform.GetCollider().CheckCollision(alienamong1Vector[i].GetCollider(), direction, 1.0f)) {
						alienamong1Vector[i].OnCollision(direction);
					}
			}
			for (i = 0; i < alienamong2Vector.size(); i++) {
				for (Platform& platform : platforms)
					if (platform.GetCollider().CheckCollision(alienamong2Vector[i].GetCollider(), direction, 1.0f)) {
						alienamong2Vector[i].OnCollision(direction);
					}
			}

			score1.str(" ");
			score1 << "SCORE :  " << int(pos.x - 200);
			EndScore = int(pos.x - 200);
			EndNumStar = player.getNumStar();
			scoregame.setPosition({ 40,30 });
			scoregame.setString(score1.str());

			view.setCenter(player.GetPosition().x, 360.0f);
			if (view.getCenter().x - 540.0f <= 0.0f) {
				view.setCenter(540.0f, 360.0f);
			}
			if (view.getCenter().x + 540.0f >= 30000.0f) {
				view.setCenter(29460.0f, 360.0f);
			}


			hpbar.setPosition(view.getCenter().x - 10, -90);
			HP.setPosition(view.getCenter().x + 160, 56);
			Score.setPosition(view.getCenter().x - 485, 95);
			scoregame.setPosition(view.getCenter().x - 510, 30);
			starPoint.setPosition(view.getCenter().x - 480, 88);


			//Score
			score.str(" ");
			score << "      " << player.getNumStar();
			Score.setString(score.str());

			//
			hppush.str(" ");
			hppush << "  " << EndScore;
			Send.setString(hppush.str());

			hppush.str(" ");
			hppush << "  " << EndNumStar;
			CSTER.setString(hppush.str());

			hppush.str(" ");
			hppush << "  " << EndScore + EndNumStar;
			NewScore.setString(hppush.str());

			//Alien
			for (i = 0; i < alienVector.size(); i++) {
				if (alienVector[i].colAlien() == 2) {
					MyHP -= 10000;
					HP.setSize(sf::Vector2f(MyHP / 320.f, 15));
					checkcoli = true;
					q = 0;
				}
			}
			for (i = 0; i < alien1Vector.size(); i++) {
				if (alien1Vector[i].colAlien() == 2) {
					MyHP -= 10000;
					HP.setSize(sf::Vector2f(MyHP / 320.f, 15));
					checkcoli = true;
					q = 0;
				}
			}
			for (i = 0; i < alien2Vector.size(); i++) {
				if (alien2Vector[i].colAlien() == 2) {
					MyHP -= 10000;
					HP.setSize(sf::Vector2f(MyHP / 320.f, 15));
					checkcoli = true;
					q = 0;
				}
			}

			for (i = 0; i < alienamong1Vector.size(); i++) {
				if (alienamong1Vector[i].colAlien() == 2) {
					MyHP -= 5000;
					HP.setSize(sf::Vector2f(MyHP / 320.f, 15));
					checkcoli = true;
					q = 0;
				}
			}
			for (i = 0; i < alienamong2Vector.size(); i++) {
				if (alienamong2Vector[i].colAlien() == 2) {
					MyHP -= 5000;
					HP.setSize(sf::Vector2f(MyHP / 320.f, 15));
					checkcoli = true;
					q = 0;
				}
			}
			//Bloodup
			for (i = 0; i < BloodupVector.size(); i++) {
				if (BloodupVector[i].colBloodup() == 1) {
					MyHP += 1000;
					HP.setSize(sf::Vector2f(MyHP / 320.f, 15));
					if (MyHP > 78000) MyHP = 78000;
					hppush.str(" ");
					hppush << "+5000 HP";
					Hpblood.setString(hppush.str());
					Hpblood.setPosition({ player.GetPosition().x , player.GetPosition().y - 90 });
					SoundUp.play();
					checkAdd = true;
				}
			}
			if (checkAdd == true) {
				countTimeAdd += deltaTime;
				if (countTimeAdd > 0.75) {
					Hpblood.setPosition({ -800, 350 });
					countTimeAdd = 0;
					checkAdd = false;
				}
			}
			//Blooddown
			for (i = 0; i < BlooddownVector.size(); i++) {
				if (BlooddownVector[i].colBlooddown() == 2) {
					MyHP -= 5000;
					HP.setSize(sf::Vector2f(MyHP / 320.f, 15));
					hppush.str(" ");
					hppush << "-5000 HP";
					Hpblood2.setString(hppush.str());
					Hpblood2.setPosition({ player.GetPosition().x,player.GetPosition().y - 90 });
					Sounddown.play();
					checkSub = true;
				}
			}
			if (checkSub == true) {
				countTimeSub += deltaTime;
				if (countTimeSub > 0.75) {
					Hpblood2.setPosition({ -800, 350 });
					countTimeSub = 0;
					checkSub = false;
				}
			}
			//X10
/*			x10.setPosition(player.GetPosition().x, player.GetPosition().y - 30);
			if (player.getBuffStatus() == true) {
				state = 1;
			}
			else {
				state = 0;
			}
*/
			ee.setPosition(view.getCenter().x - 540, 0);
			pp.setPosition(view.getCenter().x - 540, 0);
			pr.setPosition(view.getCenter().x - 540, 0);
			pm.setPosition(view.getCenter().x - 540, 0);
			pe.setPosition(view.getCenter().x - 540, 0);
			back1.setPosition(view.getCenter().x - 540, 0);
			back2.setPosition(view.getCenter().x - 540, 0);
			Send.setPosition(view.getCenter().x - 100, 440);
			CSTER.setPosition(view.getCenter().x - 100, 516);
			mission.setPosition(view.getCenter().x - 540, 0);
			NewScore.setPosition(view.getCenter().x - 108, 277);

			if (player.GetPosition().x >= 29160 && player.GetPosition().x <= 29527) {
				state = 3;
				//musicend.play();
				musicwin.play();
			}

			if ((player.GetPosition().x >= 9221 && player.GetPosition().x <= 9300) &&
				(player.GetPosition().y >= 327 && player.GetPosition().y <= 620))
			{
				Sound3.play();
				player.SetPosition(10568, 40);
				//rakai.SetPosition(10568, 40);
				checkmap1 = true;
			} 
			if ((player.GetPosition().x >= 18805 && player.GetPosition().x <= 18820) &&
				(player.GetPosition().y >= 327 && player.GetPosition().y <= 620))
			{
				Sound3.play();
				player.SetPosition(20568, 40);
				//rakai.SetPosition(20568, 40);
				checkmap2 = true;
				checkmap1 = false;
			} 
			window.clear();
			window.setView(view);
			for (Platform& platform : platforms) {
				platform.Draw(window);
			}
			window.draw(background);
			window.draw(background1);
			window.draw(background2);
			window.draw(warpPoint);
			window.draw(warpPoint1);
			window.draw(starPoint);
			
	/*		if (state == 1) {
				window.draw(x10);
			} */
			if (checkcoli == true) {
				if (q < 10) {
					if (q % 2 == 0 && timercoli.getElapsedTime().asSeconds() >= 0.1) {
						checkdraw = true;
						q++;
						timercoli.restart();
					}
					else if (q % 2 != 0 && timercoli.getElapsedTime().asSeconds() >= 0.1) {
						checkdraw = false;
						q++;
						timercoli.restart();
					}
					if (q == 10) {
						checkcoli = false;
					}
				}
			}
			if (checkdraw == false) {
				player.Draw(window);
			}
	
			window.draw(hpbar);
			window.draw(HP);
			window.draw(Score);
			window.draw(scoregame);
			window.draw(Hpblood);
			window.draw(Hpblood2);
		for (int i = 0; i < starVector.size(); i++) {
				starVector[i]->draw(window);
			}
			for (int i = 0; i < BloodupVector.size(); i++) {
				BloodupVector[i].draw(window);
			}
			for (int i = 0; i < BlooddownVector.size(); i++) {
				BlooddownVector[i].draw(window);
			}
			for (int i = 0; i < alienVector.size(); i++) {
				alienVector[i].draw(window);
			}
			for (int i = 0; i < alien1Vector.size(); i++) {
				alien1Vector[i].draw(window);
			}
			for (int i = 0; i < alien2Vector.size(); i++) {
				alien2Vector[i].draw(window);
			}
			for (int i = 0; i < alienamong1Vector.size(); i++) {
				alienamong1Vector[i].draw(window);
			}
			for (int i = 0; i < alienamong2Vector.size(); i++) {
				alienamong2Vector[i].draw(window);
			}
			if (endGame == false && state != 3) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
					checkpause = true;
				}
			}
			//cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << endl;
			if (checkpause == true) {
				music1.pause();
				window.draw(pp);
				Send.setPosition(view.getCenter().x - 45, 200);
				CSTER.setPosition(view.getCenter().x - 45, 250);
				window.draw(CSTER);
				window.draw(Send);
				if (sf::Mouse::getPosition(window).x >= 416 &&
					sf::Mouse::getPosition(window).y >= 307 &&
					sf::Mouse::getPosition(window).x <= 655 &&
					sf::Mouse::getPosition(window).y <= 368)
				{
					window.draw(pr);
					Send.setPosition(view.getCenter().x - 45, 200);
					CSTER.setPosition(view.getCenter().x - 45, 250);
					window.draw(CSTER);
					window.draw(Send);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						Soundch.play();
						checkpause = false;
						music1.play();
					}
				}
				else if (sf::Mouse::getPosition(window).x >= 416 &&
					sf::Mouse::getPosition(window).y >= 397 &&
					sf::Mouse::getPosition(window).x <= 655 &&
					sf::Mouse::getPosition(window).y <= 457)
				{
					window.draw(pm);
					Send.setPosition(view.getCenter().x - 45, 200);
					CSTER.setPosition(view.getCenter().x - 45, 250);
					window.draw(CSTER);
					window.draw(Send);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						Soundch.play();
						music1.stop();
						musicend.stop();
						timerpausemenu.restart();
						checkpause = false;
						MENU = true;
						START = false;
						Rank = false;

						bg.setPosition(view.getCenter().x - 540, 0.0f);
						bg1.setPosition(view.getCenter().x - 540, 0.0f);
						bg2.setPosition(view.getCenter().x - 540, 0.0f);
						bg3.setPosition(view.getCenter().x - 540, 0.0f);
						bg4.setPosition(view.getCenter().x - 540, 0.0f);
						key.setPosition(view.getCenter().x - 540, 0.0f);
						hh.setPosition(view.getCenter().x - 540, 0.0f);
						last_char = event.text.unicode;
						text.setString(playerInput);
						cursor.setPosition(view.getCenter().x + 5 + text.getGlobalBounds().width + 10, 555.0f);
						Keyname.setPosition(view.getCenter().x - 240, 500);
						text.setPosition(view.getCenter().x - 15, 535.0f);
						ll.setPosition(view.getCenter().x - 540, 0.0f);
						LL.setPosition(view.getCenter().x - 540, 0.0f);
						DL.setPosition(view.getCenter().x - 255, 647.5f);
					}
				}
				else if (sf::Mouse::getPosition(window).x >= 416 &&
					sf::Mouse::getPosition(window).y >= 486 &&
					sf::Mouse::getPosition(window).x <= 655 &&
					sf::Mouse::getPosition(window).y <= 546)
				{
					window.draw(pe);
					Send.setPosition(view.getCenter().x - 45, 200);
					CSTER.setPosition(view.getCenter().x - 45, 250);
					window.draw(CSTER);
					window.draw(Send);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						Soundch.play();
						window.close();
						break;
					}
				}
			}
			if (checkpause == false) {
				MyHP -= 5;
			}
			if (MyHP < 78000) {
				HP.setSize(sf::Vector2f(MyHP / 320.f, 15));
				if (MyHP < 0 || player.GetPosition().y >= 600) {
					MyHP = 0;
					endGame = true;
					for (; soundcount < 1; soundcount++) {
						sound_over = true;
					}
				}
			}
			if (endGame == true) {
				music1.stop();
				window.draw(ee);
				window.draw(CSTER);
				window.draw(NewScore);
				window.draw(Send);
				window.draw(back1);

				//cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y  << endl;
				if (sf::Mouse::getPosition(window).x >= 400 &&
					sf::Mouse::getPosition(window).y >= 600 &&
					sf::Mouse::getPosition(window).x <= 680 &&
					sf::Mouse::getPosition(window).y <= 650)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{

						Soundch.play();
						cout << "Save score" << endl;

						vector<pair<int, string> > score;
						string temp, tempString;
						int tempInt = 0, X = 1;
						while (window.pollEvent(event))
						{
							if (event.type == sf::Event::Closed)
								window.close();
							fileWriter.open("data/highscore.txt", std::ios::out | std::ios::app);
							fileWriter << "\n" << user_name << "," << EndScore + EndNumStar;
							fileWriter.close();
							playerInput.clear();
						}
						myFile.close();

						MENU = true;
						START = false;
						Rank = false;
						sound_over = false;
						musicend.stop();

						bg.setPosition(view.getCenter().x - 540, 0.0f);
						bg1.setPosition(view.getCenter().x - 540, 0.0f);
						bg2.setPosition(view.getCenter().x - 540, 0.0f);
						bg3.setPosition(view.getCenter().x - 540, 0.0f);
						bg4.setPosition(view.getCenter().x - 540, 0.0f);
						key.setPosition(view.getCenter().x - 540, 0.0f);
						hh.setPosition(view.getCenter().x - 540, 0.0f);
						last_char = event.text.unicode;
						text.setString(playerInput);
						cursor.setPosition(view.getCenter().x + 5 + text.getGlobalBounds().width + 10, 555.0f);
						Keyname.setPosition(view.getCenter().x - 240, 500);
						text.setPosition(view.getCenter().x - 15, 535.0f);
						ll.setPosition(view.getCenter().x - 540, 0.0f);
						LL.setPosition(view.getCenter().x - 540, 0.0f);
						DL.setPosition(view.getCenter().x - 255, 647.5f);
					}
				}
			}
			if (sound_over == true) {
				musicend.play();
			}
			sound_over = false;
			if (state == 3) {
				music1.stop();
				window.draw(mission);
				window.draw(back1);
				window.draw(CSTER);
				window.draw(NewScore);
				window.draw(Send);

				if (sf::Mouse::getPosition(window).x >= 400 &&
					sf::Mouse::getPosition(window).y >= 600 &&
					sf::Mouse::getPosition(window).x <= 680 &&
					sf::Mouse::getPosition(window).y <= 650)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						Soundch.play();
						cout << "Save score" << endl;

						vector<pair<int, string> > score;
						string temp, tempString;
						int tempInt = 0, X = 1;
						while (window.pollEvent(event))
						{
							if (event.type == sf::Event::Closed)
								window.close();
							fileWriter.open("data/highscore.txt", std::ios::out | std::ios::app);
							fileWriter << "\n" << user_name << "," << EndScore + EndNumStar;
							fileWriter.close();
							playerInput.clear();
						}
						myFile.close();

						MENU = true;
						START = false;
						Rank = false;
						sound_over = false;
						musicend.stop();
						musicwin.stop();

						bg.setPosition(view.getCenter().x - 540, 0.0f);
						bg1.setPosition(view.getCenter().x - 540, 0.0f);
						bg2.setPosition(view.getCenter().x - 540, 0.0f);
						bg3.setPosition(view.getCenter().x - 540, 0.0f);
						bg4.setPosition(view.getCenter().x - 540, 0.0f);
						key.setPosition(view.getCenter().x - 540, 0.0f);
						hh.setPosition(view.getCenter().x - 540, 0.0f);
						last_char = event.text.unicode;
						text.setString(playerInput);
						text.setString(playerInput);
						cursor.setPosition(view.getCenter().x + 5 + text.getGlobalBounds().width + 10, 555.0f);
						Keyname.setPosition(view.getCenter().x - 240, 500);
						text.setPosition(view.getCenter().x - 15, 535.0f);
						ll.setPosition(view.getCenter().x - 540, 0.0f);
						LL.setPosition(view.getCenter().x - 540, 0.0f);
						DL.setPosition(view.getCenter().x - 255, 647.5f);
					}
				}
			}
			if (checkpause == false) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
					Sound2.play();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					bulletCheck = player.getcheck();
					Sound1.play();
					bullet1.attack(pos);
					Bul = 1;
				}
				if (Bul >= 1) {
					if (bulletCheck == 1) {
						bullet1.update(deltaTime);
					}
					else {
						bullet1.update2(deltaTime);
					}
					bullet1.draw(window);
					for (i = 0; i < alienVector.size(); i++) {
						if (alienVector[i].hit1() == 1) {
							bullet1.del();
						}
					}
					for (i = 0; i < alien1Vector.size(); i++) {
						if (alien1Vector[i].hit1() == 1) {
							bullet1.del();
						}
					}
					for (i = 0; i < alien2Vector.size(); i++) {
						if (alien2Vector[i].hit1() == 1) {
							bullet1.del();
						}
					}
					for (i = 0; i < alienamong1Vector.size(); i++) {
						if (alienamong1Vector[i].hit1() == 1) {
							bullet1.del();
						}
					}
					for (i = 0; i < alienamong2Vector.size(); i++) {
						if (alienamong2Vector[i].hit1() == 1) {
							bullet1.del();
						}
					}
				}
				if (abs(player.GetPosition().x - bullet1.GetPosition().x) >= 500.0f) {
					Bul = 0;
					bullet1.isAvaliable();
				}
			}
			window.display();
		}

		countloop++;
		endGame = false;
		player.SetPosition(200, 520);
		player.ResetNumstar();

	 for (int i = 0; i < starVector.size(); i++) {
			starVector.erase(starVector.begin() + i);
		}
		starVector.clear();
		
		for (int i = 0; i < alienVector.size(); i++) {
			alienVector.erase(alienVector.begin() + i);
		}
		alienVector.clear();

		for (int i = 0; i < alien1Vector.size(); i++) {
			alien1Vector.erase(alien1Vector.begin() + i);
		}
		alien1Vector.clear();

		for (int i = 0; i < alien2Vector.size(); i++) {
			alien2Vector.erase(alien2Vector.begin() + i);
		}
		alien2Vector.clear();

		for (int i = 0; i < BloodupVector.size(); i++) {
			BloodupVector.erase(BloodupVector.begin() + i);
		}
		BloodupVector.clear();

		for (int i = 0; i < BlooddownVector.size(); i++) {
			BlooddownVector.erase(BlooddownVector.begin() + i);
		}
		BlooddownVector.clear();

	}
	return 0;
}
