#pragma once
#include "CommonHeader.h"

using namespace std;

namespace in
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const wstring& name) { mName = name; }
		wstring& GetName() { return mName; }

	private:
		wstring mName;
	};
}