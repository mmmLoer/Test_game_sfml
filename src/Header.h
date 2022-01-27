#pragma once
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <sstream>
#include <list>

using namespace sf;
using namespace std;
int enemy_volume, enemy_dist, playerScore, game = 1;
float CurrentFrame=0, player_s, bullet_s, enemy_s, Time_Bullet=3;

class Entity {
public:
	float dx, dy, x, y, speed, enemy_s;
	int w, h, i, playerScore;
	Texture texture;
	Sprite sprite;
	Entity(Image& image, float X, float Y, int W, int H) {
		x = X; y = Y; w = W; h = H;
		speed = 0; dx = 0; dy = 0;
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}
	virtual void update(float time) = 0;
	FloatRect getRect() {
		return FloatRect(x, y, w, h);
	}
};