#pragma once
#include "CardFuncComponent.h"
/*-------------------------------------------------------
SetCard
ī�� �����ϴ� ����� ���� FATECARD�� ���� ������Ʈ
ApplyEffect ȣ���� �� Ÿ��ī�带 �� +10�� �ִ� ī��� �ٲ۴�.
-------------------------------------------------------*/
class SetCard :
	public CardFuncComponent
{
public:
	SetCard(McCol::GameObject* owner);
	~SetCard() override;

public:
	void Initialize() override;

	void ApplyEffect(McCol::GameObject* targetObj) override;
	std::wstring ExtractString() override;
	void SetOriginValue() override;
	void ResetToOriginValue() override;
};

