#pragma once
#include "CardFuncComponent.h"
/*-------------------------------------------------------
PlayFromDeck
�÷��� ī�� ������ ������ ������ ī�带 �̷��������� ������ FATECARD�� ���� ������Ʈ
�̺�Ʈ ȣ��� ��Ʋ������ �÷���ī�嵦�� �����ְ� �÷��̾ 1�� �����ϵ��� �� �� ���õ� ī�带 �̷��������� ��������.
-------------------------------------------------------*/
class PlayFromDeck :
	public CardFuncComponent
{
public:
	PlayFromDeck(McCol::GameObject* owner);
	~PlayFromDeck() override;

public:
	void Initialize() override;

	void ApplyEffect(McCol::GameObject* targetObj) override;
	std::wstring ExtractString() override;
	void SetOriginValue() override;
	void ResetToOriginValue() override;
};

