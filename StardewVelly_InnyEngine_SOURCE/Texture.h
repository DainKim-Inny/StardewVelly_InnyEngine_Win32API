#pragma once
#include "Resource.h"

using namespace std;

namespace in
{
	class Texture : public Resource
	{
	public:
		enum class eTextureType
		{
			Bmp,
			Png,
			None
		};

		Texture();
		~Texture();

		HRESULT Load(const wstring& path) override;

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		HDC GetHdc() { return mHdc; }
		eTextureType GetTextrueType() { return mType; }
		Gdiplus::Image* GetImage() { return mImage; }

	private:
		eTextureType mType;
		Gdiplus::Image* mImage;
		HBITMAP mBitmap;
		HDC mHdc;

		UINT mWidth;
		UINT mHeight;
	};
}