#pragma once
#include "Component.h"
#include <string>

namespace Components 
{
	class Sprite : public Component
	{
	private:
		std::string spriteName;
	public:
		static const int ID;
		int GetID() { return ID;}
		std::string GetSpriteName() { return spriteName; }	
		Sprite(const std::string spriteName):spriteName(spriteName)
		{
		};
	};

	typedef std::shared_ptr<Sprite> SpriteSP;
}