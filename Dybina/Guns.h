

namespace Guns
{
	class StandartGun
	{
	public:
		std::string whereGunGo;
		sf::Sprite sprite;

		float pos_h;
		float pos_v;

		int max_bullets = 30;
		
		int now_bullets = 0;

		void setNowPosition()
		{
			sprite.setPosition(pos_h, pos_v);
		}

		void doShoot(Engine::AllBullets &allBullets, sf::Texture& texture)
		{	
			if (now_bullets <= max_bullets) 
			{	
				Bullets::StandartBullet* n_b = new Bullets::StandartBullet(texture, pos_h, pos_v, whereGunGo);

				allBullets.addBulletObjectToVector(n_b);

				now_bullets++;
			}

			else 
			{

			}

		}
		

		void standartGun(sf::Texture& texture, float pos_h, float pos_v)
		{
			
			this->pos_h = pos_h;
			this->pos_v = pos_v;

			sprite.setTexture(texture);
			setNowPosition();
		}

		void moveRight()
		{
			pos_h += 0.10;
			setNowPosition();

		}

		void moveLeft()
		{
			pos_h -= 0.10;
			setNowPosition();

		}


	};
}