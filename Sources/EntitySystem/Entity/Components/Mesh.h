#pragma once
#include "Component.h"

namespace Components
{
	class Mesh : public Component
	{
	private:
		std::string meshFile;
		std::string textureFile;

	public:
		static const int ID;
		int GetID() { return ID;}
	};

}