#include "MineScene.h"
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
    MineScene::MineScene()
        : mMine_Bg(nullptr)
        , mMine_Slime(nullptr)
    {
    }

    MineScene::~MineScene()
    {
    }
    
    void MineScene::Initialize()
    {
       // BackGround 추가
        {
            mMine_Bg = Object::Instantiate<GameObject>(eLayerType::BackGround, SetVector(-10.0f, 0.0f));
            SpriteRenderer* bgSr = mMine_Bg->AddComponent<SpriteRenderer>();

            Texture* bgTexture = Resources::Find<Texture>(L"Mine_BG");
            bgSr->SetTexture(bgTexture);
            bgSr->SetSize(SetVector(2.0f, 2.0f));
        }

        // Slime 추가
        {
            mMine_Slime = Object::Instantiate<Monster>(eLayerType::Player, SetVector(800.0f, 500.0f));
            mMine_Slime->AddComponent<MonsterScript>();

            Texture* slimeTexture = Resources::Find<Texture>(L"Mine_Slime");

            Animator* slime_animator = mMine_Slime->AddComponent<Animator>();
            slime_animator->CreateAnimation(L"SlimeMove", slimeTexture
                , SetVector(0.0f, 0.0f), SetVector(64.0f, 64.0f), SetVector::Zero, 7, 0.25f);

            slime_animator->PlayeAnimation(L"SlimeMove", true);

            mMine_Slime->GetComponent<Transform>()->SetScale(SetVector(0.7f, 0.7f));
        }

        Scene::Initialize();
    }
    
    void MineScene::Update()
    {
        Scene::Update();
    }
    
    void MineScene::LateUpdate()
    {
        Scene::LateUpdate();
    }
    
    void MineScene::Render(HDC hdc)
    {
        Scene::Render(hdc);

        wchar_t str[50] = L"MineScene";
        TextOut(hdc, 0, 0, str, 9);
    }
}