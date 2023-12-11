#include "Mine_Lobby_Scene.h"
#include "Object.h"
#include "Layer.h"
#include "SpriteRenderer.h"
#include "Texture.h"
#include "Resources.h"
#include "Input.h"

namespace in
{
    Mine_Lobby_Scene::Mine_Lobby_Scene()
        : mMine_Lobby(nullptr)
    {
    }

    Mine_Lobby_Scene::~Mine_Lobby_Scene()
    {
    }
    
    void Mine_Lobby_Scene::Initialize()
    {
        // BackGround Ãß°¡
        {
            mMine_Lobby = Object::Instantiate<GameObject>(eLayerType::BackGround, SetVector(-10.0f, -10.0f));
            SpriteRenderer* bgSr = mMine_Lobby->AddComponent<SpriteRenderer>();

            Texture* bgTexture = Resources::Find<Texture>(L"Mine_Lobby_BG");
            bgSr->SetTexture(bgTexture);
            bgSr->SetSize(SetVector(1.45f, 1.5f));
        }
    }
    
    void Mine_Lobby_Scene::Update()
    {
        Scene::Update();
    }
    
    void Mine_Lobby_Scene::LateUpdate()
    {
        Scene::LateUpdate();

        if (Input::GetKeyDown(eKeyCode::N))
        {
            SceneManger::LoadScene(L"Mine_B1_Scene");
        }
    }
    
    void Mine_Lobby_Scene::Render(HDC hdc)
    {
        Scene::Render(hdc);

        wchar_t str[50] = L"Mine_Lobby_Scene";
        TextOut(hdc, 0, 0, str, 16);
    }
}
