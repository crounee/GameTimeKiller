#pragma once


namespace Bullets 
{
	class StandartBullet 
	{
	private:
		sf::Sprite sprite;
		StandartPhysicModel::PhysicModel physicModel;

		float pos_h;
		float pos_v;

		

	public:

		float speed;
		std::string where_go;

		StandartPhysicModel::PhysicModel& getPhysicModel()
		{
			return this->physicModel;
		}

		void setNowPosition()
		{
			sprite.setPosition(pos_h, pos_v);
		}

		sf::Sprite& getPlayerSprite() {
			return sprite;
		}

		sf::Vector2f getPosition()
		{
			return sf::Vector2f(this->pos_h, this->pos_v);
		}

		StandartBullet(sf::Texture& texture, float pos_h, float pos_v,std::string wherego)
		{
			physicModel.LoadPhysicModel(25.0, 10.0, pos_h, pos_v);

			where_go = wherego;
			this->pos_h = pos_h;
			this->pos_v = pos_v;

			sprite.setTexture(texture);
			setNowPosition();
		}

		void moveRight()
		{
			pos_h += 0.10;
			setNowPosition();
			physicModel.movePhysicModelRight(0.1);

		}

		void moveLeft()
		{
			pos_h -= 0.10;
			setNowPosition();
			physicModel.movePhysicModelLeft(0.1);

		}


		void MoveBullet() {
			if (where_go == "right")
			{
				moveRight();
			}

			if (where_go == "left")
			{
				moveLeft();
			}
		}

	};
}