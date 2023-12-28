#pragma once
#include "CommonHeader.h"
#include "Component.h"
#include "Collider.h"

namespace in
{
	class GameObject
	{
	public:

		enum class eState
		{
			Active,
			Paused,
			Dead,
			End
		};

		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template<typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);

			mComponents[(UINT)comp->GetType()] = comp;

			return comp;
		}

		template<typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);

				if (component)
					break;
			}

			return component;
		}

		eState GetState() { return mState; }

		void SetActive(bool power)
		{
			if (power == true)
				mState = eState::Active;

			if (power == false)
				mState = eState::Paused;
		}

		bool IsActive() { return mState == eState::Active; }
		void Death() { mState = eState::Dead; }
		bool IsDead() { return mState == eState::Dead; }
		
	private:
		void initializeTransform();

	private:
		eState mState;
		vector<Component*> mComponents;
	};

}