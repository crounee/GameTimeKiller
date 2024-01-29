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
			}
		}

		bool checkCanPlayerMove(PlayersM::StandartPlayer &player) 
		{
			for (int nowStaticObject = 0; nowStaticObject < allStaticObjects.size(); nowStaticObject++) 
			{	//for start h	

				std::cout << "Player h " << player.getPhysicModel().start_h << " EnD h " << player.getPhysicModel().end_h << std::endl;
				std::cout << "Player v " << player.getPhysicModel().start_v << " EnD v " << player.getPhysicModel().end_v << std::endl;

				std::cout << "OBJ start h " << allStaticObjects.at(nowStaticObject)->getPhysicModel().start_h << " END h " << allStaticObjects.at(nowStaticObject)->getPhysicModel().end_h << std::endl;
				std::cout << "OBJ start v " << allStaticObjects.at(nowStaticObject)->getPhysicModel().start_v << " END v " << allStaticObjects.at(nowStaticObject)->getPhysicModel().end_v <<"\n" << std::endl;

				
				if (player.getPhysicModel().start_h >= allStaticObjects.at(nowStaticObject)->getPhysicModel().start_h && player.getPhysicModel().start_h <= allStaticObjects.at(nowStaticObject)->getPhysicModel().end_h && player.getPhysicModel().start_v >= allStaticObjects.at(nowStaticObject)->getPhysicModel().start_v && player.getPhysicModel().start_v <= allStaticObjects.at(nowStaticObject)->getPhysicModel().end_v)
				{

					
					return true;

				}

				else {
					return false;
				}
				
			}
		}

	};
}