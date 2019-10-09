// DeckofCards.cpp : class DeckofCards 내의 함수 정의 

#include <array>
#include <cstdlib>
#include "DeckofCards.h"
#include "Card.h"
using namespace std;

// 기본 생성자 : deck을 조커를 제외한 모든 카드가 한장씩 들어있는 상태 (52장)으로 정의
DeckofCards::DeckofCards()
{
	int count{ 0 };
	for (size_t i = 0; i < Card::card_suit.size(); i++)
	{
		for (size_t j = 1; j < Card::card_face.size(); j++)
		{
			deck[count++] = Card(j, i);
		}
	}

	currentCard = 0;
}

// 카드를 셔플하고 처음부터 딜링을 시작함
void DeckofCards::shuffle()
{
	size_t shuffle_point;
	static Card shuffle_card;
	for (size_t shifter = 0; shifter < 52; shifter++)
	{
		shuffle_point = rand() % 52;
		shuffle_card = deck[shuffle_point];
		deck[shuffle_point] = deck[shifter];
		deck[shifter] = shuffle_card;
	}

	currentCard = 0;
}

// 카드를 한장 줌
Card DeckofCards::dealCard()
{
	if (currentCard <= 51)
	{
		return deck[currentCard++];
	}
	else
	{
		throw out_of_range("All cards in deck are given.");
	}
}

// 카드를 더 줄 수 있는지 확인
bool DeckofCards::moreCard()
{
	if (currentCard >= 52)
	{
		return false;
	}
	else
	{
		return true;
	}
}
