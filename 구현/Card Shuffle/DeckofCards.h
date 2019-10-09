// DeckofCards.h : class DeckofCards 정의 

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include <array>
#include "Card.h"

class DeckofCards
{
public:
	// 기본 생성자 : deck을 조커를 제외한 모든 카드가 한장씩 들어있는 상태 (52장)으로 정의
	DeckofCards(); 

	void shuffle(); // 카드 셔플
	Card dealCard(); // 카드 주기
	bool moreCard(); // 카드를 더 줄 수 있는지 확인
private:
	std::array<Card, 52> deck; // 52장의 카드가 담긴 덱
	size_t currentCard; // 다음에 줄 카드
};

#endif