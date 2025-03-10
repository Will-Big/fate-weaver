#include "TestMap.h"
#include "GameManager.h"

#include "../Engine/Macro.h"
#include "../Engine/InputSystem.h"
#include "../RenderEngine/D2DTextureSystem.h"

#include "../Engine/GameObject.h"
#include "../Engine/Transform.h"
#include "../Engine/Camera.h"

#include "../Engine/BaseRenderer.h"
#include "../Engine/TextureRenderer.h"
#include "../Engine/PrimitiveRenderer.h"
#include "../Engine/TextRenderer.h"

#include "../Engine/UI.h"
#include "../Engine/Button.h"
#include "../Engine/PopUp.h"
#include "../Engine/BattleButton.h"
#include "../Engine/RandomButton.h"
#include "../Engine/CrackButton.h"

#include "Mouse.h"

#include "../Engine/RandomGenerator.h"
#include "../Engine/SoundSystem.h"

using namespace McCol;

TestMap::TestMap()
    : Scene(L"UI �׽�Ʈ�� �� ��")
{
    ///Set Battle Scene
    EventSystem::GetInstance()->Subscribe(L"Battle Button Down", MakeListenerInfo(&TestMap::BattleStart));

    ///UI Upper Button Event
    McCol::EventSystem::GetInstance()->Subscribe(L"M_UI_UPPER_FDECK_BUTTON_DOWN", MakeListenerInfo(&TestMap::UpperFdeckOn));
    McCol::EventSystem::GetInstance()->Subscribe(L"M_UI_UPPER_PDECK_DOWN", MakeListenerInfo(&TestMap::UpperPdeckOn));
    McCol::EventSystem::GetInstance()->Subscribe(L"M_UI_UPPER_EXIT_DOWN", MakeListenerInfo(&TestMap::UpperExitOn));

    ///Tutorial Popup Event
    McCol::EventSystem::GetInstance()->Subscribe(L"M_UI_TUTORIAL_BUTTON_DOWN", MakeListenerInfo(&TestMap::UpperTutorialOn));
    McCol::EventSystem::GetInstance()->Subscribe(L"M_UI_TUTORIAL_LEFT_BUTTON_CLICK", MakeListenerInfo(&TestMap::TutorialLeftButtonOn));
    McCol::EventSystem::GetInstance()->Subscribe(L"M_UI_TUTORIAL_RIGHT_BUTTON_CLICK", MakeListenerInfo(&TestMap::TutorialRightButtonOn));
    McCol::EventSystem::GetInstance()->Subscribe(L"M_UI_TUTORIAL_BACK_BUTTON_CLICK", MakeListenerInfo(&TestMap::TutorialBackButtonOn));

    ///Random Encounter Event
    
    // Random ��ư ������ �� ����� ����ǰ� �米�� �ǽ� �ݹ�Ȯ���� �⿬
    EventSystem::GetInstance()->Subscribe(L"Random Button Down", MakeListenerInfo(&TestMap::RandomStart));
    // Crack ��ư ������ �� �ð��� ƴ�� �⿬
    EventSystem::GetInstance()->Subscribe(L"Crack Button Down", MakeListenerInfo(&TestMap::CrackStart));      

    //�ð��� ƴ��
    EventSystem::GetInstance()->Subscribe(L"M_UI_NEXUS_FIRST_BUTTON_CLICK", MakeListenerInfo(&TestMap::NexusFirstButtonOn));
    EventSystem::GetInstance()->Subscribe(L"M_UI_NEXUS_SECOND_BUTTON_CLICK", MakeListenerInfo(&TestMap::NexusSecondButtonOn));

    //�米�� �ǽ�
    EventSystem::GetInstance()->Subscribe(L"M_UI_CLUT_FIRST_BUTTON_CLICK", MakeListenerInfo(&TestMap::NexusFirstButtonOn));
    EventSystem::GetInstance()->Subscribe(L"M_UI_CLUT_SECOND_BUTTON_CLICK", MakeListenerInfo(&TestMap::NexusSecondButtonOn));
    EventSystem::GetInstance()->Subscribe(L"M_UI_CLUT_THIRD_BUTTON_CLICK", MakeListenerInfo(&TestMap::ClutThirdButtonOn));

    //����� �����
    EventSystem::GetInstance()->Subscribe(L"M_UI_LAB_FIRST_BUTTON_CLICK", MakeListenerInfo(&TestMap::LabFirstButtonOn));
    EventSystem::GetInstance()->Subscribe(L"M_UI_LAB_SECOND_BUTTON_CLICK", MakeListenerInfo(&TestMap::LabSecondButtonOn));
    EventSystem::GetInstance()->Subscribe(L"M_UI_LAB_THIRD_BUTTON_CLICK", MakeListenerInfo(&TestMap::LabThirdButtonOn));
}

TestMap::~TestMap()
{
}

void TestMap::Enter()
{
    ///Background
    m_BgObj = new GameObject(L"���");
    m_BgObj->AddComponent<Transform>();
    m_BgObj->GetComponent<Transform>()->SetPosition({ 0.f, 0.f });
    m_BgObj->GetComponent<Transform>()->SetScale({ 1.0f, 1.0f });

    m_BgObj->AddComponent<TextureRenderer>();
    m_BgObj->GetComponent<TextureRenderer>()->SetBitmap(D2DTextureSystem::GetInstance()->LoadTexture(L"../Resource/Background/Map_Bg.png", L"Map_Bg"));
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

    ///UI Upper
    UIUpperSector = new UI(L"UI ��ܹ�");
    UIUpperSector->AddUITexture();
    UIUpperSector->SetUIAreaRect(1920.f, 70.f);
    UIUpperSector->LoadUITexture(L"../Resource/UI/UI_UpperSector.png", L"UI_UpperSector");
    UIUpperSector->GetUITransform()->SetPosition({ 0.f, 505.f });

    UIUpperIconLogo = new UI(L"UI ��ܹ� �ΰ�");
    UIUpperIconLogo->AddUITexture();
    UIUpperIconLogo->SetUIAreaRect(170.f, 65.f);
    UIUpperIconLogo->LoadUITexture(L"../Resource/UI/UI_Upperlogo.png", L"UI_Upperlogo");
    UIUpperIconLogo->GetUITexture()->SetTextureScale(1.0f);
    UIUpperIconLogo->GetUITransform()->SetPosition({ -875.f, 505.f });

    UIUpperIconHP = new UI(L"UI ��ܹ� HP");
    UIUpperIconHP->AddUITexture();
    UIUpperIconHP->SetUIAreaRect(45.f, 40.f);
    UIUpperIconHP->LoadUITexture(L"../Resource/icon/UI_Upper_Icon_HP.png", L"UI_Upper_Icon_HP");
    UIUpperIconHP->GetUITransform()->SetPosition({ -677.5f, 505.f });

    UIUpperHPText = new UI(L"UI ��ܹ� HP �ؽ�Ʈ");
    UIUpperHPText->AddUIText();
    UIUpperHPText->SetUIAreaRect(75.f, 19.f);
    auto curHp = GameManager::GetInstance()->GetCurHealth();
    auto maxHp = GameManager::GetInstance()->GetMaxHealth();
    UIUpperHPText->SetUIText(std::to_wstring(curHp) + L" / " + std::to_wstring(maxHp), 18.f, FontWeight::BOLD, D2D1::ColorF::White);
    UIUpperHPText->GetUITransform()->SetPosition({ -597.5f, 505.f });

    //UIUpperIconNowFloor = new UI(L"UI ��ܹ� ��");
    //UIUpperIconNowFloor->AddUITexture();
    //UIUpperIconNowFloor->SetUIAreaRect(55.f, 55.f);
    //UIUpperIconNowFloor->LoadUITexture(L"../Resource/icon/UI_Upper_Icon_NowFloor.png", L"UI_Upper_Icon_NowFloor");
    //UIUpperIconNowFloor->GetUITransform()->SetPosition({ 242.5f, 502.5f });
    //
    //UIUpperFloorText = new UI(L"UI ��ܹ� �� �ؽ�Ʈ");
    //UIUpperFloorText->AddUIText();
    //UIUpperFloorText->SetUIAreaRect(46.f, 25.f);
    //UIUpperFloorText->SetUIText(L"4��", 18.f, FontWeight::BOLD, D2D1::ColorF::White);
    //UIUpperFloorText->GetUITransform()->SetPosition({ 298.f, 502.5f });

    UIUpperTutorial = new Button(L"UI ��ܹ� Ʃ�丮��");
    UIUpperTutorial->AddUITexture();
    UIUpperTutorial->SetUIAreaRect(55.f, 55.f);
    UIUpperTutorial->LoadUITexture(L"../Resource/icon/UI_Upper_Tutorial.png", L"UI_Upper_Tutorial");
    UIUpperTutorial->GetUITransform()->SetPosition({ 482.5f, 502.5f });
    UIUpperTutorial->ReserveButtonClickEvent(L"M_UI_TUTORIAL_BUTTON_DOWN");
    UIUpperTutorial->SetUIActivate(false);

    UIUpperFdeck = new Button(L"UI ��ܹ� ���ī�� ��");
    UIUpperFdeck->AddUITexture();
    UIUpperFdeck->SetUIAreaRect(65.f, 55.f);
    UIUpperFdeck->LoadUITexture(L"../Resource/icon/UI_Upper_Fdeck.png", L"UI_Upper_Fdeck");
    UIUpperFdeck->GetUITransform()->SetPosition({ 732.5f, 502.5f });
    UIUpperFdeck->ReserveButtonClickEvent(L"M_M_UI_UPPER_FDECK_BUTTON_DOWN");
    UIUpperFdeck->SetUIActivate(false);

    UIUpperPdeck = new Button(L"UI ��ܹ� �÷���ī�� ��");
    UIUpperPdeck->AddUITexture();
    UIUpperPdeck->SetUIAreaRect(65.f, 55.f);
    UIUpperPdeck->LoadUITexture(L"../Resource/icon/UI_Upper_Pdeck.png", L"UI_Upper_Pdeck");
    UIUpperPdeck->GetUITransform()->SetPosition({ 812.5f, 502.5f });
    UIUpperPdeck->ReserveButtonClickEvent(L"M_UI_UPPER_PDECK_DOWN");
    UIUpperPdeck->SetUIActivate(false);

    UIUpperExit = new Button(L"UI ��ܹ� ��������");
    UIUpperExit->AddUITexture();
    UIUpperExit->SetUIAreaRect(55.f, 55.f);
    UIUpperExit->LoadUITexture(L"../Resource/icon/UI_Upper_Exit.png", L"UI_Upper_Exit");
    UIUpperExit->GetUITransform()->SetPosition({ 907.5f, 502.5f });
    UIUpperExit->ReserveButtonClickEvent(L"M_UI_UPPER_EXIT_DOWN");
    UIUpperExit->SetUIActivate(false);

    ///Map Whole Frame
    m_WholeFrame = new UI(L"��ü ������");
    m_WholeFrame->AddUITexture();
    m_WholeFrame->LoadUITexture(L"../Resource/UI/UI_POPUP_Body.png", L"UI_POPUP_Body");
    m_WholeFrame->GetUITransform()->SetPosition({ -5.f, -25.f });

    ///Map Frame
    m_MapFrame = new UI(L"�� ������");
    m_MapFrame->AddUITexture();
    m_MapFrame->LoadUITexture(L"../Resource/Map/Map_1.png", L"Map_1");
    m_MapFrame->GetUITransform()->SetPosition({ -6.f, -10.f });

    ///Map Icon
    m_Stage1 = new BattleButton(L"�� ������1", BattleIconType::Monster, BattleStageType::START, 1);
    m_Stage1->GetUITransform()->SetPosition({ -713.f, 9.5f });
    m_Stage1->ReserveButtonClickEvent(L"UI_MAP1_BUTTON_DOWN");
    m_Stage1->ReserveButtonOnEvent(L"UI_MAP1_BUTTON_ON");
    m_Stage1->ReserveButtonOutEvent(L"UI_MAP1_BUTTON_OUT");

    m_Stage2 = new BattleButton(L"�� ������2", BattleIconType::Monster, BattleStageType::FIRST, 2);
    m_Stage2->GetUITransform()->SetPosition({ -579.f, 110.5f });
    m_Stage2->ReserveButtonClickEvent(L"UI_MAP2_BUTTON_DOWN");
    m_Stage2->ReserveButtonOnEvent(L"UI_MAP2_BUTTON_ON");
    m_Stage2->ReserveButtonOutEvent(L"UI_MAP2_BUTTON_OUT");

    m_Stage3 = new BattleButton(L"�� ������3", BattleIconType::Monster, BattleStageType::FIRST, 3);
    m_Stage3->GetUITransform()->SetPosition({ -461.f, 174.5f });
    m_Stage3->ReserveButtonClickEvent(L"UI_MAP3_BUTTON_DOWN");
    m_Stage3->ReserveButtonOnEvent(L"UI_MAP3_BUTTON_ON");
    m_Stage3->ReserveButtonOutEvent(L"UI_MAP3_BUTTON_OUT");

    m_Stage4 = new BattleButton(L"�� ������4", BattleIconType::Monster, BattleStageType::SECOND, 4);
    m_Stage4->GetUITransform()->SetPosition({ -310.5f, 210.f });
    m_Stage4->ReserveButtonClickEvent(L"UI_MAP4_BUTTON_DOWN");
    m_Stage4->ReserveButtonOnEvent(L"UI_MAP4_BUTTON_ON");
    m_Stage4->ReserveButtonOutEvent(L"UI_MAP4_BUTTON_OUT");

    m_Stage5 = new BattleButton(L"�� ������5", BattleIconType::Monster, BattleStageType::SECOND, 5);
    m_Stage5->GetUITransform()->SetPosition({ -145.f, 191.5f });
    m_Stage5->ReserveButtonClickEvent(L"UI_MAP5_BUTTON_DOWN");
    m_Stage5->ReserveButtonOnEvent(L"UI_MAP5_BUTTON_ON");
    m_Stage5->ReserveButtonOutEvent(L"UI_MAP5_BUTTON_OUT");

    m_Stage6 = new BattleButton(L"�� ������6", BattleIconType::Elite, BattleStageType::ELITE, 6);
    m_Stage6->GetUITransform()->SetPosition({ 11.5f, 204.f });
    m_Stage6->ReserveButtonClickEvent(L"UI_MAP6_BUTTON_DOWN");
    m_Stage6->ReserveButtonOnEvent(L"UI_MAP6_BUTTON_ON");
    m_Stage6->ReserveButtonOutEvent(L"UI_MAP6_BUTTON_OUT");

    m_Stage7 = new BattleButton(L"�� ������7", BattleIconType::Monster, BattleStageType::THIRD, 7);
    m_Stage7->GetUITransform()->SetPosition({ 276.f, 249.5f });
    m_Stage7->ReserveButtonClickEvent(L"UI_MAP7_BUTTON_DOWN");
    m_Stage7->ReserveButtonOnEvent(L"UI_MAP7_BUTTON_ON");
    m_Stage7->ReserveButtonOutEvent(L"UI_MAP7_BUTTON_OUT");

    m_Stage8 = new BattleButton(L"�� ������8", BattleIconType::Elite, BattleStageType::ELITE, 8);
    m_Stage8->GetUITransform()->SetPosition({ 423.f, 209.f });
    m_Stage8->ReserveButtonClickEvent(L"UI_MAP8_BUTTON_DOWN");
    m_Stage8->ReserveButtonOnEvent(L"UI_MAP8_BUTTON_ON");
    m_Stage8->ReserveButtonOutEvent(L"UI_MAP8_BUTTON_OUT");

    m_Stage9 = new BattleButton(L"�� ������9", BattleIconType::Monster, BattleStageType::THIRD, 9);
    m_Stage9->GetUITransform()->SetPosition({ 157.f, 160.5f });
    m_Stage9->ReserveButtonClickEvent(L"UI_MAP9_BUTTON_DOWN");
    m_Stage9->ReserveButtonOnEvent(L"UI_MAP9_BUTTON_ON");
    m_Stage9->ReserveButtonOutEvent(L"UI_MAP9_BUTTON_OUT");

    m_Stage10 = new BattleButton(L"�� ������10", BattleIconType::Monster, BattleStageType::FIRST, 10);
    m_Stage10->GetUITransform()->SetPosition({ -465.f, 14.5f });
    m_Stage10->ReserveButtonClickEvent(L"UI_MAP10_BUTTON_DOWN");
    m_Stage10->ReserveButtonOnEvent(L"UI_MAP10_BUTTON_ON");
    m_Stage10->ReserveButtonOutEvent(L"UI_MAP10_BUTTON_OUT");

    m_Stage11 = new BattleButton(L"�� ������11", BattleIconType::Monster, BattleStageType::SECOND, 11);
    m_Stage11->GetUITransform()->SetPosition({ -325.f, 91.5f });
    m_Stage11->ReserveButtonClickEvent(L"UI_MAP11_BUTTON_DOWN");
    m_Stage11->ReserveButtonOnEvent(L"UI_MAP11_BUTTON_ON");
    m_Stage11->ReserveButtonOutEvent(L"UI_MAP11_BUTTON_OUT");

    m_Stage12 = new BattleButton(L"�� ������12", BattleIconType::Monster, BattleStageType::SECOND, 12);
    m_Stage12->GetUITransform()->SetPosition({ -142.5f, 45.f });
    m_Stage12->ReserveButtonClickEvent(L"UI_MAP12_BUTTON_DOWN");
    m_Stage12->ReserveButtonOnEvent(L"UI_MAP12_BUTTON_ON");
    m_Stage12->ReserveButtonOutEvent(L"UI_MAP12_BUTTON_OUT");

    m_Stage13 = new BattleButton(L"�� ������13", BattleIconType::Monster, BattleStageType::SECOND, 13);
    m_Stage13->GetUITransform()->SetPosition({ 9.f, 60.5f });
    m_Stage13->ReserveButtonClickEvent(L"UI_MAP13_BUTTON_DOWN");
    m_Stage13->ReserveButtonOnEvent(L"UI_MAP13_BUTTON_ON");
    m_Stage13->ReserveButtonOutEvent(L"UI_MAP13_BUTTON_OUT");

    m_Stage14 = new BattleButton(L"�� ������14", BattleIconType::Elite, BattleStageType::ELITE, 14);
    m_Stage14->GetUITransform()->SetPosition({ 159.5f, 57.f });
    m_Stage14->ReserveButtonClickEvent(L"UI_MAP14_BUTTON_DOWN");
    m_Stage14->ReserveButtonOnEvent(L"UI_MAP14_BUTTON_ON");
    m_Stage14->ReserveButtonOutEvent(L"UI_MAP14_BUTTON_OUT");

    m_Stage15 = new BattleButton(L"�� ������15", BattleIconType::Elite, BattleStageType::ELITE, 15);
    m_Stage15->GetUITransform()->SetPosition({ 287.f, 97.5f });
    m_Stage15->ReserveButtonClickEvent(L"UI_MAP15_BUTTON_DOWN");
    m_Stage15->ReserveButtonOnEvent(L"UI_MAP15_BUTTON_ON");
    m_Stage15->ReserveButtonOutEvent(L"UI_MAP15_BUTTON_OUT");

    m_Stage16 = new BattleButton(L"�� ������16", BattleIconType::Elite, BattleStageType::ELITE, 16);
    m_Stage16->GetUITransform()->SetPosition({ 376.5f, 25.f });
    m_Stage16->ReserveButtonClickEvent(L"UI_MAP16_BUTTON_DOWN");
    m_Stage16->ReserveButtonOnEvent(L"UI_MAP16_BUTTON_ON");
    m_Stage16->ReserveButtonOutEvent(L"UI_MAP16_BUTTON_OUT");

    m_Stage17 = new BattleButton(L"�� ������17", BattleIconType::Monster, BattleStageType::FIRST, 17);
    m_Stage17->GetUITransform()->SetPosition({ -549.f, -88.5f });
    m_Stage17->ReserveButtonClickEvent(L"UI_MAP17_BUTTON_DOWN");
    m_Stage17->ReserveButtonOnEvent(L"UI_MAP17_BUTTON_ON");
    m_Stage17->ReserveButtonOutEvent(L"UI_MAP17_BUTTON_OUT");

    m_Stage18 = new BattleButton(L"�� ������18", BattleIconType::Elite, BattleStageType::ELITE, 18);
    m_Stage18->GetUITransform()->SetPosition({ -431.5f, -132.f });
    m_Stage18->ReserveButtonClickEvent(L"UI_MAP18_BUTTON_DOWN");
    m_Stage18->ReserveButtonOnEvent(L"UI_MAP18_BUTTON_ON");
    m_Stage18->ReserveButtonOutEvent(L"UI_MAP18_BUTTON_OUT");

    m_Stage19 = new BattleButton(L"�� ������19", BattleIconType::Monster, BattleStageType::SECOND, 19);
    m_Stage19->GetUITransform()->SetPosition({ -318.f, -34.5f });
    m_Stage19->ReserveButtonClickEvent(L"UI_MAP19_BUTTON_DOWN");
    m_Stage19->ReserveButtonOnEvent(L"UI_MAP19_BUTTON_ON");
    m_Stage19->ReserveButtonOutEvent(L"UI_MAP19_BUTTON_OUT");

    m_Stage20 = new BattleButton(L"�� ������20", BattleIconType::Monster, BattleStageType::SECOND, 20);
    m_Stage20->GetUITransform()->SetPosition({ -289.f, -163.5f });
    m_Stage20->ReserveButtonClickEvent(L"UI_MAP20_BUTTON_DOWN");
    m_Stage20->ReserveButtonOnEvent(L"UI_MAP20_BUTTON_ON");
    m_Stage20->ReserveButtonOutEvent(L"UI_MAP20_BUTTON_OUT");

    m_Stage21 = new BattleButton(L"�� ������21", BattleIconType::Monster, BattleStageType::SECOND, 21);
    m_Stage21->GetUITransform()->SetPosition({ -129.f, -134.5f });
    m_Stage21->ReserveButtonClickEvent(L"UI_MAP21_BUTTON_DOWN");
    m_Stage21->ReserveButtonOnEvent(L"UI_MAP21_BUTTON_ON");
    m_Stage21->ReserveButtonOutEvent(L"UI_MAP21_BUTTON_OUT");

    m_Stage22 = new BattleButton(L"�� ������22", BattleIconType::Elite, BattleStageType::ELITE, 22);
    m_Stage22->GetUITransform()->SetPosition({ 17.5f, -89.f });
    m_Stage22->ReserveButtonClickEvent(L"UI_MAP22_BUTTON_DOWN");
    m_Stage22->ReserveButtonOnEvent(L"UI_MAP22_BUTTON_ON");
    m_Stage22->ReserveButtonOutEvent(L"UI_MAP22_BUTTON_OUT");

    m_Stage23 = new BattleButton(L"�� ������23", BattleIconType::Monster, BattleStageType::THIRD, 23);
    m_Stage23->GetUITransform()->SetPosition({ 145.f, -59.5f });
    m_Stage23->ReserveButtonClickEvent(L"UI_MAP23_BUTTON_DOWN");
    m_Stage23->ReserveButtonOnEvent(L"UI_MAP23_BUTTON_ON");
    m_Stage23->ReserveButtonOutEvent(L"UI_MAP23_BUTTON_OUT");

    m_Stage24 = new BattleButton(L"�� ������24", BattleIconType::Monster, BattleStageType::THIRD, 24);
    m_Stage24->GetUITransform()->SetPosition({ 157.f, -163.5f });
    m_Stage24->ReserveButtonClickEvent(L"UI_MAP24_BUTTON_DOWN");
    m_Stage24->ReserveButtonOnEvent(L"UI_MAP24_BUTTON_ON");
    m_Stage24->ReserveButtonOutEvent(L"UI_MAP24_BUTTON_OUT");

    m_Stage25 = new BattleButton(L"�� ������25", BattleIconType::Monster, BattleStageType::THIRD, 25);
    m_Stage25->GetUITransform()->SetPosition({ 291.f, -88.5f });
    m_Stage25->ReserveButtonClickEvent(L"UI_MAP25_BUTTON_DOWN");
    m_Stage25->ReserveButtonOnEvent(L"UI_MAP25_BUTTON_ON");
    m_Stage25->ReserveButtonOutEvent(L"UI_MAP25_BUTTON_OUT");

    m_Stage26 = new BattleButton(L"�� ������26", BattleIconType::Elite, BattleStageType::ELITE, 26);
    m_Stage26->GetUITransform()->SetPosition({ 420.5f, -157.f });
    m_Stage26->ReserveButtonClickEvent(L"UI_MAP26_BUTTON_DOWN");
    m_Stage26->ReserveButtonOnEvent(L"UI_MAP26_BUTTON_ON");
    m_Stage26->ReserveButtonOutEvent(L"UI_MAP26_BUTTON_OUT");

    m_BossStage = new BattleButton(L"�� ���� ������", BattleIconType::Boss, BattleStageType::BOSS, 280);
    m_BossStage->GetUITransform()->SetPosition({ 629.5f, 42.5f });
    m_BossStage->ReserveButtonClickEvent(L"UI_BOSS_BUTTON_DOWN");
    m_BossStage->ReserveButtonOnEvent(L"UI_BOSS_BUTTON_ON");
    m_BossStage->ReserveButtonOutEvent(L"UI_BOSS_BUTTON_OUT");

    m_WholeStages[0].push_back(m_Stage1);

    m_WholeStages[1].push_back(m_Stage2);
    m_WholeStages[1].push_back(m_Stage17);

    m_WholeStages[2].push_back(m_Stage3);
    m_WholeStages[2].push_back(m_Stage10);

    m_WholeStages[3].push_back(m_Stage4);

    m_WholeStages[4].push_back(m_Stage5);

    m_WholeStages[5].push_back(m_Stage6);
    m_WholeStages[5].push_back(m_Stage13);

    m_WholeStages[6].push_back(m_Stage7);
    m_WholeStages[6].push_back(m_Stage9);

    m_WholeStages[7].push_back(m_Stage8);

    m_WholeStages[8].push_back(m_BossStage);

    m_WholeStages[9].push_back(m_Stage15);

    m_WholeStages[10].push_back(m_Stage11);

    m_WholeStages[11].push_back(m_Stage12);

    m_WholeStages[12].push_back(m_Stage13);
    m_WholeStages[12].push_back(m_Stage22);

    m_WholeStages[13].push_back(m_Stage9);
    m_WholeStages[13].push_back(m_Stage14);

    m_WholeStages[14].push_back(m_Stage15);

    m_WholeStages[15].push_back(m_Stage8);
    m_WholeStages[15].push_back(m_Stage16);

    m_WholeStages[16].push_back(m_BossStage);

    m_WholeStages[17].push_back(m_Stage18);

    m_WholeStages[18].push_back(m_Stage19);
    m_WholeStages[18].push_back(m_Stage20);

    m_WholeStages[19].push_back(m_Stage12);

    m_WholeStages[20].push_back(m_Stage21);

    m_WholeStages[21].push_back(m_Stage22);

    m_WholeStages[22].push_back(m_Stage23);
    m_WholeStages[22].push_back(m_Stage24);

    m_WholeStages[23].push_back(m_Stage25);

    m_WholeStages[24].push_back(m_Stage25);

    m_WholeStages[25].push_back(m_Stage16);
    m_WholeStages[25].push_back(m_Stage26);

    m_WholeStages[26].push_back(m_BossStage);

    ///Mouse
    m_MouseObj = new Mouse(L"���콺");

    ///MapIndex ������ ��, ���� ���� ������ ������ �����ϰ� ��� ���� �Ұ���
    std::vector<MapButton*>& CurSelectableStages = m_WholeStages[GameManager::GetInstance()->GetMapIndex()];
    for (auto selectableStage : CurSelectableStages)
    {
        selectableStage->MakeHighlight();
    }

    ///UI Tutorial PopUp
    UITutorialPopup = new PopUp(L"Ʃ�丮�� �˾�");
    UITutorialPopup->AddUITexture();
    UITutorialPopup->GetUITransform()->SetPosition({ 0.f, 0.f });
    UITutorialPopup->LoadUITexture(L"../Resource/Tutorial/Tutorial_Page_01.png", L"Tutorial_Page_01");
    UITutorialPopup->SetAble(false);
    UITutorialPopup->SetTutorialIndex(1);

    UITutorialPageText = new UI(L"Ʃ�丮�� ������ �ؽ�Ʈ");
    UITutorialPageText->AddUIText();
    UITutorialPageText->SetUIAreaRect(90.f, 48.f);
    UITutorialPageText->GetUIText()->SetTextAttribute(L"1/4", 48.f, FontWeight::BOLD);
    UITutorialPageText->GetUIText()->SetBrushColor(D2D1::ColorF::White);
    UITutorialPageText->GetUITransform()->SetPosition({ 0.f, -468.f });
    UITutorialPageText->SetAble(false);

    UITutorialLeftButton = new Button(L"Ʃ�丮�� �˾� ���� ȭ��ǥ");
    UITutorialLeftButton->AddUITexture();
    UITutorialLeftButton->LoadUITexture(L"../Resource/UI/UI_Page_Left.png", L"UI_Page_Left");
    UITutorialLeftButton->GetUITransform()->SetPosition({ -130.f, -469.f });
    UITutorialLeftButton->ReserveButtonClickEvent(L"M_UI_TUTORIAL_LEFT_BUTTON_CLICK");
    UITutorialLeftButton->SetAble(false);

    UITutorialRightButton = new Button(L"Ʃ�丮�� �˾� ������ ȭ��ǥ");
    UITutorialRightButton->AddUITexture();
    UITutorialRightButton->LoadUITexture(L"../Resource/UI/UI_Page_Right.png", L"UI_Page_Right");
    UITutorialRightButton->GetUITransform()->SetPosition({ 130.f, -469.f });
    UITutorialRightButton->ReserveButtonClickEvent(L"M_UI_TUTORIAL_RIGHT_BUTTON_CLICK");
    UITutorialRightButton->SetAble(false);

    UITutorialBackButton = new Button(L"Ʃ�丮�� �˾� �ڷΰ��� ȭ��ǥ");
    UITutorialBackButton->AddUITexture();
    UITutorialBackButton->LoadUITexture(L"../Resource/UI/UI_Toggle_03.png", L"UI_Toggle_03");
    UITutorialBackButton->GetUITransform()->SetPosition({ 705.f, -475.f });
    UITutorialBackButton->ReserveButtonClickEvent(L"M_UI_TUTORIAL_BACK_BUTTON_CLICK");
    UITutorialBackButton->SetAble(false);

    ///UI Random Encounter
    UICultBg = new UI(L"�米�� �ǽ� ���");
    UICultBg->AddUITexture();
    UICultBg->GetUITransform()->SetPosition({ -20.f, 0.f });
    UICultBg->LoadUITexture(L"../Resource/Random Encounter/�米�� �ǽ�.png", L"�米�� �ǽ�");
    UICultBg->SetAble(false);

    UILabBg = new UI(L"����� ����� ���");
    UILabBg->AddUITexture();
    UILabBg->GetUITransform()->SetPosition({ -20.f, 0.f });
    UILabBg->LoadUITexture(L"../Resource/Random Encounter/����� �����.png", L"����� �����");
    UILabBg->SetAble(false);

    UINexusBg = new UI(L"�ð��� ƴ�� ���");
    UINexusBg->AddUITexture();
    UINexusBg->GetUITransform()->SetPosition({ -20.f, 0.f });
    UINexusBg->LoadUITexture(L"../Resource/Random Encounter/�ð��� ƴ��.png", L"�ð��� ƴ��");
    UINexusBg->SetAble(false);

    m_UIClutFirstButton = new Button(L"�米�� �ǽ� �ֻ�� ��ư");
    m_UIClutFirstButton->AddUITexture();
    m_UIClutFirstButton->LoadUITexture(L"../Resource/Random Encounter/Encounter_Cult_01.png", L"Encounter_Cult_01");
    m_UIClutFirstButton->GetUITransform()->SetPosition({ 412.f, -351.3f });
    m_UIClutFirstButton->ReserveButtonClickEvent(L"M_UI_CLUT_FIRST_BUTTON_CLICK");
    m_UIClutFirstButton->SetAble(false);

    m_UIClutSecondButton = new Button(L"�米�� �ǽ� �߰� ��ư");
    m_UIClutSecondButton->AddUITexture();
    m_UIClutSecondButton->LoadUITexture(L"../Resource/Random Encounter/Encounter_Cult_02.png", L"Encounter_Cult_02");
    m_UIClutSecondButton->GetUITransform()->SetPosition({ 412.f, -257.5f });
    m_UIClutSecondButton->ReserveButtonClickEvent(L"M_UI_CLUT_SECOND_BUTTON_CLICK");
    m_UIClutSecondButton->SetAble(false);

    m_UIClutThirdButton = new Button(L"�米�� �ǽ� ���ϴ� ��ư");
    m_UIClutThirdButton->AddUITexture();
    m_UIClutThirdButton->LoadUITexture(L"../Resource/Random Encounter/Encounter_Cult_03.png", L"Encounter_Cult_03");
    m_UIClutThirdButton->GetUITransform()->SetPosition({ 412.f, -163.5f });
    m_UIClutThirdButton->ReserveButtonClickEvent(L"M_UI_CLUT_THIRD_BUTTON_CLICK");
    m_UIClutThirdButton->SetAble(false);

    m_UILabFirstButton = new Button(L"����� ����� �ֻ�� ��ư");
    m_UILabFirstButton->AddUITexture();
    m_UILabFirstButton->LoadUITexture(L"../Resource/Random Encounter/Encounter_Lab_01.png", L"Encounter_Lab_01");
    m_UILabFirstButton->GetUITransform()->SetPosition({ 412.f, -351.3f });
    m_UILabFirstButton->ReserveButtonClickEvent(L"M_UI_LAB_FIRST_BUTTON_CLICK");
    m_UILabFirstButton->SetAble(false);

    m_UILabSecondButton = new Button(L"����� ����� �߰� ��ư");
    m_UILabSecondButton->AddUITexture();
    m_UILabSecondButton->LoadUITexture(L"../Resource/Random Encounter/Encounter_Lab_02.png", L"Encounter_Lab_02");
    m_UILabSecondButton->GetUITransform()->SetPosition({ 412.f, -257.5f });
    m_UILabSecondButton->ReserveButtonClickEvent(L"M_UI_LAB_SECOND_BUTTON_CLICK");
    m_UILabSecondButton->SetAble(false);

    m_UILabThirdButton = new Button(L"����� ����� ���ϴ� ��ư");
    m_UILabThirdButton->AddUITexture();
    m_UILabThirdButton->LoadUITexture(L"../Resource/Random Encounter/Encounter_Lab_03.png", L"Encounter_Lab_03");
    m_UILabThirdButton->GetUITransform()->SetPosition({ 412.f, -163.5f });
    m_UILabThirdButton->ReserveButtonClickEvent(L"M_UI_LAB_THIRD_BUTTON_CLICK");
    m_UILabThirdButton->SetAble(false);

    m_UINexusFirstButton = new Button(L"�ð��� ƴ�� �ֻ�� ��ư");
    m_UINexusFirstButton->AddUITexture();
    m_UINexusFirstButton->LoadUITexture(L"../Resource/Random Encounter/Encounter_Nexus_01.png", L"Encounter_Nexus_01");
    m_UINexusFirstButton->GetUITransform()->SetPosition({ 412.f, -351.3f });
    m_UINexusFirstButton->ReserveButtonClickEvent(L"M_UI_NEXUS_FIRST_BUTTON_CLICK");
    m_UINexusFirstButton->SetAble(false);

    m_UINexusSecondButton = new Button(L"�ð��� ƴ�� �߰� ��ư");
    m_UINexusSecondButton->AddUITexture();
    m_UINexusSecondButton->LoadUITexture(L"../Resource/Random Encounter/Encounter_Nexus_02.png", L"Encounter_Nexus_02");
    m_UINexusSecondButton->GetUITransform()->SetPosition({ 412.f, -257.5f });
    m_UINexusSecondButton->ReserveButtonClickEvent(L"M_UI_NEXUS_SECOND_BUTTON_CLICK");
    m_UINexusSecondButton->SetAble(false);


    Scene::EventCreateOBJ(m_BgObj);
    Scene::EventCreateOBJ(m_MouseObj);
    Scene::EventCreateOBJ(m_CameraObj);

    Scene::EventCreateOBJ(UIUpperSector);
    Scene::EventCreateOBJ(UIUpperIconLogo);
    Scene::EventCreateOBJ(UIUpperIconHP);
    Scene::EventCreateOBJ(UIUpperHPText);
    //Scene::EventCreateOBJ(UIUpperIconNowFloor);
    //Scene::EventCreateOBJ(UIUpperFloorText);
    Scene::EventCreateOBJ(UIUpperTutorial);
    Scene::EventCreateOBJ(UIUpperFdeck);
    Scene::EventCreateOBJ(UIUpperPdeck);
    Scene::EventCreateOBJ(UIUpperExit);

    Scene::EventCreateOBJ(m_WholeFrame);
    Scene::EventCreateOBJ(m_MapFrame);

    Scene::EventCreateOBJ(m_Stage1);
    Scene::EventCreateOBJ(m_Stage2);
    Scene::EventCreateOBJ(m_Stage3);
    Scene::EventCreateOBJ(m_Stage4);
    Scene::EventCreateOBJ(m_Stage5);
    Scene::EventCreateOBJ(m_Stage6);
    Scene::EventCreateOBJ(m_Stage7);
    Scene::EventCreateOBJ(m_Stage8);
    Scene::EventCreateOBJ(m_Stage9);
    Scene::EventCreateOBJ(m_Stage10);
    Scene::EventCreateOBJ(m_Stage11);
    Scene::EventCreateOBJ(m_Stage12);
    Scene::EventCreateOBJ(m_Stage13);
    Scene::EventCreateOBJ(m_Stage14);
    Scene::EventCreateOBJ(m_Stage15);
    Scene::EventCreateOBJ(m_Stage16);
    Scene::EventCreateOBJ(m_Stage17);
    Scene::EventCreateOBJ(m_Stage18);
    Scene::EventCreateOBJ(m_Stage19);
    Scene::EventCreateOBJ(m_Stage20);
    Scene::EventCreateOBJ(m_Stage21);
    Scene::EventCreateOBJ(m_Stage22);
    Scene::EventCreateOBJ(m_Stage23);
    Scene::EventCreateOBJ(m_Stage24);
    Scene::EventCreateOBJ(m_Stage25);
    Scene::EventCreateOBJ(m_Stage26);
    Scene::EventCreateOBJ(m_BossStage);

    Scene::EventCreateOBJ(UITutorialPopup);
    Scene::EventCreateOBJ(UITutorialLeftButton);
    Scene::EventCreateOBJ(UITutorialRightButton);
    Scene::EventCreateOBJ(UITutorialBackButton);
    Scene::EventCreateOBJ(UITutorialPageText);

    ///Random Encounter
    Scene::EventCreateOBJ(UICultBg);
    Scene::EventCreateOBJ(UILabBg);
    Scene::EventCreateOBJ(UINexusBg);

    Scene::EventCreateOBJ(m_UIClutFirstButton);
    Scene::EventCreateOBJ(m_UIClutSecondButton);
    Scene::EventCreateOBJ(m_UIClutThirdButton);

    Scene::EventCreateOBJ(m_UILabFirstButton);
    Scene::EventCreateOBJ(m_UILabSecondButton);
    Scene::EventCreateOBJ(m_UILabThirdButton);

    Scene::EventCreateOBJ(m_UINexusFirstButton);
    Scene::EventCreateOBJ(m_UINexusSecondButton);
}

void TestMap::Exit()
{
    Scene::Exit();

    for(auto& [index, stage] : m_WholeStages)
    {
        stage.clear();
    }
    m_WholeStages.clear();

    m_TypeArrange.clear();
}

void TestMap::Update(const float& deltaTime)
{
    Scene::Update(deltaTime);

    if(InputSystem::GetInstance()->IsKeyDown('1'))
    {
        EventSystem::GetInstance()->PublishEvent(L"CHANGE_SCENE", std::wstring(L"UI �׽�Ʈ�� ���� ��"));
    }

    for (auto selectableStage : m_WholeStages[GameManager::GetInstance()->GetMapIndex()])
    {
        selectableStage->MakeHighlight();
    }
}

void TestMap::FixedUpdate(const float& deltaTime)
{
    Scene::FixedUpdate(deltaTime);
}

void TestMap::LateUpdate(const float& deltaTime)
{
    Scene::LateUpdate(deltaTime);
}

void TestMap::Render(McCol::D2DRender* renderer)
{
    Scene::Render(renderer);
}

void TestMap::UpperTutorialOn(std::any any)
{
    // Ʃ�丮�� ��ư Ŭ�� �� �߻��ϴ� �̺�Ʈ
    DEBUGPRINT("UpperTutorialOn\n");

    // Ʃ�丮�� �˾����� �̵� / �˾� ����
    UITutorialPopup->SetAble(true);
    UITutorialLeftButton->SetAble(true);
    UITutorialRightButton->SetAble(true);
    UITutorialBackButton->SetAble(true);
    UITutorialPageText->SetAble(true);

    // Ʃ�丮�� �˾��� ��� ��ư�� ��ġ ���� ���·� �����
    UITutorialLeftButton->SetUIActivate(false);
    UITutorialRightButton->SetUIActivate(false);
    UITutorialBackButton->SetUIActivate(false);

    // �ٸ� UI���� ��ġ �Ұ��� ���·� �����.
    McCol::EventSystem::GetInstance()->PublishEvent(L"UI_INTERACTIVE_FALSE");
}

void TestMap::UpperFdeckOn(std::any any)
{
    DEBUGPRINT("UpperFdeckOn\n");
}

void TestMap::UpperPdeckOn(std::any any)
{
    DEBUGPRINT("UpperPdeckOn\n");
}

void TestMap::UpperExitOn(std::any any)
{
    DEBUGPRINT("�������� ������\n");
    EventSystem::GetInstance()->PublishEvent(L"CHANGE_SCENE", std::wstring(L"UI �׽�Ʈ�� ���� ��"));
}

void TestMap::TutorialLeftButtonOn(std::any any)
{
    // Ʃ�丮�� �˾����� ���� ��ư Ŭ�� �� �߻��ϴ� �̺�Ʈ
    DEBUGPRINT("TutorialLeftButtonOn\n");

    ReserveButtonCount(m_LeftButtonCount);

    switch (m_LeftButtonCount)
    {
    case 1:
    {
        UITutorialPopup->GetUITexture()->LoadTexture(L"../Resource/Tutorial/Tutorial_Page_01.png", L"Tutorial_Page_01");
        UITutorialPageText->GetUIText()->SetSrcText(L"1/4");
        break;
    }
    case 2:
    {
        UITutorialPopup->GetUITexture()->LoadTexture(L"../Resource/Tutorial/Tutorial_Page_02.png", L"Tutorial_Page_02");
        UITutorialPageText->GetUIText()->SetSrcText(L"2/4");
        break;
    }
    case 3:
    {
        UITutorialPopup->GetUITexture()->LoadTexture(L"../Resource/Tutorial/Tutorial_Page_03.png", L"Tutorial_Page_03");
        UITutorialPageText->GetUIText()->SetSrcText(L"3/4");
        break;
    }
    case 4:
    {
        UITutorialPopup->GetUITexture()->LoadTexture(L"../Resource/Tutorial/Tutorial_Page_04.png", L"Tutorial_Page_04");
        UITutorialPageText->GetUIText()->SetSrcText(L"4/4");

        break;
    }
    }
}

void TestMap::TutorialRightButtonOn(std::any any)
{
    // Ʃ�丮�� �˾����� ������ ��ư Ŭ�� �� �߻��ϴ� �̺�Ʈ
    DEBUGPRINT("TutorialRightButtonOn\n");

    m_RightButtonCount = (m_RightButtonCount % 4) + 1;

    switch (m_RightButtonCount)
    {
    case 1:
    {
        UITutorialPopup->GetUITexture()->LoadTexture(L"../Resource/Tutorial/Tutorial_Page_01.png", L"Tutorial_Page_01");
        UITutorialPageText->GetUIText()->SetSrcText(L"1/4");
        break;
    }
    case 2:
    {
        UITutorialPopup->GetUITexture()->LoadTexture(L"../Resource/Tutorial/Tutorial_Page_02.png", L"Tutorial_Page_02");
        UITutorialPageText->GetUIText()->SetSrcText(L"2/4");
        break;
    }
    case 3:
    {
        UITutorialPopup->GetUITexture()->LoadTexture(L"../Resource/Tutorial/Tutorial_Page_03.png", L"Tutorial_Page_03");
        UITutorialPageText->GetUIText()->SetSrcText(L"3/4");
        break;
    }
    case 4:
    {
        UITutorialPopup->GetUITexture()->LoadTexture(L"../Resource/Tutorial/Tutorial_Page_04.png", L"Tutorial_Page_04");
        UITutorialPageText->GetUIText()->SetSrcText(L"4/4");
        break;
    }
    }
}

void TestMap::TutorialBackButtonOn(std::any any)
{
    // Ʃ�丮�� �˾����� �Ѿ�� ��ư Ŭ�� �� �߻��ϴ� �̺�Ʈ
    DEBUGPRINT("TutorialBackButtonOn\n");

    // Ʃ�丮�� �˾� ���� ��Ȱ��ȭ
    UITutorialPopup->SetAble(false);
    UITutorialLeftButton->SetAble(false);
    UITutorialRightButton->SetAble(false);
    UITutorialBackButton->SetAble(false);
    UITutorialPageText->SetAble(false);

    // ��� UI ��ġ ���� ���·� �����.
    McCol::EventSystem::GetInstance()->PublishEvent(L"UI_INTERACTIVE_TRUE", nullptr);
}

void TestMap::ReserveButtonCount(int count)
{
    if (count == 1) {
        m_LeftButtonCount = 4;
    }
    else if (count == 4) {
        m_LeftButtonCount = 3;
    }
    else if (count == 3) {
        m_LeftButtonCount = 2;
    }
    else if (count == 2) {
        m_LeftButtonCount = 1;
    }
}

void TestMap::AddCharacterType(CharacterType characterType)
{
    m_TypeArrange.push_back(characterType);
}

void TestMap::BattleStart(std::any any)
{
    auto stageType = std::any_cast<BattleStageType>(any);

    auto randomNum = RandomGenerator::GetInstance()->GetRandomNumber(0, 1789);

    auto levelCase = randomNum % 3;

    AddCharacterType(CharacterType::PLAYER);
    SoundSystem::GetInstance()->PlaySoundM("Interaction_OpenMap");

    switch(stageType)
    {
    case BattleStageType::START:
    {
        AddCharacterType(CharacterType::ZOMBIE);
        EventSystem::GetInstance()->PublishEvent(L"CHANGE_SCENE", std::wstring(L"Battle Scene"));
        EventSystem::GetInstance()->PublishEvent(L"SET_MONSTER", m_TypeArrange);
        break;
    }
    case BattleStageType::FIRST:
    {
        randomNum %= 3;
        switch(randomNum)
        {
        case 0:
        {
            AddCharacterType(CharacterType::WEREWOLF);
            EventSystem::GetInstance()->PublishEvent(L"CHANGE_SCENE", std::wstring(L"Battle Scene"));
            EventSystem::GetInstance()->PublishEvent(L"SET_MONSTER", m_TypeArrange);
            break;
        }
        case 1:
        {
            AddCharacterType(CharacterType::ZOMBIE);
            AddCharacterType(CharacterType::ZOMBIE);
            EventSystem::GetInstance()->PublishEvent(L"CHANGE_SCENE", std::wstring(L"Battle Scene"));
            EventSystem::GetInstance()->PublishEvent(L"SET_MONSTER", m_TypeArrange);
            break;
        }
        case 2:
        {
            AddCharacterType(CharacterType::FANATIC);
            AddCharacterType(CharacterType::ZOMBIE);
            EventSystem::GetInstance()->PublishEvent(L"CHANGE_SCENE", std::wstring(L"Battle Scene"));
            EventSystem::GetInstance()->PublishEvent(L"SET_MONSTER", m_TypeArrange);
            break;
        }
        }

        break;
    }
    case BattleStageType::SECOND:
    {
        randomNum %= 3;
        switch (randomNum)
        {
        case 0:
        {
            AddCharacterType(CharacterType::ZOMBIE);
            AddCharacterType(CharacterType::ZOMBIE);
            AddCharacterType(CharacterType::ZOMBIE);
            EventSystem::GetInstance()->PublishEvent(L"CHANGE_SCENE", std::wstring(L"Battle Scene"));
            EventSystem::GetInstance()->PublishEvent(L"SET_MONSTER", m_TypeArrange);
            break;
        }
        case 1:
        {
            AddCharacterType(CharacterType::WEREWOLF);
            AddCharacterType(CharacterType::ZOMBIE);
            EventSystem::GetInstance()->PublishEvent(L"CHANGE_SCENE", std::wstring(L"Battle Scene"));
            EventSystem::GetInstance()->PublishEvent(L"SET_MONSTER", m_TypeArrange);
            break;
        }
        case 2:
        {
            AddCharacterType(CharacterType::FANATIC);
            AddCharacterType(CharacterType::ZOMBIE);
            AddCharacterType(CharacterType::ZOMBIE);
            AddCharacterType(CharacterType::ZOMBIE);
            EventSystem::GetInstance()->PublishEvent(L"CHANGE_SCENE", std::wstring(L"Battle Scene"));
            EventSystem::GetInstance()->PublishEvent(L"SET_MONSTER", m_TypeArrange);
            break;
        }
        }

        break;
    }
    case BattleStageType::THIRD:
    {
        randomNum %= 4;
        switch (randomNum)
        {
        case 0:
        {
            AddCharacterType(CharacterType::FANATIC);
            AddCharacterType(CharacterType::FANATIC);
            AddCharacterType(CharacterType::FANATIC);
            EventSystem::GetInstance()->PublishEvent(L"CHANGE_SCENE", std::wstring(L"Battle Scene"));
            EventSystem::GetInstance()->PublishEvent(L"SET_MONSTER", m_TypeArrange);
            break;
        }
        case 1:
        {
            AddCharacterType(CharacterType::FANATIC);
            AddCharacterType(CharacterType::ZOMBIE);
            AddCharacterType(CharacterType::FANATIC);
            AddCharacterType(CharacterType::ZOMBIE);
            EventSystem::GetInstance()->PublishEvent(L"CHANGE_SCENE", std::wstring(L"Battle Scene"));
            EventSystem::GetInstance()->PublishEvent(L"SET_MONSTER", m_TypeArrange);
            break;
        }
        case 2:
        {
            AddCharacterType(CharacterType::STALKER);
            AddCharacterType(CharacterType::WEREWOLF);
            EventSystem::GetInstance()->PublishEvent(L"CHANGE_SCENE", std::wstring(L"Battle Scene"));
            EventSystem::GetInstance()->PublishEvent(L"SET_MONSTER", m_TypeArrange);
            break;
        }
        case 3:
        {
            AddCharacterType(CharacterType::WEREWOLF);
            AddCharacterType(CharacterType::WEREWOLF);
            EventSystem::GetInstance()->PublishEvent(L"CHANGE_SCENE", std::wstring(L"Battle Scene"));
            EventSystem::GetInstance()->PublishEvent(L"SET_MONSTER", m_TypeArrange);
            break;
        }
        }
        break;
    }
    case BattleStageType::ELITE:
    {
        AddCharacterType(CharacterType::STALKER);
        AddCharacterType(CharacterType::STALKER);
        AddCharacterType(CharacterType::STALKER);
        EventSystem::GetInstance()->PublishEvent(L"CHANGE_SCENE", std::wstring(L"Battle Scene"));
        EventSystem::GetInstance()->PublishEvent(L"SET_MONSTER", m_TypeArrange);
        break;
    }
    case BattleStageType::BOSS:
    {
        AddCharacterType(CharacterType::GOLEM);
        EventSystem::GetInstance()->PublishEvent(L"CHANGE_SCENE", std::wstring(L"Battle Scene"));
        EventSystem::GetInstance()->PublishEvent(L"SET_MONSTER", m_TypeArrange);
        break;
    }
    }
}

void TestMap::ClutFirstButtonOn(std::any any)
{
    // �米�� �ǽ� �ʿ� �����ϰ�, �ֻ�� ��ư�� ������ ��
    // ��� ī�� 3���� ������ ������ ������ ���ī��� ��ȭ��Ų��.

    // �ش� �˾��� ��� ��� ���ֱ�
    UICultBg->SetAble(false);
    m_UIClutFirstButton->SetAble(false);
    m_UIClutSecondButton->SetAble(false);
    m_UIClutThirdButton->SetAble(false);

    McCol::EventSystem::GetInstance()->PublishEvent(L"UI_INTERACTIVE_FALSE");
}

void TestMap::ClutSecondButtonOn(std::any any)
{
    // �米�� �ǽ� �ʿ� �����ϰ�, �߰� ��ư�� ������ ��
    // ��� ī�� 1���� ������ ������ ���Ž�Ų��.

    // �ش� �˾��� ��� ��� ���ֱ�
    UICultBg->SetAble(false);
    m_UIClutFirstButton->SetAble(false);
    m_UIClutSecondButton->SetAble(false);
    m_UIClutThirdButton->SetAble(false);

    McCol::EventSystem::GetInstance()->PublishEvent(L"UI_INTERACTIVE_FALSE");
}

void TestMap::ClutThirdButtonOn(std::any any)
{
    // �米�� �ǽ� �ʿ� �����ϰ�, ���ϴ� ��ư�� ������ ��
    // ü�� ����(-15)�� �԰�, ���� ������ �̵�

    // �ش� �˾��� ��� ��� ���ֱ�
    UICultBg->SetAble(false);
    m_UIClutFirstButton->SetAble(false);
    m_UIClutSecondButton->SetAble(false);
    m_UIClutThirdButton->SetAble(false);

    McCol::EventSystem::GetInstance()->PublishEvent(L"UI_INTERACTIVE_FALSE");
}

void TestMap::LabFirstButtonOn(std::any any)
{
    // ����� ����� �ʿ� �����ϰ�, �ֻ�� ��ư�� ������ ��
    // ��� ī�� 2���� �������� �����ϰ�, ü���� 25��ŭ ȸ����Ų��.

    // �ش� �˾��� ��� ��� ���ֱ�
    UILabBg->SetAble(false);
    m_UILabFirstButton->SetAble(false);
    m_UILabSecondButton->SetAble(false);
    m_UILabThirdButton->SetAble(false);

    McCol::EventSystem::GetInstance()->PublishEvent(L"UI_INTERACTIVE_FALSE");
}

void TestMap::LabSecondButtonOn(std::any any)
{
    // ����� ����� �ʿ� �����ϰ�, �߰� ��ư�� ������ ��
    // ������ ī�� ������ �������� ȹ���ϰ�, ü�� ����(-25)�� �Դ´�.

    // �ش� �˾��� ��� ��� ���ֱ�
    UILabBg->SetAble(false);
    m_UILabFirstButton->SetAble(false);
    m_UILabSecondButton->SetAble(false);
    m_UILabThirdButton->SetAble(false);

    McCol::EventSystem::GetInstance()->PublishEvent(L"UI_INTERACTIVE_FALSE");
}

void TestMap::LabThirdButtonOn(std::any any)
{
    // ����� ����� �ʿ� �����ϰ�, ���ϴ� ��ư�� ������ ��
    // �ƹ��ϵ� �Ͼ�� �ʴ´�.

    // �ش� �˾��� ��� ��� ���ֱ�
    UILabBg->SetAble(false);
    m_UILabFirstButton->SetAble(false);
    m_UILabSecondButton->SetAble(false);
    m_UILabThirdButton->SetAble(false);

    McCol::EventSystem::GetInstance()->PublishEvent(L"UI_INTERACTIVE_FALSE");
}

void TestMap::NexusFirstButtonOn(std::any any)
{
    // �ð��� ƴ�� �ʿ� �����ϰ�, �ֻ�� ��ư�� ������ ��
    // ��� ī�� 1���� ������ ������ �з������� �߰��Ѵ�.

    // �ش� �˾��� ��� ��� ���ֱ�
    UINexusBg->SetAble(false);
    m_UINexusFirstButton->SetAble(false);
    m_UINexusSecondButton->SetAble(false);

    McCol::EventSystem::GetInstance()->PublishEvent(L"UI_INTERACTIVE_FALSE");
}

void TestMap::NexusSecondButtonOn(std::any any)
{
    // �ð��� ƴ�� �ʿ� �����ϰ�, ���ϴ� ��ư�� ������ ��
    // ü���� 15 ȸ���Ѵ�.

    // �ش� �˾��� ��� ��� ���ֱ�
    UINexusBg->SetAble(false);
    m_UINexusFirstButton->SetAble(false);
    m_UINexusSecondButton->SetAble(false);

    McCol::EventSystem::GetInstance()->PublishEvent(L"UI_INTERACTIVE_FALSE");
}

void TestMap::CrackStart(std::any any)
{
    // �ð��� ƴ�� �ʿ� �������� ��
    // �ش� �˾��� ��� ��� ���ֱ�
    UINexusBg->SetAble(true);
    m_UINexusFirstButton->SetAble(true);
    m_UINexusSecondButton->SetAble(true);

    // �ش� �˾��� ��� �����ϰ� ��� ��ġ �Ұ� ���·� �����
    UINexusBg->SetUIActivate(false);
    m_UINexusFirstButton->SetUIActivate(false);
    m_UINexusSecondButton->SetUIActivate(false);

    McCol::EventSystem::GetInstance()->PublishEvent(L"UI_INTERACTIVE_FALSE");
}

void TestMap::RandomStart(std::any any)
{
    auto randomNum = RandomGenerator::GetInstance()->GetRandomNumber(0, 7983);
    randomNum %= 3;

    // �ݹ�Ȯ���� �� ����
    switch(randomNum)
    {
    case 0:
    {
        // �米�� �ǽ� �ʿ� �������� ��
        // �ش� �˾��� ��� ��� ���ֱ�
        UICultBg->SetAble(true);
        m_UIClutFirstButton->SetAble(true);
        m_UIClutSecondButton->SetAble(true);
        m_UIClutThirdButton->SetAble(true);

        // �ش� �˾��� ��� �����ϰ� ��� ��ġ �Ұ� ���·� �����
        UICultBg->SetUIActivate(false);
        m_UIClutFirstButton->SetUIActivate(false);
        m_UIClutSecondButton->SetUIActivate(false);
        m_UIClutThirdButton->SetUIActivate(false);

        McCol::EventSystem::GetInstance()->PublishEvent(L"UI_INTERACTIVE_FALSE");
        break;
    }
    case 1:
    {
        // ����� ����� �ʿ� �������� ��
        // �ش� �˾��� ��� ��� ���ֱ�
        UILabBg->SetAble(true);
        m_UILabFirstButton->SetAble(true);
        m_UILabSecondButton->SetAble(true);
        m_UILabThirdButton->SetAble(true);

        // �ش� �˾��� ��� �����ϰ� ��� ��ġ �Ұ� ���·� �����
        UILabBg->SetUIActivate(false);
        m_UILabFirstButton->SetUIActivate(false);
        m_UILabSecondButton->SetUIActivate(false);
        m_UILabThirdButton->SetUIActivate(false);

        McCol::EventSystem::GetInstance()->PublishEvent(L"UI_INTERACTIVE_FALSE");
        break;
    }
    case 2:
    {
        // �ð��� ƴ�� �ʿ� �������� ��
        // �ش� �˾��� ��� ��� ���ֱ�
        UINexusBg->SetAble(true);
        m_UINexusFirstButton->SetAble(true);
        m_UINexusSecondButton->SetAble(true);

        // �ش� �˾��� ��� �����ϰ� ��� ��ġ �Ұ� ���·� �����
        UINexusBg->SetUIActivate(false);
        m_UINexusFirstButton->SetUIActivate(false);
        m_UINexusSecondButton->SetUIActivate(false);

        McCol::EventSystem::GetInstance()->PublishEvent(L"UI_INTERACTIVE_FALSE");
        break;
    }
    }
}

