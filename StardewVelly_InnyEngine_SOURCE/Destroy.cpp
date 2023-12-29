#include "Destroy.h"
#include "GameObject.h"

namespace in
{
	void Destroy::ObjDestroy(GameObject* obj)
	{
		obj->Death();
	}
}