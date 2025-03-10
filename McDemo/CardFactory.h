#pragma once
#include "Elements.h"
#include <vector>
#include <map>

class PlayCard;
class FateCard;
class Card;

class CardFactory
{
private:

	std::map<Rarity, double> fateRarityProbabilities =
	{
		{ Rarity::COMMON, 0.28 },
		{ Rarity::UNCOMMON, 0.315 },
		{ Rarity::RARE, 0.105 },
		{ Rarity::PARADOX_COMMON, 0.12 },
		{ Rarity::PARADOX_UNCOMMON, 0.135 },
		{ Rarity::PARADOX_RARE, 0.045 }
	};

	std::map<Rarity, double> playRarityProbabilities =
	{
		{ Rarity::COMMON, 0.35 },
		{ Rarity::UNCOMMON, 0.50 },
		{ Rarity::RARE, 1.15 }
	};

	std::map<Rarity, std::vector<DefaultPlayCard::PlayerCard>>
		playerPlayCardMap =
	{
		{ Rarity::COMMON,
		{
			DefaultPlayCard::PlayerCard::����,
		}},
		{ Rarity::UNCOMMON,
		{
			DefaultPlayCard::PlayerCard::�÷�����,
			DefaultPlayCard::PlayerCard::�ǹ�Ÿ��,
			DefaultPlayCard::PlayerCard::��ƴ����,
		}},
		{ Rarity::RARE,
		{
			DefaultPlayCard::PlayerCard::��ź�ǻ��,
			DefaultPlayCard::PlayerCard::�����κ���Ʈ,
		}}
	};

	std::map<Rarity, std::vector<DefaultFateCard::PlayerCard>>
		playerFateCardMap =
	{
		{ Rarity::COMMON,
		{
			DefaultFateCard::PlayerCard::���ð���,
			DefaultFateCard::PlayerCard::������â,
			DefaultFateCard::PlayerCard::����극��ũ,
		}},
		{ Rarity::UNCOMMON,
		{
			DefaultFateCard::PlayerCard::��ħ���߱�,
			DefaultFateCard::PlayerCard::�������,
			DefaultFateCard::PlayerCard::�̷�����,
			DefaultFateCard::PlayerCard::���ھ���,
			DefaultFateCard::PlayerCard::�����ݸ�,
			DefaultFateCard::PlayerCard::�߹���,
			DefaultFateCard::PlayerCard::�ð����ر�,
			DefaultFateCard::PlayerCard::������̱�,
			DefaultFateCard::PlayerCard::���ɼ���ȭ,
			DefaultFateCard::PlayerCard::ȿ������,

		}},
		{ Rarity::RARE,
		{
			DefaultFateCard::PlayerCard::�����ȸ�߽ð�,
			DefaultFateCard::PlayerCard::üũ����Ʈ,
			DefaultFateCard::PlayerCard::�ĸ��ǿ���,
			DefaultFateCard::PlayerCard::����Ȯ������,
			DefaultFateCard::PlayerCard::��ȥ��,
			DefaultFateCard::PlayerCard::���ں�,
			DefaultFateCard::PlayerCard::���༼��,
		}},
		{ Rarity::PARADOX_COMMON,
		{
			DefaultFateCard::PlayerCard::���ð���_�з�����,
			DefaultFateCard::PlayerCard::������â_�з�����,
			DefaultFateCard::PlayerCard::����극��ũ_�з�����,

		}},
		{ Rarity::PARADOX_UNCOMMON,
		{
			DefaultFateCard::PlayerCard::��ħ���߱�_�з�����,
			DefaultFateCard::PlayerCard::�������_�з�����,
			DefaultFateCard::PlayerCard::�̷�����_�з�����,
			DefaultFateCard::PlayerCard::���ھ���_�з�����,
			DefaultFateCard::PlayerCard::�����ݸ�_�з�����,
			DefaultFateCard::PlayerCard::�߹���_�з�����,
			DefaultFateCard::PlayerCard::�ð����ر�_�з�����,
			DefaultFateCard::PlayerCard::������̱�_�з�����,
			DefaultFateCard::PlayerCard::���ɼ���ȭ_�з�����,
		}},
		{ Rarity::PARADOX_RARE,
		{
			DefaultFateCard::PlayerCard::�����ȸ�߽ð�,
			DefaultFateCard::PlayerCard::üũ����Ʈ_�з�����,
			DefaultFateCard::PlayerCard::�ĸ��ǿ���_�з�����,
			DefaultFateCard::PlayerCard::����Ȯ������_�з�����,
			DefaultFateCard::PlayerCard::��ȥ��_�з�����,
			DefaultFateCard::PlayerCard::���ں�_�з�����,
			DefaultFateCard::PlayerCard::���༼��_�з�����,
		}},
	};

	/*Test*/
	std::vector<DefaultFateCard::PlayerCard>
		playerTestFateCardVector =
	{
			DefaultFateCard::PlayerCard::����,
			DefaultFateCard::PlayerCard::ġ��,
			DefaultFateCard::PlayerCard::ġ��_�з�����,
			DefaultFateCard::PlayerCard::�ð�����,
			DefaultFateCard::PlayerCard::���������¼���,
			DefaultFateCard::PlayerCard::���ð���,
			DefaultFateCard::PlayerCard::������â,
			DefaultFateCard::PlayerCard::����극��ũ,
			DefaultFateCard::PlayerCard::��ħ���߱�,
			DefaultFateCard::PlayerCard::�������,
			DefaultFateCard::PlayerCard::�̷�����,
			DefaultFateCard::PlayerCard::���ھ���,
			DefaultFateCard::PlayerCard::�����ݸ�,
			DefaultFateCard::PlayerCard::�߹���,
			DefaultFateCard::PlayerCard::�ð����ر�,
			DefaultFateCard::PlayerCard::������̱�,
			DefaultFateCard::PlayerCard::���ɼ���ȭ,
			DefaultFateCard::PlayerCard::ȿ������,
			DefaultFateCard::PlayerCard::�����ȸ�߽ð�,
			DefaultFateCard::PlayerCard::üũ����Ʈ,
			DefaultFateCard::PlayerCard::�ĸ��ǿ���,
			DefaultFateCard::PlayerCard::����Ȯ������,
			DefaultFateCard::PlayerCard::��ȥ��,
			DefaultFateCard::PlayerCard::���ں�,
			DefaultFateCard::PlayerCard::���༼��,
	};

	std::vector<DefaultPlayCard::PlayerCard>
		playerTestPlayCardVector =
	{
			DefaultPlayCard::PlayerCard::���,
			DefaultPlayCard::PlayerCard::ȸ��,
			DefaultPlayCard::PlayerCard::�ٸ��ɱ�,
			DefaultPlayCard::PlayerCard::����,
			DefaultPlayCard::PlayerCard::����,
			DefaultPlayCard::PlayerCard::�÷�����,
			DefaultPlayCard::PlayerCard::�ǹ�Ÿ��,
			DefaultPlayCard::PlayerCard::��ƴ����,
			DefaultPlayCard::PlayerCard::��ź�ǻ��,
			DefaultPlayCard::PlayerCard::�����κ���Ʈ,
	};

	std::vector<DefaultPlayCard::MonsterCard>
		MonsterTestPlayCardVector =
	{
			DefaultPlayCard::MonsterCard::����������,
			DefaultPlayCard::MonsterCard::������,
			DefaultPlayCard::MonsterCard::�߼��ع�,
			DefaultPlayCard::MonsterCard::���ں�,
			DefaultPlayCard::MonsterCard::��������,
			DefaultPlayCard::MonsterCard::�ʿ����ΰ���,
			DefaultPlayCard::MonsterCard::����������,
			DefaultPlayCard::MonsterCard::����,
			DefaultPlayCard::MonsterCard::�ٸ��ɱ�,
			DefaultPlayCard::MonsterCard::�÷�����,
			DefaultPlayCard::MonsterCard::������θ��³뷡,
			DefaultPlayCard::MonsterCard::�����ǰ�ȣ,
			DefaultPlayCard::MonsterCard::¡��,
			DefaultPlayCard::MonsterCard::�ð����ĵ�,
			DefaultPlayCard::MonsterCard::����������,
			DefaultPlayCard::MonsterCard::����,
			DefaultPlayCard::MonsterCard::���ü����,
	};
	/*----*/
public:
	PlayCard* CreateCard(DefaultPlayCard::PlayerCard cardName);
	FateCard* CreateCard(DefaultFateCard::PlayerCard cardName);
	PlayCard* CreateCard(DefaultPlayCard::MonsterCard cardName);


public:
	Rarity GetRandomFateRarity();
	Rarity GetRandomPlayRarity();

	PlayCard* MakeRandomPlayCard();
	FateCard* MakeRandomFateCard();

	//test
	PlayCard* MakeTestPlayerPlayCard();
	PlayCard* MakeTestMonsterPlayCard();
	FateCard* MakeTestPlayerFateCard();
	void SetOrigin(Card* card);
};

