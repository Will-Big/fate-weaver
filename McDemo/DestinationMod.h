#pragma once
#include "CardFuncComponent.h"
#include "Elements.h"
/*-------------------------------------------------------
DestinationMod
FateCard�� ���� Destination ���� ������Ʈ
ApplyEffect ȣ���� �� Ÿ�� ī���� Destination�� m_DestinationToModify�� ��������.
-------------------------------------------------------*/

class DestinationMod
	: public CardFuncComponent
{
private:
	CardType m_DestinationTarget;
	Destination m_DestinationToModify;

public:
	DestinationMod(McCol::GameObject* owner);
	~DestinationMod() override;

public:
	void Initialize() override;
	void InitializeDestinationMod(CardType destinationTarget, Destination destinationToModify);

public:
	CardType GetDestinationTarget() const { return m_DestinationTarget; }
	Destination GetDestinationToModify() const { return m_DestinationToModify; }

public:
	void ApplyEffect(McCol::GameObject* targetObj) override;
	std::wstring ExtractString() override;
	void SetOriginValue() override;
	void ResetToOriginValue() override;

};

