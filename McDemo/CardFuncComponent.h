#pragma once
#include "..\Engine\Component.h"
#include "Elements.h"
#include <string>

/*-------------------------------------------------------
CardComponent
ī�忡 �޾��� ������Ʈ���� ���� �߻�ȭ Ŭ����
TODO:
�����ݸ� ī�� ���(ī�带 �� +10 ���ִ� ī��� ��ü)
-------------------------------------------------------*/
class McCol::GameObject;
class Card;

class CardFuncComponent :
	public McCol::Component
{
public:
	CardFuncComponent(McCol::GameObject* owner);
	~CardFuncComponent() override;

public:
	void Initialize() override;

public:
	virtual void ApplyEffect(McCol::GameObject* targetObj = nullptr) = 0;
	virtual std::wstring ExtractString() = 0;
	virtual void SetOriginValue() = 0;
	virtual void ResetToOriginValue() = 0;
};

