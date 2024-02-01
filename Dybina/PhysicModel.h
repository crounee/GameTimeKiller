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

	public:

		float start_h;
		float end_h;

		float start_v;
		float end_v;

		float 

		void LoadPhysicModel(float start_h,float end_h, float start_v,float end_v) 
		{
			this->start_h = start_h;
			this->end_h = end_h;

			this->start_v = start_v;
			this->end_v = end_v;
		}

		void movePhysicModelRight(float speed) 
		{
			start_h += speed;
			end_h += speed;
		}

		void movePhysicModelLeft(float speed)
		{
			start_h -= speed;
			end_h -= speed;
		}

		void movePhysicModelUp(float speed)
		{
			start_v -= speed;
			end_v -= speed;
		}

		void movePhysicModelDown(float speed)
		{
			start_v += speed;
			end_v += speed;
		}

	};
}