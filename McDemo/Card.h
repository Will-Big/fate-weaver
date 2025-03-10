#pragma once
#include "Elements.h"
#include <string>
#include "..\Engine\GameObject.h"
#include "..\Engine\ICollidable.h"
/*-------------------------------------------------------
Card
��... �ϴ� fatecard�� ���� �ּ����� ������ �Ȱ� ����...
AttributeComponent�� ��Ʈ ����ϳ� ���� �ִ� ��ü ����
map���� �̳�Ŭ���� Ÿ�� �����ؼ� m_Attributes�� ����.
�� �Ӽ��� �����ϴ��� üũ�Ҷ� GetAttribute() ������ 0�� �ƴ��� üũ�ϸ� �ȴ�.
�ٵ� 0���� üũ�ϸ� ����� 0�� �Ӽ��� �������� ���� �ʳ�? �̰� Ȯ���� �ʿ�
ī�� ������ Play�� ����. ī�� ���ۿ��� ��� Ÿ�� ī�尡 �����ҰŶ� �����ؼ� �ϴ� ������ ������
-------------------------------------------------------*/

class AttributeParts;

class Card :
	public McCol::GameObject
{
protected:
	CardType m_CardType;
	CharacterType m_CardOwnerType;
	Rarity m_Rarity;
	CharacterIndex m_OwnerCharacterIndex;
	GameObject* m_MyOwnerDeck;

	bool m_Iscollidable;

public:
	Card(std::wstring_view name);
	~Card() override;

public:
	void HandleCollisionStay(McCol::Collider* otherCollider) override;
	void HandleCollisionEnter(McCol::Collider* otherCollider) override;
	void HandleCollisionExit(McCol::Collider* otherCollider) override;
	void Update(const float& deltaTime) override;
	void Render(McCol::D2DRender* renderer) override;
	void Initialize() override;

public:
	void InitializeCard(CharacterType chT, CardType caT);
	virtual void Play(GameObject* targetObj) = 0;

public:
	void SetAttributeValue(Attribute attrTarget, int value);
	void SetAttributeType(Attribute attrTarget, Attribute attrModify);

	void SetDestination(Attribute attrTarget, Destination dest);
	void SetDestinations(Destination dest);

	Rarity GetRarity() const;
	Destination GetDestination() const;
	AttributeParts* GetAttribute(Attribute attr) const;
	std::vector<AttributeParts*> GetAttributes() const;

	int GetCharacterIndex() const;
	void SetCharacterIndex(CharacterIndex ci);

	CharacterType GetCardOwnerType() const;
	CardType GetCardType() const;

	void Setcollidable(bool iscollidable) { m_Iscollidable = iscollidable; }

	void SetMyOwnerDeck(McCol::GameObject* deck);

	virtual std::wstring MakeString() = 0;
};
