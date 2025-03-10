///*-------------------------------------------------------
//Affect Component
//
//- ȿ���� PlayCard������ ���ǹǷ� ��� ������ ������
//- �����ڿ��� ���� ������Ʈ(ī�� �� ĳ����)�� ��������
//- �����ڿ��� ������ Attribute�� Affect, value ��������
//- �����ڿ��� value�� �޾ƿ� Affect enum class���� �ش��ϴ� Affect�� ��������
//- None�̸�, Affect enum class���� �ش��ϴ� Affect�� ���ٴ� ������ value�� �����ϰ� ������ ��
//------------------------------------------------------ - */
//
//#pragma once
//#include "CardComponent.h"
//#include "Card.h"
//
//class McCol::GameObject;
//class AffectComponent :
//    public CardComponent
//{
//public:
//    enum class Affect
//    {
//        None,
//        AllDamageMinus3,
//        AllDamagePlus3,
//        NextDamagePlus2,
//        HealthPlus2,
//        For1Turn,
//        For2Turn,
//        For3Turn,
//        InitiativePlus1,
//        DamageMinus30Percent,
//        FirstCardRemove,
//        Paradox
//    };
//
//private:
//    Card::Attribute m_Attribute;
//    Affect m_Affect;
//    int m_ValueToModify;
//
//public:
//    AffectComponent(McCol::GameObject* owner, Card::Attribute attr, Affect affect, int value);
//
//public:
//    void ApplyEffect(McCol::GameObject* targetObj) override;
//};
//
