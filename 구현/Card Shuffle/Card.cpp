// Card.cpp : Card.h의 함수 정의

#include <array>
#include <string>
#include "Card.h"
using namespace std;

// 카드의 숫자와 K, Q, J의 이름이 담긴 String
const array<string, 14> Card::card_face
{ "" ,"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "King", "Queen", "Jack" };
// 카드의 무늬 (스페이드, 하트, 다이아몬드, 클럽)가 담긴 String
const array<string, 4> Card::card_suit
{ "Spades", "Hearts", "Diamonds", "Clubs" };

// 생성자 : enum을 이용한 face와 suit 결정
Card::Card(int face_, int suit_ ) : face(face_), suit(suit_) {}

// 카드의 정보를 "[Face] of [Suit]" 형태의 string으로 return
string Card::toString()
{
	string tmp;
	tmp = card_face[face] + " of " + card_suit[suit];
	return tmp;
}

// 카드의 숫자 return
int Card::getFace() const { return face; };
// 카드의 문양 return
int Card::getSuit() const { return suit; };