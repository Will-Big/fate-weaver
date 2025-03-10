#pragma once
#include "CardFuncComponent.h"
/*-------------------------------------------------------
ValueMod
��Ģ�������� �̷���� FateCard�� ���� ������Ʈ
�����Ҷ� ���ڷ� ������ Attribute�� Operation, ��ġ ���� ���ָ�
ApplyEffect ȣ���Ҷ� Ÿ�� ī���� ���� Attribute ����� ��Ģ ���� ����.
-------------------------------------------------------*/

class McCol::GameObject;

class ValueMod
	: public CardFuncComponent
{

private:
	Attribute m_AttributeTarget;
	Operation m_Operation;
	int m_ValueToModify;
	CardType m_TargetCard;

	Attribute m_OriginAttributeTarget;
	Operation m_OriginOperation;
	int m_OriginValueToModify;
	CardType m_OriginTargetCard;

public:
	ValueMod(McCol::GameObject* owner);
	~ValueMod() override;

	void Initialize() override;
	void InitializeValueMod(Attribute attr, Operation op, int value, CardType targetCard);

	Operation GetOperation() const;
	void SetOperation(Operation operation);
	int GetValueToModify() const;
	void SetValueToModify(int valueToModify);
	CardType GetTargetCard() const
	{
		return m_TargetCard;
	}
	//void SetTargetCard(CardType targetCard)
	//{
	//	m_TargetCard = targetCard;
	//}

	Attribute GetAttribute() const { return m_AttributeTarget; }
public:
	void ApplyEffect(McCol::GameObject* targetObj) override;
	std::wstring ExtractString() override;

	void SetOriginValue();
	void ResetToOriginValue();
};

