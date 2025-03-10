#pragma once

#include <d2d1_1.h>
#include <string>
#include <wincodec.h>

#include <unordered_map>
#include <string>

namespace McCol
{
	class D2DTextureSystem
	{
	private:
		D2DTextureSystem();
		~D2DTextureSystem();

	private:
		static D2DTextureSystem* m_Instance;

		ID2D1DeviceContext* m_d2dContext;
		IWICImagingFactory* m_ImagingFactory;
		std::unordered_map<std::wstring_view, ID2D1Bitmap*> m_TextureContainer;

	public:
		static D2DTextureSystem* GetInstance()
		{
			if (m_Instance == nullptr)
				m_Instance = new D2DTextureSystem;

			return m_Instance;
		}

		void Initialize(ID2D1DeviceContext* d2dContext);
		void Finalize();

		// ���� ���, Ű �Է��Ͽ� ��Ʈ�� ����
		ID2D1Bitmap* LoadTexture(const std::wstring& strFilePath, std::wstring_view key);
		// ������ ��Ʈ�� ��ȯ
		ID2D1Bitmap* GetTexture(std::wstring_view key);

	private:

	};
}

