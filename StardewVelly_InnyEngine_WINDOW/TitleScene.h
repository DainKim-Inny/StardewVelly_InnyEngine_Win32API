#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\Scene.h"

namespace in
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		class GameObject* mbg;
		class GameObject* mlogo;
		class GameObject* mNewButton;
		class GameObject* mLoadButton;
		class GameObject* mExitButton;
		class GameObject* mBird1;
		class GameObject* mBird2;
		class GameObject* mTopLeaf;
		class GameObject* mBottomLeaf;
		class GameObject* mQuestion;
	};
}
