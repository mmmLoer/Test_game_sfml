class Enemy :public Entity {
public:
	Enemy(Image& image, float X, float Y, float W, float H, float ENEMY_S, int params) :Entity(image, X, Y, W, H) {
		w = W; h = H;
		enemy_s = ENEMY_S;
		sprite.setTextureRect(IntRect(0, 0, w, h));
		x = X; y = Y;
	}

	void update(float time)
	{
		y += enemy_s * time;
		sprite.setPosition(x, y);
	}
};
