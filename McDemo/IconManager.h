//TODO : vector<Icon*> m_Icons�� �ش��ϴ� state ������ push_back
// Receive State, RepeatNum �޾Ƽ� RepeatNum 0�϶� vector���� erase�ϰ� ��ĭ�� ����
// ��ĭ�� ���� ���Ŀ�, SetXOffset���� ��ġ ����

#pragma once

#include <vector>

namespace McCol
{
    class Icon;
}

class IconManager
{
public:
    IconManager();
    ~IconManager() = default;

private:
    McCol::Icon* m_Icon;
    std::vector<McCol::Icon*> m_Icons;

public:
    void Initialize();
    void Finialize();
    void Resgister(McCol::Icon* icon);
};

