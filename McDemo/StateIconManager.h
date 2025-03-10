//TODO : vector<Icon*> m_Icons�� �ش��ϴ� state ������ push_back
// Receive State, RepeatNum �޾Ƽ� RepeatNum 0�϶� vector���� erase�ϰ� ��ĭ�� ����
// ��ĭ�� ���� ���Ŀ�, SetXOffset���� ��ġ ����

#pragma once

#include <vector>

namespace McCol
{
    class StateIcon;
}

enum class State;

class StateIconManager
{
public:
    StateIconManager();
    ~StateIconManager() = default;

private:
    float startX;
    float startY;

    std::vector<McCol::StateIcon*> m_Icons;

public:
    void Initialize(float x, float y);
    void Finialize();

    void ModifyState(State state, const int& repeatCount);
    void OffRender();

private:
    void AddState(State state, const int& repeatCount);

};

