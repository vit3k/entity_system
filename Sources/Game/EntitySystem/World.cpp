#include "World.h"

EntityStrongPtr World::Create()
{
	EntityStrongPtr e(new Entity(idSequencer.Next(),this));
	entityManager->Add(e);
	return e;
}