#include "Mine_B1_Scene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "SceneManger.h"
#include "Object.h"
#include "Texture.h"
#include "Resources.h"
#include "Camera.h"
#include "Renderer.h"
#include "Animator.h"
#include "Monster.h"
#include "MonsterScript.h"

namespace in
{
    Mine_B1_Scene::Mine_B1_Scene()
        : mMine_B1_Bg(nullptr)
        , mMine_B1_Slime(nullptr)
    {
    }

    Mine_B1_Scene::~Mine_B1_Scene()
    {
    }
    
    void Mine_B1_Scene::Initialize()
    {
       // BackGround 추가
        {
            mMine_B1_Bg = Object::Instantiate<GameObject>(eLayerType::BackGround, SetVector(-10.0f, 0.0f));
            SpriteRenderer* bgSr = mMine_B1_Bg->AddComponent<SpriteRenderer>();

            Texture* bgTexture = Resources::Find<Texture>(L"Mine_B1_BG");
            bgSr->SetTexture(bgTexture);
            bgSr->SetSize(SetVector(2.0f, 2.0f));
        }

        // Slime 추가
        {
            mMine_B1_Slime = Object::Instantiate<Monster>(eLayerType::Player, SetVector(800.0f, 500.0f));
            mMine_B1_Slime->AddComponent<MonsterScript>();

            Texture* slimeTexture = Resources::Find<Texture>(L"Mine_B1_Slime");

            Animator* slime_animator = mMine_B1_Slime->AddComponent<Animator>();
            slime_animator->CreateAnimation(L"SlimeMove", slimeTexture
                , SetVector(0.0f, 0.0f), SetVector(64.0f, 64.0f), SetVector::Zero, 7, 0.25f);

            slime_animator->PlayeAnimation(L"SlimeMove", true);

            mMine_B1_Slime->GetComponent<Transform>()->SetScale(SetVector(0.7f, 0.7f));
        }

        Scene::Initialize();
    }
    
    void Mine_B1_Scene::Update()
    {
        Scene::Update();
    }
    
    void Mine_B1_Scene::LateUpdate()
    {
        Scene::LateUpdate();
    }
    
    void Mine_B1_Scene::Render(HDC hdc)
    {
        Scene::Render(hdc);

        wchar_t str[50] = L"Mine_B1_Scene";
        TextOut(hdc, 0, 0, str, 13);
    }
}