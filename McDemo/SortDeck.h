#pragma once
#include "CardFuncComponent.h"
/*-------------------------------------------------------
SortDeck
������ ���� 5�� ī�带 ������ ������� �����ϴ� ����� ���� FATECARD�� ���� ������Ʈ
�̺�Ʈ ȣ��� ��Ʋ������ �÷���ī�嵦�� �����ְ� �÷��̾ 5�� �����ϵ��� �� �ڿ� ������ ������� �� �ε��� ������ ���� �����������.
-------------------------------------------------------*/
class SortDeck :
    public CardFuncComponent
{
public:
	SortDeck(McCol::GameObject* owner);
	~SortDeck() override;

public:
	void Initialize() override;

	void ApplyEffect(McCol::GameObject* targetObj) override;
	std::wstring ExtractString() override;
	void SetOriginValue() override;
	void ResetToOriginValue() override;
};

