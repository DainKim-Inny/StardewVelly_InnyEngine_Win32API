#pragma once

namespace in 
{
	class Destroy
	{
	public:
		Destroy();
		~Destroy();

		static void ObjDestroy(class GameObject* obj);
	};
}
