#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <string>
using namespace std;
using namespace sf;
#pragma once

class Animation
{
public:
	float Frame, speed;
	Sprite sprite;
	vector<IntRect> frames;

	Animation(){}
	Animation(Texture &t, int x, int y, int w, int h, int count, float Speed, string s);
	void update();
	bool isEnd();

};
class Entity
{
public:
	float x, y, dx, dy, R, angle;
	bool life; int number;
	string name;
	Animation anim;
	Entity();
	void settings(Animation &a, int X, int Y, float Angle = 0, int radius = 1, int n = -1);
	virtual void update(){};
	void draw(RenderWindow &app);
	virtual ~Entity(){};
};
class bigenemy :public Entity{
public:
	bigenemy();
	void update();
};

class LevelFour
{
private:
	
public:
	void Progress();

};

