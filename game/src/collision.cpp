#include "collision.h"

namespace Flappy
{
	Collision::Collision()
	{

	}


	bool Collision::CheckSpriteCollision(Sprite sprite1, Sprite sprite2)
	{
		Rect<float> rect1 = sprite1.getGlobalBounds();
		Rect<float> rect2 = sprite2.getGlobalBounds();

		if (rect1.intersects(rect2))
		{
			return true;
		}

		return false;
	}

	bool Collision::CheckSpriteCollision(Sprite sprite1, float scale1, Sprite sprite2, float scale2)
	{
		sprite1.setScale(scale1, scale1);
		sprite2.setScale(scale2, scale2);

		Rect<float> rect1 = sprite1.getGlobalBounds();
		Rect<float> rect2 = sprite2.getGlobalBounds();

		if (rect1.intersects(rect2))
		{
			return true;
		}

		return false;
	}



	Collision::~Collision()
	{

	}
}