#pragma once
#include "CardFuncComponent.h"
/*-------------------------------------------------------
DrawCard
ī�� ��ο츦 ���ִ� FATECARD�� ���� ������Ʈ
m_TargetDeckType�� ���� �ٸ� �̺�Ʈ ȣ��
��Ʋ������ Ÿ�� �� Ÿ�Կ� �´� ������ m_NumberOfCards ����ŭ ī�� ��ο� �������.
-------------------------------------------------------*/

class DrawCard :
	public CardFuncComponent
{
private:
	DeckType m_TargetDeckType;
	int m_NumberOfCards;

public:
	DrawCard(McCol::GameObject* owner);
	~DrawCard() override;

	void Initialize() override;
	void InitializeDrawCard(DeckType, int);

public:
	int GetNumOfCards();
	void SetNumOfCards(int numberOfCards);

public:
	void ApplyEffect(McCol::GameObject* targetObj) override;
	std::wstring ExtractString() override;
	void SetOriginValue() override;
	void ResetToOriginValue() override;
};

