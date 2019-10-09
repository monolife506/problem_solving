#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Card.h"
#include "DeckofCards.h"
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	DeckofCards d;
	for (size_t i = 1; d.moreCard() != false; i++)
	{
		cout << setw(18) << left << d.dealCard().toString();
		if (i % 4 == 0 && i != 0)
		{
			cout << endl;
		}
	}

	d.shuffle();
	cout << endl;
	for (size_t i = 1; d.moreCard() != false; i++)
	{
		cout << setw(18) << left << d.dealCard().toString();
		if (i % 4 == 0 && i != 0)
		{
			cout << endl;
		}
	}
}