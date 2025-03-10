#include "PlayFromDeck.h"
#include "../Engine/EventSystem.h"

PlayFromDeck::PlayFromDeck(McCol::GameObject* owner)
	: CardFuncComponent(owner)
{
}

PlayFromDeck::~PlayFromDeck()
{
}

void PlayFromDeck::Initialize()
{
}

void PlayFromDeck::ApplyEffect(McCol::GameObject* targetObj)
{
	McCol::EventSystem::GetInstance()->PublishEvent(L"PLAY_FROM_DECK", this);
	//PLAY_FROM_DECK �÷��� ī�� ������ �ϳ� �����ؼ� ī�� ���� �̺�Ʈ
}

std::wstring PlayFromDeck::ExtractString()
{
	return std::wstring();
}

void PlayFromDeck::SetOriginValue()
{
}

void PlayFromDeck::ResetToOriginValue()
{
}
