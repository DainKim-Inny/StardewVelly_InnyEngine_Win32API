#pragma once
#include "Entity.h"

using namespace std;

namespace in
{
	class Resource abstract: public Entity
	{
	public:
		Resource(eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const wstring& path) = 0;  // 순수 가상함수

		const wstring& GetPath() { return mPath; }
		void SetPath(const wstring& path) { mPath = path; }

	private:
		const eResourceType mType;
		wstring mPath;

	};
}