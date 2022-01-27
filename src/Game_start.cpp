int Game_start() {
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

	Texture texture;
	texture.loadFromFile("img/fon.jpg");

	Font font;
	font.loadFromFile("font/CyrilicOld.TTF");
	Text text("", font, 20);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}