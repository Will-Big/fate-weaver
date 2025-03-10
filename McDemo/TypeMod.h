#pragma once
#include "CardFuncComponent.h"
/*-------------------------------------------------------
TypeMod
FateCard�� ���� Type ���� ������Ʈ
ApplyEffect ȣ���� �� Ÿ�� ī���� Attribute�� m_AttributeToModify�� ��������.
-------------------------------------------------------*/

class TypeMod :
    public CardFuncComponent
{
private:
	Attribute m_AttributeTarget;
	Attribute m_AttributeToModify;
	CardType m_TargetCard;

	Attribute m_OriginAttributeTarget;
	Attribute m_OriginAttributeToModify;
	CardType m_OriginTargetCard;

public:
	TypeMod(McCol::GameObject* owner);
	~TypeMod() override;

	void Initialize() override;
	void InitializeTypeMod(Attribute attrTarget, Attribute attrModify, CardType targetCard);

public:
	void ApplyEffect(McCol::GameObject* targetObj) override;
	std::wstring ExtractString() override;
	void SetOriginValue() override;
	void ResetToOriginValue() override;
};

