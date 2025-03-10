#include "../Engine/pch.h"
#include "StateIconManager.h"
#include "Elements.h"

#include "../Engine/Scene.h"
#include "../Engine/StateIcon.h"
#include "../Engine/Transform.h"

StateIconManager::StateIconManager()
{
    m_Icons.clear();
}

void StateIconManager::Initialize(float x, float y)
{
    startX = x;
    startY = y;
}

void StateIconManager::Finialize()
{
}

void StateIconManager::ModifyState(State state, const int& repeatCount)
{
    int targetIndex = -1;

    for (int i = 0; i < m_Icons.size(); i++)
    {
        if (m_Icons[i]->GetIconState() == state)
        {
            targetIndex = i;
            if (repeatCount > 0)
            {
                m_Icons[i]->SetIconRepeatCount(repeatCount);
                return;
            }
            else
            {
                McCol::Vector2 tempIconPos = m_Icons[targetIndex]->GetUITransform()->GetPosition();
                for (int j = targetIndex; j < m_Icons.size() - 1; j++)
                {
                    auto oldIconPos = m_Icons[j + 1]->GetUITransform()->GetPosition();
                    m_Icons[j + 1]->GetUITransform()->SetPosition(tempIconPos);
                    tempIconPos = oldIconPos;

                }
                McCol::Scene::EventDeleteOBJ(m_Icons[targetIndex]);
                m_Icons.erase(m_Icons.begin() + targetIndex);
                return;
            }
        }
    }

    // m_Icons ���Ϳ� �̹� �ش� ���Ұ� ���ٸ� AddState
    if (repeatCount != 0)
        AddState(state, repeatCount);
}

void StateIconManager::OffRender()
{
    for(auto icon : m_Icons)
    {
        icon->SetAble(false);
    }
}

void StateIconManager::AddState(State state, const int& repeatCount)
{
    // m_Icons ���Ϳ� �ش� ���Ұ� ���ٸ�, ���� stateIcon ���� �־���
    McCol::StateIcon* stateIcon = new McCol::StateIcon(L"�����̻� ������");

    m_Icons.push_back(stateIcon);

    // stateIcon State ����
    stateIcon->SetIconTransform(startX, startY);
    stateIcon->SetIconState(state);
    stateIcon->SetIconRepeatCount(repeatCount);

    // stateIcon�� Offset ����
    for (int i = 0; i < m_Icons.size(); i++)
    {
        if (m_Icons[i] == stateIcon)
        {
            m_Icons[i]->SetIconOffset(i);
        }
    }

    // stateIcon�� Event ���
    stateIcon->ReserveIconOnEvent(L"B_UI_STATE_ICON_ON");
    stateIcon->ReserveIconOutEvent(L"B_UI_STATE_ICON_OUT");

    stateIcon->SubScribeOn(L"STATE_ICON_ABLE");
    stateIcon->SubScribeOff(L"STATE_ICON_DISABLE");

    // stateIcon CreateObj
    McCol::Scene::EventCreateOBJ(stateIcon);
}
