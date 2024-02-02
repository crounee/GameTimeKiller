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
				window.draw(allStaticObjects.at(nowObject)->getPhysicModel().getPhysicModel());
			}
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

				return staticObj.intersects(playerRect);
			}
			
		}

	};
}