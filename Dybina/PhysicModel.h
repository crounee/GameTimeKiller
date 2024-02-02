#pragma once




namespace StandartPhysicModel 
{	

	struct TwoCords 
	{
		float pos_h;
		float pos_v;
	};

	class PhysicModel 
	{	
	private:
		float pos_h;
		float pos_v;

		sf::RectangleShape physicModel;

	public:

		
		void LoadPhysicModel(float size_h,float size_v,float pos_h,float pos_v) 
		{
			physicModel.setSize(sf::Vector2f(size_h, size_v));
			physicModel.setPosition(sf::Vector2f(pos_h, pos_v));
			std::cout << physicModel.getTextureRect().height << "eblan" << std::endl;
			this->pos_h = pos_h;
			this->pos_v = pos_v;
		}

		sf::RectangleShape &getPhysicModel() 
		{
			return physicModel;
		}

		void movePhysicModelRight(float speed) 
		{
			pos_h += speed;
			physicModel.setPosition(sf::Vector2f(this->pos_h, this->pos_v));
			
			
		}

		void movePhysicModelLeft(float speed)
		{
			pos_h -= speed;
			physicModel.setPosition(sf::Vector2f(this->pos_h, this->pos_v));
		}

		void movePhysicModelUp(float speed)
		{
			pos_v -= speed;
			physicModel.setPosition(sf::Vector2f(this->pos_h, this->pos_v));
		}

		void movePhysicModelDown(float speed)
		{
			pos_v += speed;
			physicModel.setPosition(sf::Vector2f(this->pos_h, this->pos_v));
		}

	};
}