#include "TestMain.h"

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
#include "../Engine/SoundSystem.h"

#include "../Engine/UI.h"
#include "../Engine/Button.h"
#include "../Engine/Panel.h"

#include "Mouse.h"

#include "CardFactory.h"
#include "Card.h"
#include "FateCard.h"
#include "PlayCard.h"
#include "Deck.h"
#include "GameManager.h"

using namespace McCol;

TestMain::TestMain()
    : Scene(L"UI �׽�Ʈ�� ���� ��")
    , m_BgObj(nullptr)
    , m_CameraObj(nullptr)
{
    McCol::EventSystem::GetInstance()->Subscribe(L"UI_PLAY_BUTTON_DOWN", MakeListenerInfo(&TestMain::PlayButtonClickEvent));
    McCol::EventSystem::GetInstance()->Subscribe(L"UI_ARCHIVE_BUTTON_DOWN", MakeListenerInfo(&TestMain::ArchiveButtonClickEvent));
    McCol::EventSystem::GetInstance()->Subscribe(L"UI_EXIT_BUTTON_DOWN", MakeListenerInfo(&TestMain::ExitButtonClickEvent));
    McCol::EventSystem::GetInstance()->Subscribe(L"UI_BACK_BUTTON_DOWN", MakeListenerInfo(&TestMain::BackButtonClickEvent));
    McCol::EventSystem::GetInstance()->Subscribe(L"UI_FATE_ARCHIVE_BUTTON_DOWN", MakeListenerInfo(&TestMain::FateCardButtonOnEvent));
    McCol::EventSystem::GetInstance()->Subscribe(L"UI_PLAY_ARCHIVE_BUTTON_DOWN", MakeListenerInfo(&TestMain::PlayCardButtonOnEvent));
    McCol::EventSystem::GetInstance()->Subscribe(L"UI_PAGE_LEFT_BUTTON_DOWN", MakeListenerInfo(&TestMain::PageLeftButtonOnEvent));
    McCol::EventSystem::GetInstance()->Subscribe(L"UI_PAGE_RIGHT_BUTTON_DOWN", MakeListenerInfo(&TestMain::PageRightButtonOnEvent));

    McCol::EventSystem::GetInstance()->Subscribe(L"UI_PLAY_BUTTON_ON", MakeListenerInfo(&TestMain::PlayButtonOnEvent));
    McCol::EventSystem::GetInstance()->Subscribe(L"UI_ARCHIVE_BUTTON_ON", MakeListenerInfo(&TestMain::ArchiveButtonOnEvent));
    McCol::EventSystem::GetInstance()->Subscribe(L"UI_EXIT_BUTTON_ON", MakeListenerInfo(&TestMain::ExitButtonOnEvent));
    McCol::EventSystem::GetInstance()->Subscribe(L"UI_PLAY_BUTTON_OUT", MakeListenerInfo(&TestMain::PlayButtonOutEvent));
    McCol::EventSystem::GetInstance()->Subscribe(L"UI_ARCHIVE_BUTTON_OUT", MakeListenerInfo(&TestMain::ArchiveButtonOutEvent));
    McCol::EventSystem::GetInstance()->Subscribe(L"UI_EXIT_BUTTON_OUT", MakeListenerInfo(&TestMain::ExitButtonOutEvent));
}

TestMain::~TestMain()
{
}

void TestMain::Enter()
{
    SoundSystem::GetInstance()->Replay("BGM_01");
    GameManager::GetInstance()->SetMapIndex(0);
    ///Background
    m_BgObj = new GameObject(L"���", Layer::BACKGROUND);
    m_BgObj->AddComponent<Transform>();
    m_BgObj->GetComponent<Transform>()->SetPosition({ 0.f, 0.f });
    m_BgObj->GetComponent<Transform>()->SetScale({ 1.0f, 1.0f });

    m_BgObj->AddComponent<TextureRenderer>();
    m_BgObj->GetComponent<TextureRenderer>()->SetBitmap(D2DTextureSystem::GetInstance()->LoadTexture(L"../Resource/BG/BG_Title_Logo.png", L"BG_Title_Logo"));
    m_BgObj->GetComponent<TextureRenderer>()->SetTextureScale(1.0f);

    ///Camera
    m_CameraObj = new GameObject(L"ī�޶� ������Ʈ");

    m_CameraObj->AddComponent<Camera>();

    m_CameraObj->AddComponent<Transform>();
    m_CameraObj->GetComponent<Transform>()->SetPosition({ 0.f, 0.f });
    m_CameraObj->GetComponent<Transform>()->SetScale({ 1.f, 1.f });

    m_CameraObj->AddComponent<PrimitiveRenderer>();
    m_CameraObj->GetComponent<PrimitiveRenderer>()->SetPmRectangle(200.f, 200.f);
    m_CameraObj->GetComponent<PrimitiveRenderer>()->SetPmScale(1.0f);
    m_CameraObj->GetComponent<PrimitiveRenderer>()->SetPmBrushColor(D2D1::ColorF::Red);

    ///PlayButton
    m_PlayButton = new Button(L"UI ���� �÷��� ��ư");
    m_PlayButton->AddUITexture();
    m_PlayButton->LoadUITexture(L"../Resource/UI/StartScene_Start.png", L"StartScene_Start");
    m_PlayButton->GetUITransform()->SetPosition({ 360.f, -222.5f });
    m_PlayButton->ReserveButtonClickEvent(L"UI_PLAY_BUTTON_DOWN");
    m_PlayButton->ReserveButtonOnEvent(L"UI_PLAY_BUTTON_ON");
    m_PlayButton->ReserveButtonOutEvent(L"UI_PLAY_BUTTON_OUT");

    // TODO : ȭ��ǥ �ؽ�ó �ֱ�
    m_PlayButtonArrow = new UI(L"UI ���� �÷��� ��ư ȭ��ǥ");
    m_PlayButtonArrow->AddUITexture();
    m_PlayButtonArrow->LoadUITexture(L"../Resource/UI/StartScene_Start_mouseover.png", L"StartScene_Start_mouseover");
    m_PlayButtonArrow->GetUITransform()->SetPosition({ 360.f, -222.5f });
    m_PlayButtonArrow->SetAble(false);

    ///ArchiveButton
    m_ArchiveButton = new Button(L"UI ���� ��ī�̺� ��ư");
    m_ArchiveButton->AddUITexture();
    m_ArchiveButton->LoadUITexture(L"../Resource/UI/StartScene_Archive.png", L"StartScene_Archive");
    m_ArchiveButton->GetUITransform()->SetPosition({ 360.f, -322.5f });
    m_ArchiveButton->ReserveButtonClickEvent(L"UI_ARCHIVE_BUTTON_DOWN");
    m_ArchiveButton->ReserveButtonOnEvent(L"UI_ARCHIVE_BUTTON_ON");
    m_ArchiveButton->ReserveButtonOutEvent(L"UI_ARCHIVE_BUTTON_OUT");

    m_ArchiveButtonArrow = new UI(L"UI ���� ��ī�̺� ��ư ȭ��ǥ");
    m_ArchiveButtonArrow->AddUITexture();
    m_ArchiveButtonArrow->LoadUITexture(L"../Resource/UI/StartScene_Archive_mouseover.png", L"StartScene_Archive_mouseover");
    m_ArchiveButtonArrow->GetUITransform()->SetPosition({ 360.f, -322.5f });
    m_ArchiveButtonArrow->SetAble(false);

    ///ArchivePopUp
    m_PopUpFrame = new UI(L"�˾� ������");
    m_PopUpFrame->AddUITexture();
    m_PopUpFrame->LoadUITexture(L"../Resource/UI/UI_POPUP_Body.png", L"UI_POPUP_Body");
    m_PopUpFrame->GetUITransform()->SetPosition({ -5.f, 0.f });
    m_PopUpFrame->SetAble(false);

    ///Fatecard Archive Popup
    m_FateCardArchiveButton = new Button(L"���ī�� ��ī�̺� ��ư");
    m_FateCardArchiveButton->AddUITexture();
    m_FateCardArchiveButton->LoadUITexture(L"../Resource/UI/UI_Archive_Destiny_En.png", L"UI_Archive_Destiny_En");
    m_FateCardArchiveButton->GetUITransform()->SetPosition({ -705.f, 435.f });
    m_FateCardArchiveButton->ReserveButtonClickEvent(L"UI_FATE_ARCHIVE_BUTTON_DOWN");
    m_FateCardArchiveButton->SetAble(false);

    ///Playcard Archive Popup
    m_PlayCardArchiveButton = new Button(L"�÷���ī�� ��ī�̺� ��ư");
    m_PlayCardArchiveButton->AddUITexture();
    m_PlayCardArchiveButton->LoadUITexture(L"../Resource/UI/UI_Archive_Play_Dis.png", L"UI_Archive_Play_Dis");
    m_PlayCardArchiveButton->GetUITransform()->SetPosition({ -390.f, 435.f });
    m_PlayCardArchiveButton->ReserveButtonClickEvent(L"UI_PLAY_ARCHIVE_BUTTON_DOWN");
    m_PlayCardArchiveButton->SetAble(false);

    m_BackButton = new Button(L"���ư��� ��ư");
    m_BackButton->AddUITexture();
    m_BackButton->LoadUITexture(L"../Resource/UI/UI_Toggle_02.png", L"UI_Toggle_02");
    m_BackButton->GetUITransform()->SetPosition({ -780.f, -395.f });
    m_BackButton->ReserveButtonClickEvent(L"UI_BACK_BUTTON_DOWN");
    m_BackButton->SetAble(false);

    ///ExitButton
    m_ExitButton = new Button(L"UI ���� ���� ��ư");
    m_ExitButton->AddUITexture();
    m_ExitButton->LoadUITexture(L"../Resource/UI/StartScene_Quit.png", L"StartScene_Quit");
    m_ExitButton->GetUITransform()->SetPosition({ 360.f, -425.0f });
    m_ExitButton->ReserveButtonClickEvent(L"UI_EXIT_BUTTON_DOWN");
    m_ExitButton->ReserveButtonOnEvent(L"UI_EXIT_BUTTON_ON");
    m_ExitButton->ReserveButtonOutEvent(L"UI_EXIT_BUTTON_OUT");

    m_ExitButtonArrow = new UI(L"UI ���� ���� ��ư ȭ��ǥ");
    m_ExitButtonArrow->AddUITexture();
    m_ExitButtonArrow->LoadUITexture(L"../Resource/UI/StartScene_Quit_mouseover.png", L"StartScene_Quit_mouseover");
    m_ExitButtonArrow->GetUITransform()->SetPosition({ 360.f, -425.f });
    m_ExitButtonArrow->SetAble(false);

    ///Page Left / Right Button
    m_PageLeftButton = new Button(L"������ ���� ��ư");
    m_PageLeftButton->AddUITexture();
    m_PageLeftButton->LoadUITexture(L"../Resource/UI/UI_Page_Left.png", L"UI_Page_Left");
    m_PageLeftButton->GetUITransform()->SetPosition({ -130.f, -469.f });
    m_PageLeftButton->ReserveButtonClickEvent(L"UI_PAGE_LEFT_BUTTON_DOWN");
    m_PageLeftButton->SetAble(false);

    m_PageRightButton = new Button(L"������ ������ ��ư");
    m_PageRightButton->AddUITexture();
    m_PageRightButton->LoadUITexture(L"../Resource/UI/UI_Page_Right.png", L"UI_Page_Right");
    m_PageRightButton->GetUITransform()->SetPosition({ 130.f, -469.f });
    m_PageRightButton->ReserveButtonClickEvent(L"UI_PAGE_RIGHT_BUTTON_DOWN");
    m_PageRightButton->SetAble(false);

    ///Archive Card Test
    m_ArchiveCardTest = new Panel(L"��ī�̺� ī�� �׽�Ʈ");
    m_ArchiveCardTest->AddUITexture();
    m_ArchiveCardTest->LoadUITexture(L"../Resource/FateCardExample.png", L"FateCardExample");
    m_ArchiveCardTest->GetUITransform()->SetPosition({ 0.f, 0.f });
    m_ArchiveCardTest->ReservePanelOnEvent(L"UI_PANEL_TEST_ON");
    m_ArchiveCardTest->ReservePanelOutEvent(L"UI_PANEL_TEST_OUT");
    m_ArchiveCardTest->SetPanelOffset(150.f, 0.f);

    ///Mouse
    m_MouseObj = new Mouse(L"���콺");
    m_CardFactory = new CardFactory;

    ///FateCard, PlayCard Deck ����
    m_PlayCardDeck = new Deck(L"��ī�̺�� ���ī�� ��", CharacterIndex::NONE);
    for (auto i = 0; i <= static_cast<int>(DefaultPlayCard::PlayerCard::�����κ���Ʈ); i++)
    {
        m_PlayCardDeck->AddCard(m_CardFactory->CreateCard(static_cast<DefaultPlayCard::PlayerCard>(i)));
    }
    for (auto i = 0; i <= static_cast<int>(DefaultPlayCard::MonsterCard::���ü����); i++)
    {
        m_PlayCardDeck->AddCard(m_CardFactory->CreateCard(static_cast<DefaultPlayCard::MonsterCard>(i)));
    }
    m_PlayCardDeck->SetCurrentPageIndex(m_PlayCardPageIndex);
    m_PlayCardDeck->IsRender(false);

    m_FateCardDeck = new Deck(L"��ī�̺�� �÷���ī�� ��", CharacterIndex::NONE);
    for (auto i = 0; i <= static_cast<int>(ArchivePlayCard::���ü����); i++)
    {
        m_FateCardDeck->AddCard(m_CardFactory->CreateCard(static_cast<DefaultFateCard::PlayerCard>(i)));
    }
    m_FateCardDeck->SetCurrentPageIndex(m_FateCardPageIndex);
    m_FateCardDeck->IsRender(false);


    Scene::EventCreateOBJ(m_BgObj);
    Scene::EventCreateOBJ(m_MouseObj);
    Scene::EventCreateOBJ(m_CameraObj);

    Scene::EventCreateOBJ(m_PlayButton);
    Scene::EventCreateOBJ(m_ArchiveButton);
    Scene::EventCreateOBJ(m_ExitButton);

    Scene::EventCreateOBJ(m_PlayButtonArrow);
    Scene::EventCreateOBJ(m_ArchiveButtonArrow);
    Scene::EventCreateOBJ(m_ExitButtonArrow);

    Scene::EventCreateOBJ(m_FateCardArchiveButton);
    Scene::EventCreateOBJ(m_PlayCardArchiveButton);
    Scene::EventCreateOBJ(m_PopUpFrame);

    Scene::EventCreateOBJ(m_PageLeftButton);
    Scene::EventCreateOBJ(m_PageRightButton);

    Scene::EventCreateOBJ(m_BackButton);

    Scene::EventCreateOBJ(m_FateCardDeck);
    Scene::EventCreateOBJ(m_PlayCardDeck);
}

void TestMain::Exit()
{
    Scene::Exit();

    delete m_CardFactory;
}

void TestMain::Update(const float& deltaTime)
{
    Scene::Update(deltaTime);
    m_FateCardDeck->Update(deltaTime);
    m_PlayCardDeck->Update(deltaTime);
}

void TestMain::FixedUpdate(const float& deltaTime)
{
    Scene::FixedUpdate(deltaTime);
    m_FateCardDeck->FixedUpdate(deltaTime);
    m_PlayCardDeck->FixedUpdate(deltaTime);
}

void TestMain::LateUpdate(const float& deltaTime)
{
    Scene::LateUpdate(deltaTime);
}

void TestMain::Render(McCol::D2DRender* renderer)
{
    Scene::Render(renderer);
}

void TestMain::PlayButtonClickEvent(std::any any)
{
    // �÷��̹�ư Ŭ�� �� �߻��ϴ� �̺�Ʈ
    // �� ������ �̵�
    DEBUGPRINT("PlayButtonEvent\n");

    EventSystem::GetInstance()->PublishEvent(L"CHANGE_SCENE", std::wstring(L"UI �׽�Ʈ�� �� ��"));
}

void TestMain::ArchiveButtonClickEvent(std::any any)
{
    // ��ī�̺��ư Ŭ�� �� �߻��ϴ� �̺�Ʈ
    DEBUGPRINT("ArchiveButtonEvent\n");

    m_ArchiveButtonArrow->SetAble(false);

    // ��ī�̺� �˾����� �̵�
    m_PopUpFrame->SetAble(true);

    // �˾� ����
    m_FateCardArchiveButton->SetAble(true);
    m_PlayCardArchiveButton->SetAble(true);
    m_PageLeftButton->SetAble(true);
    m_PageRightButton->SetAble(true);
    m_BackButton->SetAble(true);
    m_FateCardDeck->IsRender(true);
    m_PlayCardDeck->IsRender(false);
    m_IsFateCardAble = true;
    m_IsPlayCardAble = false;

    // ��ī�̺� �˾��� ��ư�� ��ġ ���ɻ��·� �����
    m_FateCardArchiveButton->SetUIActivate(false);
    m_PlayCardArchiveButton->SetUIActivate(false);
    m_PageLeftButton->SetUIActivate(false);
    m_PageRightButton->SetUIActivate(false);
    m_BackButton->SetUIActivate(false);

    // �ٸ� UI���� ��ġ �Ұ��� ���·� �����.
    McCol::EventSystem::GetInstance()->PublishEvent(L"UI_INTERACTIVE_FALSE");
}

void TestMain::ExitButtonClickEvent(std::any any)
{
    // �����ư Ŭ�� �� �߻��ϴ� �̺�Ʈ
    // ���� ����
    DEBUGPRINT("ExitButtonEvent\n");

    McCol::EventSystem::GetInstance()->PublishEvent(L"GAME_EXIT");
}

void TestMain::BackButtonClickEvent(std::any any)
{
    // ��ī�̺� �˾����� ���ư��� ��ư Ŭ�� �� �߻��ϴ� �̺�Ʈ
    DEBUGPRINT("BackButtonEvent\n");

    // ��ī�̺� �˾� ��� ��� SetAble(false)�ϰ�
    m_PopUpFrame->SetAble(false);
    m_FateCardArchiveButton->SetAble(false);
    m_PlayCardArchiveButton->SetAble(false);
    m_PageLeftButton->SetAble(false);
    m_PageRightButton->SetAble(false);
    m_BackButton->SetAble(false);
    m_FateCardDeck->IsRender(false);
    m_PlayCardDeck->IsRender(false);
    m_IsFateCardAble = false;
    m_IsPlayCardAble = false;

    // ��� UI ��ġ ���� ���·� �����.
    McCol::EventSystem::GetInstance()->PublishEvent(L"UI_INTERACTIVE_TRUE", nullptr);
}

void TestMain::PlayButtonOnEvent(std::any any)
{
    // �÷��� ��ư�� ���콺 �÷��� �� �̺�Ʈ
    DEBUGPRINT("PlayButtonOnEvent\n");
    m_PlayButtonArrow->SetAble(true);
}

void TestMain::PlayButtonOutEvent(std::any any)
{
    // �÷��� ��ư���� ���콺 ������ �� �̺�Ʈ
    DEBUGPRINT("PlayButtonOutEvent\n");
    m_PlayButtonArrow->SetAble(false);
}

void TestMain::ArchiveButtonOnEvent(std::any any)
{
    // ��ī�̺� ��ư�� ���콺 �÷��� �� �̺�Ʈ
    DEBUGPRINT("ArchiveButtonOnEvent\n");
    m_ArchiveButtonArrow->SetAble(true);
}

void TestMain::ArchiveButtonOutEvent(std::any any)
{
    // ��ī�̺� ��ư���� ���콺 ������ �� �̺�Ʈ
    DEBUGPRINT("ArchiveButtonOutEvent\n");
    m_ArchiveButtonArrow->SetAble(false);
}

void TestMain::ExitButtonOnEvent(std::any any)
{
    // �������� ��ư�� ���콺 �÷��� �� �̺�Ʈ
    DEBUGPRINT("ExitButtonOnEvent\n");
    m_ExitButtonArrow->SetAble(true);
}

void TestMain::ExitButtonOutEvent(std::any any)
{
    // �������� ��ư���� ���콺 ������ �� �̺�Ʈ
    DEBUGPRINT("ExitButtonOutEvent\n");
    m_ExitButtonArrow->SetAble(false);
}

void TestMain::FateCardButtonOnEvent(std::any any)
{
    // ��ī�̺� �˾����� ���ī�� ��ư ���� �� �߻��ϴ� �̺�Ʈ
    DEBUGPRINT("��ī�̺� �˾����� ���ī�� ����\n");

    m_IsFateCardAble = true;
    m_IsPlayCardAble = false;

    m_PlayCardDeck->IsRender(m_IsPlayCardAble);
    m_FateCardDeck->IsRender(m_IsFateCardAble);

    m_FateCardArchiveButton->LoadUITexture(L"../Resource/UI/UI_Archive_Destiny_En.png", L"UI_Archive_Destiny_En");
    m_PlayCardArchiveButton->LoadUITexture(L"../Resource/UI/UI_Archive_Play_Dis.png", L"UI_Archive_Play_Dis");
}

void TestMain::PlayCardButtonOnEvent(std::any any)
{
    // ��ī�̺� �˾����� �÷���ī�� ��ư ���� �� �߻��ϴ� �̺�Ʈ
    DEBUGPRINT("��ī�̺� �˾����� �÷���ī�� ����\n");

    m_IsPlayCardAble = true;
    m_IsFateCardAble = false;

    m_FateCardDeck->IsRender(m_IsFateCardAble);
    m_PlayCardDeck->IsRender(m_IsPlayCardAble);

    m_PlayCardArchiveButton->LoadUITexture(L"../Resource/UI/UI_Archive_Play_En.png", L"UI_Archive_Play_En");
    m_FateCardArchiveButton->LoadUITexture(L"../Resource/UI/UI_Archive_Destiny_Dis.png", L"UI_Archive_Destiny_Dis");
}

void TestMain::PageLeftButtonOnEvent(std::any any)
{
    // ��ī�̺� �˾����� ������ ���� ��ư ���� �� �߻��ϴ� �̺�Ʈ

    if (m_IsFateCardAble)
    {
        DEBUGPRINT("���ī�� ������ ���� ��ư\n");
        m_FateCardPageIndex--;

        if (m_FateCardPageIndex < 1)
        {
            m_FateCardPageIndex = 1;
        }
        m_FateCardDeck->SetCurrentPageIndex(m_FateCardPageIndex);
    }

    if (m_IsPlayCardAble)
    {
        DEBUGPRINT("�÷���ī�� ������ ���� ��ư\n");
        m_PlayCardPageIndex--;

        if (m_PlayCardPageIndex < 1)
        {
            m_PlayCardPageIndex = 1;
        }
        m_PlayCardDeck->SetCurrentPageIndex(m_PlayCardPageIndex);
    }

    DEBUGPRINT("������ ���� ��ư\n");
    DEBUGPRINT("%d", m_PlayCardPageIndex);
}

void TestMain::PageRightButtonOnEvent(std::any any)
{
    // ��ī�̺� �˾����� ������ ������ ��ư ���� �� �߻��ϴ� �̺�Ʈ

    if (m_IsFateCardAble)
    {
        DEBUGPRINT("���ī�� ������ ������ ��ư\n");
        m_FateCardPageIndex++;

        if (m_FateCardPageIndex > 3)
        {
            m_FateCardPageIndex = 3;
        }
        m_FateCardDeck->SetCurrentPageIndex(m_FateCardPageIndex);
    }

    if (m_IsPlayCardAble)
    {
        DEBUGPRINT("�÷���ī�� ������ ������ ��ư\n");
        m_PlayCardPageIndex++;

        if (m_PlayCardPageIndex > 3)
        {
            m_PlayCardPageIndex = 3;
        }
        m_PlayCardDeck->SetCurrentPageIndex(m_PlayCardPageIndex);
    }

    DEBUGPRINT("������ ������ ��ư\n");
    DEBUGPRINT("%d", m_PlayCardPageIndex);
}

