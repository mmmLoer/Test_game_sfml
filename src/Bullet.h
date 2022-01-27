class Bullet :public Entity {
public:
	int direction;

	Bullet(Image& image, float X, float Y, float W, float H, float BULLET_S) :Entity(image, X, Y, W, H) {
		x = X; y = Y; w = W; h = H; bullet_s = BULLET_S;
	}
	FloatRect getRect2() {
		return FloatRect(x, y, w, h);
	}

	void update(float time)
	{
		if (y > 0) {
			y -= bullet_s * time;
		}
		else {
			y = -100;
			x = -100;
		}
		sprite.setPosition(x, y);
	}
};
