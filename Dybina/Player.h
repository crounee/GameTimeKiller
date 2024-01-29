
namespace PlayersM 
{
	class StandartPlayer 
	{
	private:
		sf::Sprite sprite;
		StandartPhysicModel::PhysicModel physicModel;

		float pos_h;
		float pos_v;

		

	public:

		float speed;

		StandartPhysicModel::PhysicModel & getPhysicModel() 
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

		StandartPlayer(sf::Texture &texture,float pos_h,float pos_v)
		{	
			physicModel.LoadPhysicModel(pos_h, pos_h + 50, pos_v, pos_v + 110);
			

			this->pos_h = pos_h;
			this->pos_v = pos_v;

			sprite.setTexture(texture);
			//sprite.scale(sf::Vector2f(0.1, 0.1));
			setNowPosition();
		}

		void moveRight() 
		{
			pos_h += 0.1;
			setNowPosition();
			physicModel.movePhysicModelRight(0.1);
		}
		
		void moveLeft()
		{
			pos_h -= 0.1;
			setNowPosition();
			physicModel.movePhysicModelLeft(0.1);
		}

		void moveUp()
		{
			pos_v -= 0.1;
			setNowPosition();
			physicModel.movePhysicModelUp(0.1);
		}

		void moveDown()
		{
			pos_v += 0.1;
			setNowPosition();
			physicModel.movePhysicModelDown(0.1);
		}

	};
}