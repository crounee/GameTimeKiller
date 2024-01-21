

namespace Player 
{	//player class
	class Player 
	{
	public:
		float cords_h = 0.0;
		float cords_v = 70.0;
		sf::Sprite human_model;
		Player(sf::Texture& human_texture) 
		{
			human_model.setTexture(human_texture);
			human_model.scale(float(0.1), float(0.1));
		}

		void setCords() 
		{
			human_model.setPosition(this->cords_h, this->cords_v);
		}

		void go_left()
		{
			this->cords_h -= 0.1;
			setCords();
		}

		void go_right()
		{
			this->cords_h += 0.1;
			setCords();
		}
		
	};


	class Your_player: public Player
	{	
	public:
		Your_player(sf::Texture& human_texture) : Player(human_texture) 
		{
			
		}
	};

}