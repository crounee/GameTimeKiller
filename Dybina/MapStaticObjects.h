#pragma once



namespace MapObjects 
{
	class Wall 
	{
	private:
		sf::Sprite sprite;
		StandartPhysicModel::PhysicModel physicModel;

		float pos_h;
		float pos_v;

	public:
		
		StandartPhysicModel::PhysicModel& getPhysicModel()
		{
			return this->physicModel;
		}

		void setNowPosition()
		{
			sprite.setPosition(pos_h, pos_v);
		}

		sf::Sprite& getWallSprite() {
			return sprite;
		}

		Wall(sf::Texture& texture, float pos_h, float pos_v)
		{
			physicModel.LoadPhysicModel(pos_h, pos_h + 100, pos_v, pos_v + 50);


			this->pos_h = pos_h;
			this->pos_v = pos_v;

			sprite.setTexture(texture);
			//sprite.scale(sf::Vector2f(0.1, 0.1));
			setNowPosition();
		}

	};
};