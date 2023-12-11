#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\Scene.h"

namespace in
{
	class Mine_Lobby_Scene : public Scene
	{
	public:
		Mine_Lobby_Scene();
		~Mine_Lobby_Scene();
		
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		class GameObject* mMine_Lobby;
	};
}