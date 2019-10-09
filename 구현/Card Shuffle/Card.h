// Card.h : class Card 정의

#ifndef CARD_H
#define CARD_H

#include <array>
#include <string>

// 카드의 Face (숫자)를 표현하는데 쓰이는 enum
enum Face {Ace = 1, Deuce, Three, Four, Five, Six, Seven, Eight, Nine, Ten, King, Queen, Jack};
// 카드의 Suit (문양)를 표현하는데 쓰이는 enum
enum Suit {Spade, Heart, Diamond, Club};

class Card
{
public:
	static const std::array<std::string, 14> card_face; // 카드의 숫자와 K, Q, J의 이름이 담긴 String
	static const std::array<std::string, 4> card_suit; // 카드의 무늬 (스페이드, 하트, 다이아몬드, 클럽)가 담긴 String

	Card(int = Ace, int = Spade); // 생성자 : enum을 이용한 face와 suit 결정
	std::string toString(); // 카드의 정보를 "[Face] of [Suit]" 형태의 string으로 return
private:
	int face; // 카드의 Face (숫자)
	int suit; // 카드의 Suit (문양)
};

#endif