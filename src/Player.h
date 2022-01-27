
class Player :public Entity {
public:

	float x, y, w, h, dx, dy, speed = 0;
	int dir = 0;
	Texture texture;
	Sprite sprite;
	enum { left, right, up, down, stay } state;
	int isShoot = 0;
	Player(Image& image, float X, float Y, float W, float H, float PLAYER_S) :Entity(image, X, Y, W, H) {
		playerScore = 0;
		w = W; h = H;
		player_s = PLAYER_S;
		image.createMaskFromColor(Color(255, 255, 255));
		image.createMaskFromColor(Color(226, 219, 215));
		image.createMaskFromColor(Color(252, 253, 252));
		image.createMaskFromColor(Color(245, 248, 245));
		image.createMaskFromColor(Color(242, 246, 242));
		image.createMaskFromColor(Color(239, 244, 239));
		image.createMaskFromColor(Color(236, 242, 236));
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
		sprite.setTextureRect(IntRect(0, 0, w, h));
		sprite.setOrigin(4, 0);
	}

	void control() {
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			state = left; speed = player_s;
		}

		if (Keyboard::isKeyPressed(Keyboard::D)) {
			state = right; speed = player_s;
		}

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			state = up; speed = player_s;
		}

		if (Keyboard::isKeyPressed(Keyboard::S)) {
			state = down; speed = player_s;
		}
	}
	FloatRect getRect1() {
		return FloatRect(x, y, w, h);
	}
	void update(float time)
	{
		control();
		switch (state)
		{
		case right: if (x < 304) {
			dx = speed; dy = 0;   break;
		}
		case left: if (x > 0) {
			dx = -speed; dy = 0; break;
		}
		default: dx = 0; dy = 0;   break;
		case down: if (y < 850) {
			dx = 0; dy = speed;   break;
		}
		case up: if (y > 500) {
			dx = 0; dy = -speed;   break;
		}
		case stay: dx = 0; dy = 0;   break;
		}
		x += dx * time;
		y += dy * time;
		speed = 0;
		sprite.setPosition(x, y);
		CurrentFrame += 0.01 * time;
		if (CurrentFrame > 3) {
			CurrentFrame -= 3;
		}
		sprite.setTextureRect(IntRect(94 * int(CurrentFrame), 0, 94, 159));

	}

};