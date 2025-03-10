#include "PlayFromDiscard.h"
#include "../Engine/EventSystem.h"

PlayFromDiscard::PlayFromDiscard(McCol::GameObject* owner)
	: CardFuncComponent(owner)
{
}

PlayFromDiscard::~PlayFromDiscard()
{
}

void PlayFromDiscard::Initialize()
{
}

void PlayFromDiscard::ApplyEffect(McCol::GameObject* targetObj)
{
	McCol::EventSystem::GetInstance()->PublishEvent(L"PLAY_FROM_DISCARD", this);
	//PLAY_FROM_DISCARD ���� ī�� ������ �ϳ� �����ؼ� ī�� ���� �̺�Ʈ
}

std::wstring PlayFromDiscard::ExtractString()
{
	return std::wstring();
}

void PlayFromDiscard::SetOriginValue()
{
}

void PlayFromDiscard::ResetToOriginValue()
{
}
