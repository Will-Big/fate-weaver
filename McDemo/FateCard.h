#pragma once
#include "Card.h"
/*-------------------------------------------------------
FateCard
Play�� FateCard�� ���� �ִ� ValueMod ã�Ƽ� �� ��ü�� ApplyEffect ȣ��
TODO : �ٸ� Mod�鵵 ApplyEffect ȣ�� ����
-------------------------------------------------------*/
class FateCard :
	public Card
{
private:
	int m_Cost;
	bool m_IsParadox;

	int m_HandOrder;

public:
	FateCard(std::wstring_view name);
	~FateCard() override;

public:
	void HandleCollisionStay(McCol::Collider* otherCollider) override;
	void HandleCollisionEnter(McCol::Collider* otherCollider) override;
	void HandleCollisionExit(McCol::Collider* otherCollider) override;

public:
	void InitializeFateCard(Rarity rarity, int cost, CharacterType chT, CardType caT, bool isParadox = false);


public:
	void Play(GameObject* targetObj) override;
	void ParadoxOn();

	void SetHandOrder(int zOrder);
	int GetHandOrder() const;

	GameObject* GetMyOwnerDeck() const;

	bool GetCost() const { return m_Cost; }

	bool IsParadox() const { return m_IsParadox; }
	void SetParadox(bool isparadox) { m_IsParadox = isparadox; }

	std::wstring GetCostString() const;
	std::wstring MakeString() override;
};

