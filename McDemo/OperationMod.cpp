#include "OperationMod.h"
#include "FateCard.h"
#include "ValueMod.h"

#include <vector>

OperationMod::OperationMod(McCol::GameObject* owner)
	: CardFuncComponent(owner)
{
}

OperationMod::~OperationMod()
{
}

void OperationMod::Initialize()
{
}

void OperationMod::ApplyEffect(McCol::GameObject* targetObj)
{
	FateCard* targetCard = dynamic_cast<FateCard*>(targetObj);

	if (targetCard)
	{
		ValueMod* vm = targetCard->GetComponent<ValueMod>();

		if (vm && vm->GetOperation() == Operation::ADD)
		{
			vm->SetOperation(Operation::SUB);
		}

		if (dynamic_cast<FateCard*>(GetOwner())->IsParadox())
			vm->SetOriginValue();
	}

}

std::wstring OperationMod::ExtractString()
{
	std::wstring result;

	result = L"���ī��\nī���� +��\n-�� �ٲߴϴ�.";

	return result;
}

void OperationMod::SetOriginValue()
{
}

void OperationMod::ResetToOriginValue()
{
}
