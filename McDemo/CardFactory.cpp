#include "CardFactory.h"
#include "CardComponentHeader.h"
#include "Elements.h"
#include "PlayCard.h"
#include "FateCard.h"
#include "Card.h"
#include "CardTexture.h"
#include "../Engine/RandomGenerator.h"


PlayCard* CardFactory::CreateCard(DefaultPlayCard::PlayerCard cardName)
{
	switch (cardName)
	{
	case DefaultPlayCard::PlayerCard::���:
	{
		PlayCard* card = new PlayCard(L"���");
		card->GetComponent<CardTexture>()->SetIllustration(L"���");
		card->InitializePlayCard(Rarity::DEFAULT, CharacterType::PLAYER, CardType::PLAYER_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 5);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DAMAGE, 5, Destination::NEAREST_ENEMY);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::PlayerCard::ȸ��:
	{
		PlayCard* card = new PlayCard(L"ȸ��");
		card->GetComponent<CardTexture>()->SetIllustration(L"ȸ��");
		card->InitializePlayCard(Rarity::DEFAULT, CharacterType::PLAYER, CardType::PLAYER_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 2);
		card->AddComponent<StateParts>()->InitializeStateParts(State::QUICK, 2, Destination::SELF);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::PlayerCard::�ٸ��ɱ�:
	{
		PlayCard* card = new PlayCard(L"�ٸ� �ɱ�");
		card->GetComponent<CardTexture>()->SetIllustration(L"�ٸ��ɱ�");
		card->InitializePlayCard(Rarity::DEFAULT, CharacterType::PLAYER, CardType::PLAYER_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 2);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DAMAGE, 2, Destination::NEAREST_ENEMY);
		card->AddComponent<StateParts>()->InitializeStateParts(State::DISRUPTION, 1, Destination::NEAREST_ENEMY);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::PlayerCard::����:
	{
		PlayCard* card = new PlayCard(L"����");
		card->GetComponent<CardTexture>()->SetIllustration(L"����");
		card->InitializePlayCard(Rarity::DEFAULT, CharacterType::PLAYER, CardType::PLAYER_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 4);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DAMAGE, 4, Destination::NEAREST_ENEMY);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::ATTACK_COUNT, 2, Destination::NEAREST_ENEMY);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::PlayerCard::����:
	{
		PlayCard* card = new PlayCard(L"����");
		card->GetComponent<CardTexture>()->SetIllustration(L"����");
		card->InitializePlayCard(Rarity::COMMON, CharacterType::PLAYER, CardType::PLAYER_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 7);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DAMAGE, 16, Destination::FARTHEST_ENEMY);
		SetOrigin(card); 
		return card;
	}
	break;
	case DefaultPlayCard::PlayerCard::�÷�����:
	{
		PlayCard* card = new PlayCard(L"�÷�����");
		card->GetComponent<CardTexture>()->SetIllustration(L"�÷�����");
		card->InitializePlayCard(Rarity::UNCOMMON, CharacterType::PLAYER, CardType::PLAYER_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 3);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DAMAGE, 6, Destination::ALL_ENEMIES);
		card->AddComponent<StateParts>()->InitializeStateParts(State::CONFUSION, 3, Destination::ALL_ENEMIES);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::PlayerCard::�ǹ�Ÿ��:
	{
		PlayCard* card = new PlayCard(L"�ǹ� Ÿ��");
		card->GetComponent<CardTexture>()->SetIllustration(L"�ǹ�Ÿ��");
		card->InitializePlayCard(Rarity::UNCOMMON, CharacterType::PLAYER, CardType::PLAYER_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 2);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DAMAGE, 8, Destination::FARTHEST_ENEMY);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DEFENSE, 8, Destination::SELF);
		SetOrigin(card);

		return card;
	}
	break;
	case DefaultPlayCard::PlayerCard::��ƴ����:
	{
		PlayCard* card = new PlayCard(L"��ƴ ����");
		card->GetComponent<CardTexture>()->SetIllustration(L"��ƴ����");
		card->InitializePlayCard(Rarity::UNCOMMON, CharacterType::PLAYER, CardType::PLAYER_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 4);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DAMAGE, 6, Destination::FARTHEST_ENEMY);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::ATTACK_COUNT, 2, Destination::FARTHEST_ENEMY);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DRAW_NUMBER, -9999, Destination::FARTHEST_ENEMY);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::PlayerCard::��ź�ǻ��:
	{
		PlayCard* card = new PlayCard(L"��ź�� ���");
		card->GetComponent<CardTexture>()->SetIllustration(L"��ź�ǻ��");
		card->InitializePlayCard(Rarity::RARE, CharacterType::PLAYER, CardType::PLAYER_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 1);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DEFENSE, 10, Destination::SELF);
		card->AddComponent<StateParts>()->InitializeStateParts(State::ENCHANTMENT, 3, Destination::SELF);
		SetOrigin(card);

		return card;
	}
	break;
	case DefaultPlayCard::PlayerCard::�����κ���Ʈ:
	{
		PlayCard* card = new PlayCard(L"������ ����Ʈ");
		card->GetComponent<CardTexture>()->SetIllustration(L"�����κ���Ʈ");
		card->InitializePlayCard(Rarity::RARE, CharacterType::PLAYER, CardType::PLAYER_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 7);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DAMAGE, 25, Destination::NEAREST_ENEMY);
		card->AddComponent<StateParts>()->InitializeStateParts(State::DISRUPTION, 2, Destination::NEAREST_ENEMY);
		card->AddComponent<StateParts>()->InitializeStateParts(State::CONFUSION, 2, Destination::NEAREST_ENEMY);
		SetOrigin(card);
		return card;
	}
	break;
	default:
		return nullptr;
	}
}

FateCard* CardFactory::CreateCard(DefaultFateCard::PlayerCard cardName)
{
	switch (cardName)
	{
	case DefaultFateCard::PlayerCard::����:
	{
		FateCard* card = new FateCard(L"����");
		card->GetComponent<CardTexture>()->SetIllustration(L"����");
		card->InitializeFateCard(Rarity::DEFAULT, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::DAMAGE, Operation::SUB, 5, CardType::ENEMY_PLAY_CARD);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::ġ��:
	{
		FateCard* card = new FateCard(L"ġ��");
		card->GetComponent<CardTexture>()->SetIllustration(L"ġ��");
		card->InitializeFateCard(Rarity::DEFAULT, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::DAMAGE, Operation::ADD, 5, CardType::PLAYER_PLAY_CARD);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::ġ��_�з�����:
	{
		FateCard* card = new FateCard(L"ġ��");
		card->GetComponent<CardTexture>()->SetIllustration(L"ġ��");
		card->InitializeFateCard(Rarity::DEFAULT, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::DAMAGE, Operation::ADD, 5, CardType::PLAYER_PLAY_CARD);
		card->SetParadox(true);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::�ð�����:
	{
		FateCard* card = new FateCard(L"�ð� ����");
		card->GetComponent<CardTexture>()->SetIllustration(L"�ð�����");
		card->InitializeFateCard(Rarity::DEFAULT, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::INITIATIVE, Operation::SUB, 2, CardType::PLAY_CARD);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::���������¼���:
	{
		FateCard* card = new FateCard(L"���� �� ���� ����");
		card->GetComponent<CardTexture>()->SetIllustration(L"���������¼���");
		card->InitializeFateCard(Rarity::DEFAULT, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<DestinationMod>()->InitializeDestinationMod(CardType::PLAYER_PLAY_CARD, Destination::FARTHEST_ENEMY);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::���ð���:
	{
		FateCard* card = new FateCard(L"���ð���");
		card->GetComponent<CardTexture>()->SetIllustration(L"���ð���");
		card->InitializeFateCard(Rarity::COMMON, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::ATTACK_COUNT, Operation::ADD, 1, CardType::PLAY_CARD);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::������â:
	{
		FateCard* card = new FateCard(L"���� ��â");
		card->GetComponent<CardTexture>()->SetIllustration(L"������â");
		card->InitializeFateCard(Rarity::COMMON, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::INITIATIVE, Operation::ADD, 2, CardType::PLAY_CARD);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::����극��ũ:
	{
		FateCard* card = new FateCard(L"���� �극��ũ");
		card->GetComponent<CardTexture>()->SetIllustration(L"����극��ũ");
		card->InitializeFateCard(Rarity::COMMON, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::DEFENSE, Operation::MUL, 0, CardType::ENEMY_PLAY_CARD);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::��ħ���߱�:
	{
		FateCard* card = new FateCard(L"��ħ ���߱�");
		card->GetComponent<CardTexture>()->SetIllustration(L"��ħ���߱�");
		card->InitializeFateCard(Rarity::UNCOMMON, 2, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<AllValueMod>()->InitializeAllValueMod(Attribute::INITIATIVE, Operation::DIV, 2);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::�������:
	{
		FateCard* card = new FateCard(L"��� ����");
		card->GetComponent<CardTexture>()->SetIllustration(L"�������");
		card->InitializeFateCard(Rarity::UNCOMMON, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::INITIATIVE, Operation::SUB, 2, CardType::PLAYER_PLAY_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::DAMAGE, Operation::ADD, 5, CardType::PLAYER_PLAY_CARD);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::�̷�����:
	{
		FateCard* card = new FateCard(L"�̷� ����");
		card->GetComponent<CardTexture>()->SetIllustration(L"�̷�����");
		card->InitializeFateCard(Rarity::UNCOMMON, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::INITIATIVE, Operation::ADD, 2, CardType::ENEMY_PLAY_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::DAMAGE, Operation::SUB, 5, CardType::ENEMY_PLAY_CARD);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::���ھ���:
	{
		FateCard* card = new FateCard(L"���� ����");
		card->GetComponent<CardTexture>()->SetIllustration(L"���ھ���");
		card->InitializeFateCard(Rarity::UNCOMMON, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<DestinationMod>()->InitializeDestinationMod(CardType::PLAYER_PLAY_CARD, Destination::ALL_ENEMIES);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::�����ݸ�:
	{
		FateCard* card = new FateCard(L"���� �ݸ�");
		card->GetComponent<CardTexture>()->SetIllustration(L"�����ݸ�");
		card->InitializeFateCard(Rarity::UNCOMMON, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::DEFENSE, Operation::ADD, 10, CardType::PLAYER_PLAY_CARD);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::�߹���:
	{
		FateCard* card = new FateCard(L"�߹���");
		card->GetComponent<CardTexture>()->SetIllustration(L"�߹���");
		card->InitializeFateCard(Rarity::UNCOMMON, 2, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<OperationMod>();
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::�ð����ر�:
	{
		FateCard* card = new FateCard(L"�ð��� �ر�");
		card->GetComponent<CardTexture>()->SetIllustration(L"�ð����ر�");
		card->InitializeFateCard(Rarity::UNCOMMON, 2, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::INITIATIVE, Operation::ADD, 5, CardType::ENEMY_PLAY_CARD);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::������̱�:
	{
		FateCard* card = new FateCard(L"���� ���̱�");
		card->GetComponent<CardTexture>()->SetIllustration(L"������̱�");
		card->InitializeFateCard(Rarity::UNCOMMON, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<TypeMod>()->InitializeTypeMod(Attribute::DAMAGE, Attribute::DEFENSE, CardType::PLAYER_PLAY_CARD);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::���ɼ���ȭ:
	{
		FateCard* card = new FateCard(L"���ɼ� ��ȭ");
		card->GetComponent<CardTexture>()->SetIllustration(L"���ɼ���ȭ");
		card->InitializeFateCard(Rarity::UNCOMMON, 2, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<DestinationMod>()->InitializeDestinationMod(CardType::PLAYER_PLAY_CARD, Destination::ALL_ENEMIES);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::DAMAGE, Operation::ADD, 9, CardType::PLAYER_PLAY_CARD);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::ȿ������:
	{
		FateCard* card = new FateCard(L"ȿ�� ����");
		card->GetComponent<CardTexture>()->SetIllustration(L"ȿ������");
		card->InitializeFateCard(Rarity::UNCOMMON, 0, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::FATE_ENERGY, Operation::ADD, 2, CardType::NONE);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::�����ȸ�߽ð�:
	{
		FateCard* card = new FateCard(L"����� ȸ�߽ð�");
		card->GetComponent<CardTexture>()->SetIllustration(L"�����ȸ�߽ð�");
		card->InitializeFateCard(Rarity::RARE, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<KeywordParts>()->InitializeKeywordParts(Keyword::OVERLOAD);
		card->AddComponent<ParadoxMod>();
		card->SetParadox(true);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::üũ����Ʈ:
	{
		FateCard* card = new FateCard(L"üũ����Ʈ");
		card->GetComponent<CardTexture>()->SetIllustration(L"üũ����Ʈ");
		card->InitializeFateCard(Rarity::RARE, 3, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::DAMAGE, Operation::MUL, 3, CardType::PLAYER_PLAY_CARD);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::�ĸ��ǿ���:
	{
		FateCard* card = new FateCard(L"�ĸ��� ����");
		card->GetComponent<CardTexture>()->SetIllustration(L"�ĸ��ǿ���");
		card->InitializeFateCard(Rarity::RARE, 2, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<KeywordParts>()->InitializeKeywordParts(Keyword::OVERLOAD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::VALUE, Operation::MUL, 2, CardType::PLAYER_FATE_CARD);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::����Ȯ������:
	{
		FateCard* card = new FateCard(L"���� Ȯ�� ����");
		card->GetComponent<CardTexture>()->SetIllustration(L"����Ȯ������");
		card->InitializeFateCard(Rarity::RARE, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<KeywordParts>()->InitializeKeywordParts(Keyword::OVERLOAD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::DAMAGE, Operation::MUL, 0, CardType::ENEMY_PLAY_CARD);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::��ȥ��:
	{
		FateCard* card = new FateCard(L"��ȥ��");
		card->GetComponent<CardTexture>()->SetIllustration(L"��ȥ��");
		card->InitializeFateCard(Rarity::RARE, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<DestinationMod>()->InitializeDestinationMod(CardType::ENEMY_PLAY_CARD, Destination::SELF);
		SetOrigin(card);
		return card;
	}
	break;

	case DefaultFateCard::PlayerCard::���ں�:
	{
		FateCard* card = new FateCard(L"���ں�");
		card->GetComponent<CardTexture>()->SetIllustration(L"���ں�");
		card->InitializeFateCard(Rarity::UNCOMMON, 0, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<KeywordParts>()->InitializeKeywordParts(Keyword::OVERLOAD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::INITIATIVE, Operation::SUB, 5, CardType::PLAYER_PLAY_CARD);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::���༼��:
	{
		FateCard* card = new FateCard(L"���� ����");
		card->GetComponent<CardTexture>()->SetIllustration(L"���༼��");
		card->InitializeFateCard(Rarity::UNCOMMON, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::ATTACK_COUNT, Operation::MUL, 2, CardType::PLAYER_PLAY_CARD);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::���ð���_�з�����:
	{
		FateCard* card = new FateCard(L"���ð���");
		card->GetComponent<CardTexture>()->SetIllustration(L"���ð���");
		card->InitializeFateCard(Rarity::COMMON, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::ATTACK_COUNT, Operation::ADD, 1, CardType::PLAY_CARD);
		card->SetParadox(true);

		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::������â_�з�����:
	{
		FateCard* card = new FateCard(L"���� ��â");
		card->GetComponent<CardTexture>()->SetIllustration(L"������â");
		card->InitializeFateCard(Rarity::COMMON, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::INITIATIVE, Operation::ADD, 2, CardType::PLAY_CARD);
		card->SetParadox(true);

		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::����극��ũ_�з�����:
	{
		FateCard* card = new FateCard(L"���� �극��ũ");
		card->GetComponent<CardTexture>()->SetIllustration(L"����극��ũ");
		card->InitializeFateCard(Rarity::COMMON, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::DEFENSE, Operation::MUL, 0, CardType::ENEMY_PLAY_CARD);
		card->SetParadox(true);

		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::��ħ���߱�_�з�����:
	{
		FateCard* card = new FateCard(L"��ħ ���߱�");
		card->GetComponent<CardTexture>()->SetIllustration(L"��ħ���߱�");
		card->InitializeFateCard(Rarity::UNCOMMON, 2, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<AllValueMod>()->InitializeAllValueMod(Attribute::INITIATIVE, Operation::DIV, 2);
		card->SetParadox(true);

		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::�������_�з�����:
	{
		FateCard* card = new FateCard(L"��� ����");
		card->GetComponent<CardTexture>()->SetIllustration(L"�������");
		card->InitializeFateCard(Rarity::UNCOMMON, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::INITIATIVE, Operation::SUB, 2, CardType::PLAYER_PLAY_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::DAMAGE, Operation::ADD, 5, CardType::PLAYER_PLAY_CARD);
		card->SetParadox(true);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::�̷�����_�з�����:
	{
		FateCard* card = new FateCard(L"�̷� ����");
		card->GetComponent<CardTexture>()->SetIllustration(L"�̷�����");
		card->InitializeFateCard(Rarity::UNCOMMON, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::INITIATIVE, Operation::ADD, 2, CardType::ENEMY_PLAY_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::DAMAGE, Operation::SUB, 5, CardType::ENEMY_PLAY_CARD);
		card->SetParadox(true);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::���ھ���_�з�����:
	{
		FateCard* card = new FateCard(L"���� ����");
		card->GetComponent<CardTexture>()->SetIllustration(L"���ھ���");
		card->InitializeFateCard(Rarity::UNCOMMON, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<DestinationMod>()->InitializeDestinationMod(CardType::PLAYER_PLAY_CARD, Destination::ALL_ENEMIES);
		card->SetParadox(true);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::�����ݸ�_�з�����:
	{
		FateCard* card = new FateCard(L"���� �ݸ�");
		card->GetComponent<CardTexture>()->SetIllustration(L"�����ݸ�");
		card->InitializeFateCard(Rarity::UNCOMMON, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::DEFENSE, Operation::ADD, 10, CardType::PLAYER_PLAY_CARD);
		card->SetParadox(true);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::�߹���_�з�����:
	{
		FateCard* card = new FateCard(L"�߹���");
		card->GetComponent<CardTexture>()->SetIllustration(L"�߹���");
		card->InitializeFateCard(Rarity::UNCOMMON, 2, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<OperationMod>();
		card->SetParadox(true);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::�ð����ر�_�з�����:
	{
		FateCard* card = new FateCard(L"�ð��� �ر�");
		card->GetComponent<CardTexture>()->SetIllustration(L"�ð����ر�");
		card->InitializeFateCard(Rarity::UNCOMMON, 2, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::INITIATIVE, Operation::ADD, 5, CardType::ENEMY_PLAY_CARD);
		card->SetParadox(true);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::������̱�_�з�����:
	{
		FateCard* card = new FateCard(L"���� ���̱�");
		card->GetComponent<CardTexture>()->SetIllustration(L"������̱�");
		card->InitializeFateCard(Rarity::UNCOMMON, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<TypeMod>()->InitializeTypeMod(Attribute::DAMAGE, Attribute::DEFENSE, CardType::PLAYER_PLAY_CARD);
		card->SetParadox(true);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::���ɼ���ȭ_�з�����:
	{
		FateCard* card = new FateCard(L"���ɼ� ��ȭ");
		card->GetComponent<CardTexture>()->SetIllustration(L"���ɼ���ȭ");
		card->InitializeFateCard(Rarity::UNCOMMON, 2, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::DAMAGE, Operation::ADD, 9, CardType::PLAYER_PLAY_CARD);
		card->AddComponent<DestinationMod>()->InitializeDestinationMod(CardType::PLAYER_PLAY_CARD, Destination::ALL_ENEMIES);
		card->SetParadox(true);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::üũ����Ʈ_�з�����:
	{
		FateCard* card = new FateCard(L"üũ����Ʈ");
		card->GetComponent<CardTexture>()->SetIllustration(L"üũ����Ʈ");
		card->InitializeFateCard(Rarity::RARE, 3, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::DAMAGE, Operation::MUL, 3, CardType::PLAYER_PLAY_CARD);
		card->SetParadox(true);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::�ĸ��ǿ���_�з�����:
	{
		FateCard* card = new FateCard(L"�ĸ��� ����");
		card->GetComponent<CardTexture>()->SetIllustration(L"�ĸ��ǿ���");
		card->InitializeFateCard(Rarity::RARE, 2, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<KeywordParts>()->InitializeKeywordParts(Keyword::OVERLOAD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::VALUE, Operation::MUL, 2, CardType::PLAYER_FATE_CARD);
		card->SetParadox(true);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::����Ȯ������_�з�����:
	{
		FateCard* card = new FateCard(L"���� Ȯ�� ����");
		card->GetComponent<CardTexture>()->SetIllustration(L"����Ȯ������");
		card->InitializeFateCard(Rarity::RARE, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<KeywordParts>()->InitializeKeywordParts(Keyword::OVERLOAD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::DAMAGE, Operation::MUL, 0, CardType::ENEMY_PLAY_CARD);
		card->SetParadox(true);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::��ȥ��_�з�����:
	{
		FateCard* card = new FateCard(L"��ȥ��");
		card->GetComponent<CardTexture>()->SetIllustration(L"��ȥ��");
		card->InitializeFateCard(Rarity::RARE, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<DestinationMod>()->InitializeDestinationMod(CardType::ENEMY_PLAY_CARD, Destination::SELF);
		card->SetParadox(true);
		SetOrigin(card);
		return card;
	}
	break;

	case DefaultFateCard::PlayerCard::���ں�_�з�����:
	{
		FateCard* card = new FateCard(L"���ں�");
		card->GetComponent<CardTexture>()->SetIllustration(L"���ں�");
		card->InitializeFateCard(Rarity::UNCOMMON, 0, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<KeywordParts>()->InitializeKeywordParts(Keyword::OVERLOAD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::INITIATIVE, Operation::SUB, 5, CardType::PLAYER_PLAY_CARD);
		card->SetParadox(true);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultFateCard::PlayerCard::���༼��_�з�����:
	{
		FateCard* card = new FateCard(L"���� ����");
		card->GetComponent<CardTexture>()->SetIllustration(L"���༼��");
		card->InitializeFateCard(Rarity::UNCOMMON, 1, CharacterType::PLAYER, CardType::PLAYER_FATE_CARD);
		card->AddComponent<ValueMod>()->InitializeValueMod(Attribute::ATTACK_COUNT, Operation::MUL, 2, CardType::PLAYER_PLAY_CARD);
		card->SetParadox(true);
		SetOrigin(card);
		return card;
	}
	break;
	default:
		return nullptr;
		break;
	}
}

PlayCard* CardFactory::CreateCard(DefaultPlayCard::MonsterCard cardName)
{
	switch (cardName)
	{
	case DefaultPlayCard::MonsterCard::����������:
	{
		PlayCard* card = new PlayCard(L"������ ����");
		card->GetComponent<CardTexture>()->SetIllustration(L"����������");
		card->InitializePlayCard(Rarity::COMMON, CharacterType::ZOMBIE, CardType::ENEMY_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 3);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DEFENSE, 5, Destination::SELF);
		card->AddComponent<StateParts>()->InitializeStateParts(State::DISRUPTION, 1, Destination::PLAYER);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::MonsterCard::������:
	{
		PlayCard* card = new PlayCard(L"������");
		card->GetComponent<CardTexture>()->SetIllustration(L"������");
		card->InitializePlayCard(Rarity::COMMON, CharacterType::ZOMBIE, CardType::ENEMY_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 9);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DAMAGE, 8, Destination::PLAYER);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::MonsterCard::�߼��ع�:
	{
		PlayCard* card = new PlayCard(L"�߼� �ع�");
		card->GetComponent<CardTexture>()->SetIllustration(L"�߼��ع�");
		card->InitializePlayCard(Rarity::COMMON, CharacterType::WEREWOLF, CardType::ENEMY_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 4);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DEFENSE, 7, Destination::SELF);
		card->AddComponent<StateParts>()->InitializeStateParts(State::ENCHANTMENT, 3, Destination::SELF);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::MonsterCard::���ں�:
	{
		PlayCard* card = new PlayCard(L"���ں�");
		card->GetComponent<CardTexture>()->SetIllustration(L"���ں�");
		card->InitializePlayCard(Rarity::COMMON, CharacterType::WEREWOLF, CardType::ENEMY_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 10);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DAMAGE, 7, Destination::PLAYER);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::ATTACK_COUNT, 2, Destination::PLAYER);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::MonsterCard::��������:
	{
		PlayCard* card = new PlayCard(L"��������");
		card->GetComponent<CardTexture>()->SetIllustration(L"��������");
		card->InitializePlayCard(Rarity::COMMON, CharacterType::WEREWOLF, CardType::ENEMY_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 4);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DAMAGE, 13, Destination::PLAYER);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DEFENSE, 7, Destination::SELF);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::MonsterCard::�ʿ����ΰ���:
	{
		PlayCard* card = new PlayCard(L"�ʿ����� ����");
		card->GetComponent<CardTexture>()->SetIllustration(L"�ʿ����ΰ���");
		card->InitializePlayCard(Rarity::COMMON, CharacterType::STALKER, CardType::ENEMY_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 1);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DEFENSE, 10, Destination::ALL_ENEMIES);
		card->AddComponent<StateParts>()->InitializeStateParts(State::QUICK, 2, Destination::SELF);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::MonsterCard::����������:
	{
		PlayCard* card = new PlayCard(L"������ ����");
		card->GetComponent<CardTexture>()->SetIllustration(L"����������");
		card->InitializePlayCard(Rarity::COMMON, CharacterType::STALKER, CardType::ENEMY_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 1);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DAMAGE, 10, Destination::PLAYER);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::MonsterCard::����:
	{
		PlayCard* card = new PlayCard(L"����");
		card->GetComponent<CardTexture>()->SetIllustration(L"����");
		card->InitializePlayCard(Rarity::COMMON, CharacterType::STALKER, CardType::ENEMY_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 7);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DAMAGE, 16, Destination::PLAYER);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::MonsterCard::�ٸ��ɱ�:
	{
		PlayCard* card = new PlayCard(L"�ٸ� �ɱ�");
		card->GetComponent<CardTexture>()->SetIllustration(L"�ٸ��ɱ�");
		card->InitializePlayCard(Rarity::COMMON, CharacterType::STALKER, CardType::ENEMY_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 2);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DAMAGE, 2, Destination::PLAYER);
		card->AddComponent<StateParts>()->InitializeStateParts(State::DISRUPTION, 1, Destination::PLAYER);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::MonsterCard::�÷�����:
	{
		PlayCard* card = new PlayCard(L"�÷�����");
		card->GetComponent<CardTexture>()->SetIllustration(L"�÷�����");
		card->InitializePlayCard(Rarity::COMMON, CharacterType::STALKER, CardType::ENEMY_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 3);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DAMAGE, 6, Destination::PLAYER);
		card->AddComponent<StateParts>()->InitializeStateParts(State::CONFUSION, 2, Destination::PLAYER);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::MonsterCard::������θ��³뷡:
	{
		PlayCard* card = new PlayCard(L"����� �θ��� �뷡");
		card->GetComponent<CardTexture>()->SetIllustration(L"������θ��³뷡");
		card->InitializePlayCard(Rarity::COMMON, CharacterType::FANATIC, CardType::ENEMY_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 9);
		card->AddComponent<StateParts>()->InitializeStateParts(State::IMPENDING_RUIN, 2, Destination::ALL_ENEMIES);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::MonsterCard::�����ǰ�ȣ:
	{
		PlayCard* card = new PlayCard(L"������ ��ȣ");
		card->GetComponent<CardTexture>()->SetIllustration(L"�����ǰ�ȣ");
		card->InitializePlayCard(Rarity::COMMON, CharacterType::FANATIC, CardType::ENEMY_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 1);
		card->AddComponent<StateParts>()->InitializeStateParts(State::WILL_OF_RUIN, 10, Destination::ALL_ENEMIES);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::MonsterCard::¡��:
	{
		PlayCard* card = new PlayCard(L"¡��");
		card->GetComponent<CardTexture>()->SetIllustration(L"¡��");
		card->InitializePlayCard(Rarity::COMMON, CharacterType::FANATIC, CardType::ENEMY_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 6);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DAMAGE, 2, Destination::PLAYER);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::ATTACK_COUNT, 3);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::MonsterCard::�ð����ĵ�:
	{
		PlayCard* card = new PlayCard(L"�ð��� �ĵ�");
		card->GetComponent<CardTexture>()->SetIllustration(L"�ð����ĵ�");
		card->InitializePlayCard(Rarity::COMMON, CharacterType::GOLEM, CardType::ENEMY_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 1);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DAMAGE, 10, Destination::PLAYER);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::MonsterCard::����������:
	{
		PlayCard* card = new PlayCard(L"���� ������");
		card->GetComponent<CardTexture>()->SetIllustration(L"����������");
		card->InitializePlayCard(Rarity::COMMON, CharacterType::GOLEM, CardType::ENEMY_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 7);
		card->AddComponent<StateParts>()->InitializeStateParts(State::ENGINE_OVERLOAD, 2, Destination::SELF);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::MonsterCard::����:
	{
		PlayCard* card = new PlayCard(L"����");
		card->GetComponent<CardTexture>()->SetIllustration(L"����");
		card->InitializePlayCard(Rarity::COMMON, CharacterType::GOLEM, CardType::ENEMY_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 6);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DAMAGE, 9, Destination::PLAYER);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::ATTACK_COUNT, 4);
		SetOrigin(card);
		return card;
	}
	break;
	case DefaultPlayCard::MonsterCard::���ü����:
	{
		PlayCard* card = new PlayCard(L"��� ü����");
		card->GetComponent<CardTexture>()->SetIllustration(L"���ü����");
		card->InitializePlayCard(Rarity::COMMON, CharacterType::GOLEM, CardType::ENEMY_PLAY_CARD);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::INITIATIVE, 9);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DAMAGE, 18, Destination::PLAYER);
		card->AddComponent<AttributeParts>()->InitializeAttributeParts(Attribute::DEFENSE, 25, Destination::SELF);
		card->AddComponent<StateParts>()->InitializeStateParts(State::QUICK, 3, Destination::SELF);
		SetOrigin(card);
		return card;
	}
	break;

	default:
		return nullptr;
	}
}

Rarity CardFactory::GetRandomFateRarity()
{
	RandomGenerator* rngInstance = RandomGenerator::GetInstance();

	double randomValue = static_cast<double>(rngInstance->GetRandomNumber(0, RAND_MAX) / RAND_MAX);
	double cumulativeProbability = 0.0;
	for (const auto& entry : fateRarityProbabilities)
	{
		cumulativeProbability += entry.second;
		if (randomValue < cumulativeProbability)
		{
			return entry.first;
		}
	}
	return Rarity::COMMON;
}

Rarity CardFactory::GetRandomPlayRarity()
{
	RandomGenerator* rngInstance = RandomGenerator::GetInstance();

	double randomValue = static_cast<double>(rngInstance->GetRandomNumber(0, RAND_MAX) / RAND_MAX);
	double cumulativeProbability = 0.0;
	for (const auto& entry : playRarityProbabilities)
	{
		cumulativeProbability += entry.second;
		if (randomValue < cumulativeProbability)
		{
			return entry.first;
		}
	}
	return Rarity::COMMON;
}

PlayCard* CardFactory::MakeRandomPlayCard()
{
	RandomGenerator* rngInstance = RandomGenerator::GetInstance();

	const std::vector<DefaultPlayCard::PlayerCard>& cards = playerPlayCardMap[GetRandomPlayRarity()];

	int randomIndex = rngInstance->GetRandomNumber(0, cards.size() - 1);

	return CreateCard(cards[randomIndex]);
}

FateCard* CardFactory::MakeRandomFateCard()
{
	RandomGenerator* rngInstance = RandomGenerator::GetInstance();

	const std::vector<DefaultFateCard::PlayerCard>& cards = playerFateCardMap[GetRandomFateRarity()];

	int randomIndex = rngInstance->GetRandomNumber(0, cards.size() - 1);

	return CreateCard(cards[randomIndex]);
}


/*test*/
PlayCard* CardFactory::MakeTestPlayerPlayCard()
{
	RandomGenerator* rngInstance = RandomGenerator::GetInstance();

	int randomIndex = rngInstance->GetRandomNumber(0, playerTestPlayCardVector.size() - 1);

	return CreateCard(playerTestPlayCardVector[randomIndex]);
}

PlayCard* CardFactory::MakeTestMonsterPlayCard()
{
	RandomGenerator* rngInstance = RandomGenerator::GetInstance();

	int randomIndex = rngInstance->GetRandomNumber(0, MonsterTestPlayCardVector.size() - 1);

	return CreateCard(MonsterTestPlayCardVector[randomIndex]);
}

FateCard* CardFactory::MakeTestPlayerFateCard()
{
	RandomGenerator* rngInstance = RandomGenerator::GetInstance();

	int randomIndex = rngInstance->GetRandomNumber(0, playerTestFateCardVector.size() - 1);

	return CreateCard(playerTestFateCardVector[randomIndex]);
}

void CardFactory::SetOrigin(Card* card)
{
	std::vector<CardPartsComponent*> cpcs = card->GetComponents<CardPartsComponent>();
	if (!cpcs.empty())
	{
		for (auto cpc : cpcs)
		{
			cpc->SetOriginValue();
		}
	}
	std::vector<CardFuncComponent*> cfcs = card->GetComponents<CardFuncComponent>();
	if (!cfcs.empty())
	{
		for (auto cfc : cfcs)
		{
			cfc->SetOriginValue();
		}
	}
}