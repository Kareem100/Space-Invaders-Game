#include "Level4.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <list>
#include <sstream>
using namespace std;
using namespace sf;


Animation::Animation(Texture &t, int x, int y, int w, int h, int count, float Speed, string s){
	Frame = 0;
	speed = Speed;

	for (int i = 0; i<count; i++)
		frames.push_back(IntRect(x + i*w, y, w, h));

	sprite.setTexture(t);
	sprite.setOrigin(w / 2, h / 2);
	if (s == "order")sprite.setScale(1, 1);
	else if ((count == 1 || count == 8) && s != "order"){ sprite.setScale(1, 1); }
	else if (s == "egg"){ sprite.setScale(1, 1); }
	else if (s == "bigenemy")sprite.setScale(0.8, 0.8);

	sprite.setTextureRect(frames[0]);
}
void back_groung(Sprite &s, int &ani, RenderWindow &window){
	s.setTextureRect(IntRect(0, ani*0.125, 2000, 2000));
	if (ani >= 1250 * 8)ani = 0;
	window.draw(s);
}
Entity::Entity(){
	life = 1;
}
void Entity::settings(Animation &a, int X, int Y, float Angle, int radius, int n){
	anim = a;
	x = X; y = Y;
	angle = Angle;
	R = radius;
	number = n;
}
void Entity::draw(RenderWindow &app){
	anim.sprite.setPosition(x, y);
	anim.sprite.setRotation(angle + 90);
	app.draw(anim.sprite);
}

void LevelFour::Progress()
{
	const int ScreenWidth = 1380, ScreenHeight = 770;

	srand(time(0)); // Lsa M3rfch bta3t eh !!!!
	RenderWindow window(VideoMode(ScreenWidth, ScreenHeight), "Space Invaders!!");
	
	window.setFramerateLimit(60);
	
	Texture backGround, spaceShip, bigChicken, fires, boom, shipDoomed, eggs;
	backGround.loadFromFile("../sfml_test.2/sfml_test.2/images/ch_background2.jpg");   
	spaceShip.loadFromFile("../sfml_test.2/sfml_test.2/images/spaceship.png"); 
	shipDoomed.loadFromFile("../sfml_test.2/sfml_test.2/images/explosions/type_B.png"); 
	boom.loadFromFile("../sfml_test.2/sfml_test.2/images/explosions/type_A.png");  
	fires.loadFromFile("../sfml_test.2/sfml_test.2/images/fire_red.png"); 
	bigChicken.loadFromFile("../sfml_test.2/sfml_test.2/images/BlueBigChicken.png"); 
	eggs.loadFromFile("../sfml_test.2/sfml_test.2/images/egg_1.png");

	Sprite Background(backGround);


	Animation Spaceship(spaceShip, 40, 0, 40, 40, 1, 0, "0");
	Animation SpaceshipLaunch(spaceShip, 40, 40, 40, 40, 1, 0, "0");
	Animation SpaceshipTurningRight(spaceShip, 80, 0, 40, 40, 1, 0, "0");
	Animation SpaceshipTurningLeft(spaceShip, 0, 0, 39, 40, 1, 0, "0");
	Animation ShipDoomed(shipDoomed, 0, 0, 192, 192, 64, 0.5, "0");
	Animation Boom (boom, 0, 0, 256, 256, 44, 0.5, "0");
	Animation Fires (fires, 0, 0, 32, 64, 16, 0.8, "0");
	Animation BigChicken(bigChicken, 0, 0, 565, 462, 2, 0, "bigenemy");
	Animation Eggs (eggs, 0, 0, 40, 40, 1, 0, "egg");

	bigenemy *BlueChicken = NULL;
	bigenemy *RedChicken = NULL;
	/*
	Music music;
	music.openFromFile("Chicken invaders soundtrack.wav");
	music.setVolume(300);
	music.setLoop(true);
	music.play();

	Sound bullet, pump1;
	SoundBuffer Bullet, bfpump;
	Bullet.loadFromFile("bullt1.wav");
	bfpump.loadFromFile("pump1.wav");
	bullet.setBuffer(Bullet);
	pump1.setBuffer(bfpump);
	*/
	int ani = 0, bullet_counter=0;
	while (window.isOpen())
	{

		//bullet_counter++;
		BlueChicken = new bigenemy();
		BlueChicken->settings(BigChicken, ScreenWidth / 1.38, ScreenHeight / -5.133333333, ScreenWidth / -15.33333333, ScreenWidth / 6.9);


		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
	//window.clear();
	ani+=50;
	back_groung(Background, ani, window);
	window.draw(Background);
	window.display();
	}
}