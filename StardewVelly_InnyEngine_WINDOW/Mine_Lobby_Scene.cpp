#include "Mine_Lobby_Scene.h"
#include "FarmScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "SceneManager.h"
#include "Object.h"
#include "Texture.h"
#include "Resources.h"
#include "PlayerScript.h"
#include "Camera.h"
#include "Renderer.h"
#include "Animator.h"
#include "Mine_B1_Scene.h"

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
        // BackGround 추가
        {
            mMine_Lobby = Object::Instantiate<GameObject>(eLayerType::BackGround, SetVector(-10.0f, -10.0f));
            SpriteRenderer* bgSr = mMine_Lobby->AddComponent<SpriteRenderer>();

            Texture* bgTexture = Resources::Find<Texture>(L"Mine_Lobby_BG");
            bgSr->SetTexture(bgTexture);
            bgSr->SetSize(SetVector(1.45f, 1.5f));
        }

        // Player 소환
        {
        }
    }
    
    void Mine_Lobby_Scene::Update()
    {
        Scene::Update();
    }
    
    void Mine_Lobby_Scene::LateUpdate()
    {
        Scene::LateUpdate();

        SetVector mousePos = Input::GetMousePosition();

        if (Input::GetKeyDown(eKeyCode::MouseRB)
            && 600.0f <= mousePos.x && mousePos.x <= 660.0f
            && 100.0f <= mousePos.y && mousePos.y <= 200.0f)
        {
            SceneManager::LoadScene(L"Mine_B1_Scene");
        }
    }
    
    void Mine_Lobby_Scene::Render(HDC hdc)
    {
        Scene::Render(hdc);

        wchar_t str[50] = L"Mine_Lobby_Scene";
        TextOut(hdc, 0, 0, str, 16);
    }
}
