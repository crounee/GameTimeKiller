
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
		

		bool jumpStatus = false;
		int jumpMaxTimes = 500;
		int nowJumpTimes = 0;

		float speed;
		std::string where_go;
		std::string where_bullet_go = "right";

		StandartPhysicModel::PhysicModel & getPhysicModel() 
		{
			return this->physicModel;
		}

		void setNowPosition() 
		{
			sprite.setPosition(pos_h, pos_v);
		}

		sf::Vector2f getPosition() 
		{
			return sf::Vector2f(this->pos_h,this->pos_v);
		}

		sf::Sprite& getPlayerSprite() {
			return sprite;
		}

		StandartPlayer(sf::Texture &texture,float pos_h,float pos_v)
		{	
			physicModel.LoadPhysicModel(50.0,100.0,pos_h, pos_v);
			
			

			this->pos_h = pos_h;
			this->pos_v = pos_v;

			sprite.setTexture(texture);
			setNowPosition();
		}

		void jump(bool status)
		{	
			

			if (this->jumpMaxTimes > this->nowJumpTimes && jumpStatus == true) 
			{	
				if (status != true) {
					this->moveUp();
				}
				
				this->nowJumpTimes += 1;

			}

			if (this->jumpMaxTimes <= this->nowJumpTimes == true) 
			{
				this->jumpStatus = false;
				this->nowJumpTimes = 0;
			}

		}

		void moveRight() 
		{
			pos_h += 0.10;
			setNowPosition();
			physicModel.movePhysicModelRight(0.1);
			where_bullet_go = "right";
		}
		
		void moveLeft()
		{
			pos_h -= 0.10;
			setNowPosition();
			physicModel.movePhysicModelLeft(0.1);
			where_bullet_go = "left";
		}

		void moveUp()
		{
			pos_v -= 0.50;
			setNowPosition();
			physicModel.movePhysicModelUp(0.5);
		
		}

		void moveDown()
		{
			pos_v += 0.30;
			setNowPosition();
			physicModel.movePhysicModelDown(0.3);
		}

		void setWhereGo(std::string whereGo) 
		{
			this->where_go = whereGo;
		}

	};
}