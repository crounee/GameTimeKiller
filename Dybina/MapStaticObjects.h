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
			physicModel.LoadPhysicModel(150, 50, pos_h, pos_v);


			this->pos_h = pos_h;
			this->pos_v = pos_v;

			sprite.setTexture(texture);
			setNowPosition();
		}

	};
};