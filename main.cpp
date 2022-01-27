#include "src/Header.h"
#include "src/enemy.h"
#include "src/bullet.h"
#include "src/player.h"
#include "src/read.cpp"
int main()
{
	int cx = GetSystemMetrics(SM_CXSCREEN);
	int cy = GetSystemMetrics(SM_CYSCREEN);

	Clock clock;
	Image heroImage;

	RenderWindow window(sf::VideoMode(400, 1000), "My Game");

	SoundBuffer shootBuffer;
	shootBuffer.loadFromFile("audio/shoot.ogg");
	Sound shoot(shootBuffer);

	SoundBuffer overBuffer;
	overBuffer.loadFromFile("audio/game_over.ogg");
	Sound game_over(overBuffer);

	heroImage.loadFromFile("img/hero.png");

	Image EnemyImage;
	EnemyImage.loadFromFile("img/enemy.png");

	Image BulletImage;
	BulletImage.loadFromFile("img/bullet.png");
	BulletImage.createMaskFromColor(Color(255, 255, 255));

	sf::Event event;

	while (window.isOpen())
	{

		std::list <Entity*> entities;
		std::list <Entity*>::iterator it;
		read();
		int** params = new int* [enemy_volume];
		int a = 0;
		for (int i = 0; i < enemy_volume; i++) {
			params[i] = new int[2];
			params[i][0] = rand() % 350;
			params[i][1] = a - enemy_dist;
			a -= enemy_dist;
		}
		for (int i = 0; i < enemy_volume; i++) {
			entities.push_back(new Enemy(EnemyImage, params[i][0], params[i][1], 50.0, 38.0, enemy_s, **params));
		}
		Player p(heroImage, 150, 600, 86.0, 131.0, player_s);
		Bullet b(BulletImage, -100, -100, 16, 32, bullet_s);
		Bullet b2(BulletImage, -100, -100, 16, 32, bullet_s);
		while (game == 1) {
			Font font;
			font.loadFromFile("font/CyrilicOld.TTF");
			Text text("", font, 20);
			text.setStyle(sf::Text::Bold | sf::Text::Underlined);

			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 800;

			if (Time_Bullet < 1) {
				Time_Bullet += 0.002 * time;
			}

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();

			int i = 0;
			for (it = entities.begin(); it != entities.end(); it++) {
				(*it)->x = params[i][0];
				if ((*it)->y > 1100) {
					(*it)->y = -100;
					(*it)->enemy_s = enemy_s + 0.005;
					params[i][0] = rand() % 350;
				}
				(*it)->update(time);
				i++;
			}
			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				if (b.x == -100 && Time_Bullet >= 1) {
					shoot.play();
					b.x = p.x + p.w / 2 - 8; b.y = p.y - 8;
					Time_Bullet = 0;
				}
				if (b.x != -100 && b2.x == -100 && Time_Bullet >= 1) {
					shoot.play();
					b2.x = p.x + p.w / 2 - 8; b2.y = p.y - 8;
					Time_Bullet = 0;
				}
			}
			b2.update(time);
			b.update(time);
			p.update(time);
			for (it = entities.begin(); it != entities.end(); it++) {
				window.draw((*it)->sprite);
			}
			std::ostringstream playerScoreString;
			playerScoreString << playerScore;
			text.setString("Score:" + playerScoreString.str());
			text.setPosition(300, 20);
			window.draw(text);
			window.draw(p.sprite);
			window.draw(b2.sprite);
			window.draw(b.sprite);
			for (it = entities.begin(); it != entities.end(); it++) {
				if ((*it)->getRect().intersects(b.getRect2()))
				{
					b.x = -100;
					b.y = -100;
					(*it)->y = -100 - 1000 - (*it)->y;
					playerScore += 1;
				}
				if ((*it)->getRect().intersects(b2.getRect2()))
				{
					b2.x = -100;
					b2.y = -100;
					(*it)->y = -100 - 1000 - (*it)->y;
					playerScore += 1;
				}
				if ((*it)->getRect().intersects(p.getRect1()))
				{
					game_over.play();
					delete[]params;
					game = 0;
				}
			}
			window.display();
		}
		while (game == 0) {
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			Texture texture;
			Sprite sprite;
			Image Image;
			Image.loadFromFile("img/lose.jpg");
			Image.createMaskFromColor(Color(0, 0, 0));
			texture.loadFromImage(Image);
			sprite.setTexture(texture);
			sprite.setTextureRect(IntRect(0, 0, 299, 72));
			sprite.setPosition(60, 350);
			window.draw(sprite);
			window.display();
			if (Keyboard::isKeyPressed(Keyboard::Enter)) {
				playerScore = 0;
				game = 1;
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				game = -1;
			}
		}
		while (game == -1) {
			window.close();
			return 0;
		}
	}
	return 0;
}