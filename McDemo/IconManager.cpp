#include "../Engine/pch.h"
#include "IconManager.h"
#include "../Engine/Scene.h"
#include "../Engine/Icon.h"

IconManager::IconManager()
    : m_Icon(nullptr)
{
    // TODO : new Icon stateIcon�� �ش��ϴ� �͵� �� �س���
}

void IconManager::Initialize()
{
}

void IconManager::Finialize()
{
}

void IconManager::Resgister(McCol::Icon* icon)
{
    m_Icon = icon;
    m_Icons.push_back(icon);

    // TODO : �̰� ������ �Ŵ��� Ŭ�������� �ϸ� Scene::Exit�Ҷ� ���� ��..
    //McCol::Scene::EventCreateOBJ(icon);
}
