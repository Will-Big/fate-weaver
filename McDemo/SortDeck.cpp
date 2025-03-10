#include "SortDeck.h"
#include "../Engine/EventSystem.h"

SortDeck::SortDeck(McCol::GameObject* owner)
	: CardFuncComponent(owner)
{
}

SortDeck::~SortDeck()
{
}

void SortDeck::Initialize()
{
}

void SortDeck::ApplyEffect(McCol::GameObject* targetObj)
{
	McCol::EventSystem::GetInstance()->PublishEvent(L"SORT_TOP5_CARD", this);
	//SORT_TOP5_CARD �÷��� ī�� ������ �ټ� �� �����ؼ� ������ ������ ������� �������� �������ִ� �̺�Ʈ
}

std::wstring SortDeck::ExtractString()
{
	return std::wstring();
}

void SortDeck::SetOriginValue()
{
}

void SortDeck::ResetToOriginValue()
{
}
