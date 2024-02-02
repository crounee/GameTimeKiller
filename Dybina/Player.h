
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
		std::string where_go;

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
			physicModel.LoadPhysicModel(50.0,75.0,pos_h, pos_v);
			
			

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

		void moveUp()
		{
			pos_v -= 0.10;
			setNowPosition();
			physicModel.movePhysicModelUp(0.1);
		
		}

		void moveDown()
		{
			pos_v += 0.10;
			setNowPosition();
			physicModel.movePhysicModelDown(0.1);
		}

		void setWhereGo(std::string whereGo) 
		{
			this->where_go = whereGo;
		}

	};
}