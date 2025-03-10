/*-------------------------------------------------------
Play Card
: Play�� PlayCard�� ���� �ִ� AffectComponent ã�Ƽ� �� ��ü�� ApplyEffect ȣ��

- �ֵ���, Ÿ���� PlayCard������ ���ǹǷ� ��� ������ ������
- ���Ǵ� Factor�� FateCard�� �ַ� ��ġ�� ������ Card�� Attribute���� ����ٰ� �����
- ȿ���� ���, FateCard�� ��ġ�� �����Ƿ� AffectComponent�� ������

++) PlayCard�� ��� ��� 2�� ������ ���� �ִµ�... �̰� ���߿� .. ��ŷ�غ���
------------------------------------------------------ - */

#pragma once
#include <map>

#include "Card.h"
#include "Elements.h"

class PlayCard :
	public Card
{
public:
	PlayCard(std::wstring_view name);
	~PlayCard() override;



public:
	void InitializePlayCard(Rarity rarity, CharacterType chT, CardType caT);

	void HandleCollisionStay(McCol::Collider* otherCollider) override;
	void HandleCollisionEnter(McCol::Collider* otherCollider) override;
	void HandleCollisionExit(McCol::Collider* otherCollider) override;

public:
	void Play(GameObject* targetObj) override;

public:
	int GetInitiative() const;
	void SetInitiative(int value);

	std::map<Destination, CardInfo> GetCardInfo();

	std::wstring MakeString() override;
};

