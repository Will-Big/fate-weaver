#pragma once
#include "..\Engine\Component.h"
#include "Elements.h"
/*-------------------------------------------------------
CardComponent
ī�忡 �޾��� ������Ʈ���� ���� �߻�ȭ Ŭ����
TODO:
�����ݸ� ī�� ���(ī�带 �� +10 ���ִ� ī��� ��ü)
-------------------------------------------------------*/
class McCol::GameObject;
class Card;

class CardComponent :
	public McCol::Component
{
public:
	CardComponent(McCol::GameObject* owner);
	~CardComponent() override;

public:
	virtual void ApplyEffect(McCol::GameObject* targetObj = nullptr) = 0;
	void Initialize() override {}
};

