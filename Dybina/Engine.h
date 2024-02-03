#pragma once


namespace Engine
{
	class AllPlayerObjects 
	{
	private:
		std::vector<PlayersM::StandartPlayer*> allplayers;

	public:

		void addPlayerToVector(PlayersM::StandartPlayer *player) 
		{
			allplayers.push_back(player);
		}

		void drawAllPlayers(sf::RenderWindow &window)
		{
			for (int nowObject = 0; nowObject < allplayers.size(); nowObject++) 
			{
				window.draw(allplayers.at(nowObject)->getPlayerSprite());
				

			}
		}

	};


	class AllStaticObjects
	{
	private:
		std::vector<MapObjects::Wall*> allStaticObjects;

	public:

		void addStaticObjectToVector(MapObjects::Wall* staticObject)
		{
			allStaticObjects.push_back(staticObject);
		}

		void drawAllStaticObjects(sf::RenderWindow& window)
		{
			for (int nowObject = 0; nowObject < allStaticObjects.size(); nowObject++)
			{
				window.draw(allStaticObjects.at(nowObject)->getWallSprite());
				//window.draw(allStaticObjects.at(nowObject)->getPhysicModel().getPhysicModel());
			}

			//Draw size
			//std::cout << allStaticObjects.size()<<std::endl;

		}

		bool checkCanPlayerMove(PlayersM::StandartPlayer player) 
		{	

			
			if (player.where_go == "left")
			{
				player.moveLeft();
			}
			else if (player.where_go == "right")
			{
				player.moveRight();
			}
			else if (player.where_go == "up")
			{
				player.moveUp();
			}
			else if (player.where_go == "down")
			{
				player.moveDown();
			}


			for (int nowStaticObject = 0; nowStaticObject < allStaticObjects.size(); nowStaticObject++) 
			{	
				sf::FloatRect playerRect(player.getPhysicModel().getPhysicModel().getPosition(), player.getPhysicModel().getPhysicModel().getSize());
			
				sf::FloatRect staticObj(allStaticObjects.at(nowStaticObject)->getPhysicModel().getPhysicModel().getPosition(), allStaticObjects.at(nowStaticObject)->getPhysicModel().getPhysicModel().getSize());

				if (staticObj.intersects(playerRect) == true) { return true; };
			}
			
			return false;
		}

		bool GetHitStatus(Bullets::StandartBullet *bullet) 
		{
			for (int nowStaticObject = 0; nowStaticObject < allStaticObjects.size(); nowStaticObject++)
			{
				sf::FloatRect playerRect(bullet->getPhysicModel().getPhysicModel().getPosition(), bullet->getPhysicModel().getPhysicModel().getSize());

				sf::FloatRect staticObj(allStaticObjects.at(nowStaticObject)->getPhysicModel().getPhysicModel().getPosition(), allStaticObjects.at(nowStaticObject)->getPhysicModel().getPhysicModel().getSize());

				return staticObj.intersects(playerRect);
			}
		}


	};

	class AllBullets
	{
	private:
		std::vector<Bullets::StandartBullet*> allBulletsObjects;

	public:

		void addBulletObjectToVector(Bullets::StandartBullet* BulletObject)
		{
			allBulletsObjects.push_back(BulletObject);
		}

		void drawAllBulletsObjects(sf::RenderWindow& window)
		{
			for (int nowObject = 0; nowObject < allBulletsObjects.size(); nowObject++)
			{

				window.draw(allBulletsObjects.at(nowObject)->getPlayerSprite());
				//window.draw(allBulletsObjects.at(nowObject)->getPhysicModel().getPhysicModel());

			}
			//std::cout << allBulletsObjects.size() << std::endl;
		}

		void moveAllBullets()
		{

			for (int nowObject = 0; nowObject < allBulletsObjects.size(); nowObject++)
			{

				allBulletsObjects.at(nowObject)->MoveBullet();

			}

		}

		void checkOutSideBullets(AllStaticObjects& allStaticObjects)
		{
			for (int nowObject = 0; nowObject < allBulletsObjects.size(); nowObject++)
			{

				if (allBulletsObjects.at(nowObject)->getPosition().x >= 1080
					|| allBulletsObjects.at(nowObject)->getPosition().x <= 0
					|| allBulletsObjects.at(nowObject)->getPosition().y >= 1080
					|| allBulletsObjects.at(nowObject)->getPosition().y <= 0)
				{

					allBulletsObjects.erase(allBulletsObjects.begin() + nowObject);
					nowObject--;
				}
				else if (allStaticObjects.GetHitStatus(allBulletsObjects.at(nowObject))) 
				{
					allBulletsObjects.erase(allBulletsObjects.begin() + nowObject);
					nowObject--;
				}

			}
		}
	};
}