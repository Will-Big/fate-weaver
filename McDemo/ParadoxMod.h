#pragma once
#include "CardFuncComponent.h"
/*-------------------------------------------------------
ParadoxMod
FateCard�� ���� Paradox ���� ������Ʈ
ApplyEffect ȣ���� �� Ÿ�� ���ī���� m_Paradox�� true�� ��������.
-------------------------------------------------------*/
class ParadoxMod :
    public CardFuncComponent
{
public:
	ParadoxMod(McCol::GameObject* owner);
	~ParadoxMod() override;

public:
	void Initialize() override;

	void ApplyEffect(McCol::GameObject* targetObj) override;
	std::wstring ExtractString() override;
	void SetOriginValue() override;
	void ResetToOriginValue() override;
};

