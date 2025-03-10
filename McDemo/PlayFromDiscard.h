#pragma once
#include "CardFuncComponent.h"
/*-------------------------------------------------------
PlayFromDiscard
������ ī�� ������ ������ ������ ī�带 �̷��������� ������ FATECARD�� ���� ������Ʈ
�̺�Ʈ ȣ��� ��Ʋ������ ������ �÷���ī�嵦�� �����ְ� �÷��̾ 1�� �����ϵ��� �� �� ���õ� ī�带 �̷��������� ��������.
-------------------------------------------------------*/
class PlayFromDiscard :
	public CardFuncComponent
{
public:
	PlayFromDiscard(McCol::GameObject* owner);
	~PlayFromDiscard() override;

public:
	void Initialize() override;

	void ApplyEffect(McCol::GameObject* targetObj) override;
	std::wstring ExtractString() override;
	void SetOriginValue() override;
	void ResetToOriginValue() override;
};

