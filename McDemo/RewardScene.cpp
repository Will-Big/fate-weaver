#include "RewardScene.h"

#include "../Engine/Macro.h"
#include "../Engine/InputSystem.h"
#include "../Engine/MouseCollisionSystem.h"
#include "../RenderEngine/D2DTextureSystem.h"

#include "../Engine/GameObject.h"
#include "../Engine/Transform.h"
#include "../Engine/Camera.h"

#include "../Engine/BaseRenderer.h"
#include "../Engine/TextureRenderer.h"
#include "../Engine/PrimitiveRenderer.h"
#include "../Engine/TextRenderer.h"
#include "../Engine/Animation.h"
#include "../Engine/AnimationClip.h"
#include "../Engine/AnimationState.h"

#include "../Engine/UI.h"
#include "../Engine/Button.h"
#include "../Engine/PopUp.h"
#include "../Engine/Panel.h"

#include "Deck.h"
#include "Mouse.h"
#include "FateCard.h"
#include "PlayCard.h"
#include "CardFactory.h"
#include "GameManager.h"
#include "../Engine/RandomGenerator.h"

using namespace McCol;


RewardScene::RewardScene()
    : Scene(L"Reward Scene")
    , m_IsFateCardReward(false)
    , m_IsPlayCardReward(false)
    , m_IsRemoveReward(false)
{
    EventSystem::GetInstance()->Subscribe(L"R_UI_FATE_CARD_BUTTON_DOWN", MakeListenerInfo(&RewardScene::FateCardRewardClick));
    EventSystem::GetInstance()->Subscribe(L"R_UI_PLAY_CARD_BUTTON_DOWN", MakeListenerInfo(&RewardScene::PlayCardRewardClick));
    EventSystem::GetInstance()->Subscribe(L"R_UI_REMOVE_BUTTON_DOWN", MakeListenerInfo(&RewardScene::RemoveRewardClick));
    EventSystem::GetInstance()->Subscribe(L"R_UI_SKIP_BUTTON_DOWN", MakeListenerInfo(&RewardScene::SkipButtonClick));
    EventSystem::GetInstance()->Subscribe(L"R_UI_BACK_BUTTON_DOWN", MakeListenerInfo(&RewardScene::BackButtonClick));
}

RewardScene::~RewardScene()
{
}

void RewardScene::Enter()
{
    ///Background
    m_BgObj = new GameObject(L"���");
    m_BgObj->AddComponent<Transform>();
    m_BgObj->GetComponent<Transform>()->SetPosition({ 0.f, 0.f });
    m_BgObj->GetComponent<Transform>()->SetScale({ 1.0f, 1.0f });

    m_BgObj->AddComponent<TextureRenderer>();
    m_BgObj->GetComponent<TextureRenderer>()->SetBitmap(D2DTextureSystem::GetInstance()->LoadTexture(L"../Resource/UI/reward_popup_bg.png", L"reward_popup_bg"));
    m_BgObj->GetComponent<TextureRenderer>()->SetTextureScale(1.0f);

    ///Camera
    m_CameraObj = new GameObject(L"ī�޶� ������Ʈ");

    m_CameraObj->AddComponent<Camera>();

    m_CameraObj->AddComponent<Transform>();
    m_CameraObj->GetComponent<Transform>()->SetPosition({ 0.f, 0.f });
    m_CameraObj->GetComponent<Transform>()->SetScale({ 1.f, 1.f });

    ///Mouse
    m_MouseObj = new Mouse(L"���콺");

    ///Reward
    m_FateCardReward = new Button(L"���ī�� ������ ��ư");
    m_FateCardReward->AddUITexture();
    m_FateCardReward->LoadUITexture(L"../Resource/UI/Reward_Fate_Comb.png", L"Reward_Fate_Comb");
    m_FateCardReward->GetUITransform()->SetPosition({ -390.f, 0.f });
    m_FateCardReward->ReserveButtonClickEvent(L"R_UI_FATE_CARD_BUTTON_DOWN");

    m_PlayCardReward = new Button(L"�÷���ī�� ������ ��ư");
    m_PlayCardReward->AddUITexture();
    m_PlayCardReward->LoadUITexture(L"../Resource/UI/Reward_Play_Comb.png", L"Reward_Play_Comb");
    m_PlayCardReward->GetUITransform()->SetPosition({ 0.f, 0.f });
    m_PlayCardReward->ReserveButtonClickEvent(L"R_UI_PLAY_CARD_BUTTON_DOWN");

    m_RewardIndex = RandomGenerator::GetInstance()->GetRandomNumber(0, 7983);
    m_RewardIndex %= 2;

    m_RemoveReward = new Button(L"ī�� ���� ������ ��ư");
    m_RemoveReward->AddUITexture();

    // �ݹ�Ȯ���� �� ����
    switch (m_RewardIndex)
    {
    case 0:
    {
        m_RemoveReward->LoadUITexture(L"../Resource/UI/Remove_Fate_Comb.png", L"Remove_Fate_Comb");
        break;
    }
    case 1:
    {
        m_RemoveReward->LoadUITexture(L"../Resource/UI/Remove_Play_Comb.png", L"Remove_Play_Comb");
        break;
    }
    }
    m_RemoveReward->GetUITransform()->SetPosition({ 390.f, 0.f });
    m_RemoveReward->ReserveButtonClickEvent(L"R_UI_REMOVE_BUTTON_DOWN");

    m_SkipRewardButton = new Button(L"������ ��ŵ ��ư");
    m_SkipRewardButton->AddUITexture();
    m_SkipRewardButton->LoadUITexture(L"../Resource/UI/UI_Toggle_03.png", L"UI_Toggle_03");
    m_SkipRewardButton->GetUITransform()->SetPosition({ 0.f, -395.f });
    m_SkipRewardButton->ReserveButtonClickEvent(L"R_UI_SKIP_BUTTON_DOWN");
    m_SkipRewardButton->SetUIActivate(false);

    m_BackButton = new Button(L"������ â �� �ڷΰ��� ��ư");
    m_BackButton->AddUITexture();
    m_BackButton->LoadUITexture(L"../Resource/UI/UI_Toggle_03.png", L"UI_Toggle_03");
    m_BackButton->GetUITransform()->SetPosition({ 0.f, -395.f });
    m_BackButton->ReserveButtonClickEvent(L"R_UI_BACK_BUTTON_DOWN");
    m_BackButton->SetAble(false);

    m_SelectableReward = new UI(L"���� ���� ����");
    m_SelectableReward->AddUIText();
    m_SelectableReward->AddUITexture();
    m_SelectableReward->SetUIAreaRect(400.f, 25.f);
    m_SelectableReward->LoadUITexture(L"../Resource/UI/reward_popup_text.png", L"reward_popup_text");
    m_SelectableReward->GetUIText()->SetTextAttribute(L"2", 30.f, FontWeight::BOLD);
    m_SelectableReward->GetUIText()->SetBrushColor(D2D1::ColorF::White);
    m_SelectableReward->GetUIText()->SetOffset(150.f, -3.f);
    m_SelectableReward->GetUITransform()->SetPosition({1, -216.5});

    ///Card Test
    //m_FateCardDeck = new Deck(L"�׽�Ʈ ���ī�� ��", CharacterIndex::NONE);
    //for (auto i = 0; i <= static_cast<int>(DefaultFateCard::PlayerCard::�̷��κ��ͼ�ȯ); i++)
    //{
    //    m_FateCardDeck->AddCard(m_CardFactory->CreateCard(static_cast<DefaultFateCard::PlayerCard>(i)));
    //}
    //m_FateCardDeck->IsRender(false);

    //m_PlayCardDeck = new Deck(L"�׽�Ʈ �÷���ī�� ��", CharacterIndex::NONE);
    //for (auto i = 0; i <= static_cast<int>(DefaultPlayCard::MonsterCard::����); i++)
    //{
    //    m_PlayCardDeck->AddCard(m_CardFactory->CreateCard(static_cast<DefaultPlayCard::MonsterCard>(i)));
    //}
    //m_PlayCardDeck->IsRender(false);

    Scene::EventCreateOBJ(m_BgObj);
    Scene::EventCreateOBJ(m_MouseObj);
    Scene::EventCreateOBJ(m_CameraObj);

    Scene::EventCreateOBJ(m_FateCardReward);
    Scene::EventCreateOBJ(m_PlayCardReward);
    Scene::EventCreateOBJ(m_RemoveReward);
    Scene::EventCreateOBJ(m_SkipRewardButton);
    Scene::EventCreateOBJ(m_BackButton);
    Scene::EventCreateOBJ(m_SelectableReward);

    Scene::EventCreateOBJ(m_FateCardDeck);
    Scene::EventCreateOBJ(m_PlayCardDeck);
}

void RewardScene::Exit()
{
    Scene::EventDeleteOBJ(m_FateCardDeck);
    Scene::EventDeleteOBJ(m_PlayCardDeck);

    Scene::Exit();
}

void RewardScene::Update(const float& deltaTime)
{
    Scene::Update(deltaTime);

    m_SelectableReward->GetUIText()->SetSrcText(std::to_wstring(m_RewardCount));
    m_FateCardDeck->Update(deltaTime);
    m_PlayCardDeck->Update(deltaTime);

    m_RewardFateCard = m_FateCardDeck->GetClickedCard();
    m_RewardPlayCard = m_PlayCardDeck->GetClickedCard();
}

void RewardScene::FixedUpdate(const float& deltaTime)
{
    Scene::FixedUpdate(deltaTime);
    m_FateCardDeck->FixedUpdate(deltaTime);
    m_PlayCardDeck->FixedUpdate(deltaTime);
}

void RewardScene::LateUpdate(const float& deltaTime)
{
    Scene::LateUpdate(deltaTime);
}

void RewardScene::Render(McCol::D2DRender* renderer)
{
    Scene::Render(renderer);

}

void RewardScene::FateCardRewardClick(std::any any)
{
    auto prevFate = m_FateCardDeck->GetDeck();

    // ���ī�� ������ â Ȱ��ȭ
    DEBUGPRINT("FateCardRewardClick\n");

    m_IsFateCardReward = true;

    if(m_RewardCount <= 0)
    {
        m_IsSelectableReward = false;
    }

    if (!m_IsSelectableReward)
    {
        // ������ ��ŵ ��ư�� Ȱ��ȭ�ϰ� �������� ��Ȱ��ȭ
        m_SkipRewardButton->SetUIActivate(false);
        McCol::EventSystem::GetInstance()->PublishEvent(L"UI_INTERACTIVE_FALSE");
        return;
    }

    // ������ ���� ��ư ��� ��Ȱ��ȭ
    m_FateCardReward->SetAble(false);
    m_PlayCardReward->SetAble(false);
    m_RemoveReward->SetAble(false);
    m_SkipRewardButton->SetAble(false);

    // ������ â �� �ڷΰ��� ��ư Ȱ��ȭ
    m_BackButton->SetAble(true);

    // ���ī�� ������� ī�� ����
    m_FateCardDeck->IsRender(true);

    m_RewardCount--;

}

void RewardScene::PlayCardRewardClick(std::any any)
{
    auto prevPlay = m_PlayCardDeck->GetDeck();

    // �÷���ī�� ������ â Ȱ��ȭ
    DEBUGPRINT("PlayCardRewardClick\n");

    m_IsPlayCardReward = true;

    if (m_RewardCount <= 0)
    {
        m_IsSelectableReward = false;
    }

    if (!m_IsSelectableReward)
    {
        // ������ ��ŵ ��ư�� Ȱ��ȭ�ϰ� �������� ��Ȱ��ȭ
        m_SkipRewardButton->SetUIActivate(false);
        McCol::EventSystem::GetInstance()->PublishEvent(L"UI_INTERACTIVE_FALSE");
        return;
    }

    // ������ ���� ��ư ��� ��Ȱ��ȭ
    m_FateCardReward->SetAble(false);
    m_PlayCardReward->SetAble(false);
    m_RemoveReward->SetAble(false);
    m_SkipRewardButton->SetAble(false);

    // ������ â �� �ڷΰ��� ��ư Ȱ��ȭ
    m_BackButton->SetAble(true);

    // �÷���ī�� ������� ī�� ����
    m_PlayCardDeck->IsRender(true);

    m_RewardCount--;
}

void RewardScene::RemoveRewardClick(std::any any)
{
    auto prevFReward = m_PlayCardDeck->GetDeck();
    auto prevPReward = m_PlayCardDeck->GetDeck();

    // ���� ������ â Ȱ��ȭ
    DEBUGPRINT("RemoveRewardClick\n");

    m_IsRemoveReward = true;

    if (m_RewardCount <= 0)
    {
        m_IsSelectableReward = false;
    }

    if (!m_IsSelectableReward)
    {
        // ������ ��ŵ ��ư�� Ȱ��ȭ�ϰ� �������� ��Ȱ��ȭ
        m_SkipRewardButton->SetUIActivate(false);
        McCol::EventSystem::GetInstance()->PublishEvent(L"UI_INTERACTIVE_FALSE");
        return;
    }

    // ������ ���� ��ư ��� ��Ȱ��ȭ
    m_FateCardReward->SetAble(false);
    m_PlayCardReward->SetAble(false);
    m_RemoveReward->SetAble(false);
    m_SkipRewardButton->SetAble(false);

    // ������ â �� �ڷΰ��� ��ư Ȱ��ȭ
    m_BackButton->SetAble(true);

    // �ݹ�Ȯ���� �� ����
    switch (m_RewardIndex)
    {
    case 0:
    {
        // �ڱ� �� ����
        m_FateCardDeck->IsRender(true);
        break;
    }
    case 1:
    {
        // �ڱ� �� ����
        m_PlayCardDeck->IsRender(true);
        break;
    }
    }

    m_RewardCount--;
}

void RewardScene::SkipButtonClick(std::any any)
{
    // ������ â ��ŵ�ϰ� �� ������ �̵�
    DEBUGPRINT("SkipButtonClick\n");

    // ���� â���� �ߴ� �� ��Ȱ��ȭ
    m_FateCardDeck->IsRender(false);
    m_PlayCardDeck->IsRender(false);

    // ������ ���� ��ư ��� Ȱ��ȭ
    m_FateCardReward->SetAble(true);
    m_PlayCardReward->SetAble(true);
    m_RemoveReward->SetAble(true);
    m_SkipRewardButton->SetAble(true);

    // ������ â �� �ڷΰ��� ��ư ��Ȱ��ȭ
    m_BackButton->SetAble(false);

    // ������ ���� ���θ� false ó��
    m_IsFateCardReward = false;
    m_IsPlayCardReward = false;
    m_IsRemoveReward = false;

    if (m_RewardCount <= 0)
    {
        // ������ ���� �Ұ������̹Ƿ� �� ������ �̵�
        EventSystem::GetInstance()->PublishEvent(L"CHANGE_SCENE", std::wstring(L"UI �׽�Ʈ�� �� ��"));
    }
}

void RewardScene::BackButtonClick(std::any any)
{
    // ������ â ������ �ڷΰ���
    DEBUGPRINT("BackButtonClick\n");

    // ������ ���ī�� ���� ���� �߰�
    if(m_IsFateCardReward)
    {
        m_FateCardDeck->AddCard(m_RewardFateCard);
        auto nextFate = m_FateCardDeck->GetDeck();
    }
    // ������ �÷���ī�� ���� ���� �߰�
    if(m_IsPlayCardReward)
    {
        m_PlayCardDeck->AddCard(m_RewardPlayCard);
        auto nextPlay = m_PlayCardDeck->GetDeck();
    }
    // ������ ī�� ������ ����
    if(m_IsRemoveReward)
    {
        // �ݹ�Ȯ���� �� ����
        switch (m_RewardIndex)
        {
        case 0:
        {
            // ���ī�� ����
            m_FateCardDeck->RemoveCard(m_RewardFateCard);
            auto prevFReward = m_FateCardDeck->GetDeck();

            break;
        }
        case 1:
        {
            // �÷���ī�� ����
            m_PlayCardDeck->RemoveCard(m_RewardPlayCard);
            auto prevPReward = m_PlayCardDeck->GetDeck();
            break;
        }
        }
    }

    // ���� â���� �ߴ� �� ��Ȱ��ȭ
    m_FateCardDeck->IsRender(false);
    m_PlayCardDeck->IsRender(false);

    // ������ ���� ��ư ��� Ȱ��ȭ
    m_FateCardReward->SetAble(true);
    m_PlayCardReward->SetAble(true);
    m_RemoveReward->SetAble(true);
    m_SkipRewardButton->SetAble(true);

    // ������ â �� �ڷΰ��� ��ư ��Ȱ��ȭ
    m_BackButton->SetAble(false);

    // ������ ���� ���θ� false ó��
    m_IsFateCardReward = false;
    m_IsPlayCardReward = false;
    m_IsRemoveReward = false;
}
