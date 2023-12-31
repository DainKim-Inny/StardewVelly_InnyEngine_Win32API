#pragma once
#include "Entity.h"
#include "CommonHeader.h"
#include "GameObject.h"

using namespace std;

namespace in
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		void AddGameObject(GameObject* gameObject);
		void EraseGameObject(GameObject* eraseGameObj);
		const vector<GameObject*> GetGameObjects() { return mGameObjects; }

	private:
		void findDeadGameObjects(vector<GameObject*>& gameObjs);
		void deleteGameObjects(vector<GameObject*> deleteObjs);
		void eraseDeadGameObject();

	private:
		vector<GameObject*> mGameObjects;
	};

	typedef vector<GameObject*>::iterator GameObjectIter;
}