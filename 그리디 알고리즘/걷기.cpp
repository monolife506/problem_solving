#include <iostream>
using namespace std;

int main()
{
	unsigned long long X, Y, W, S, left;
	cin >> X >> Y >> W >> S;

	unsigned long long time{ 0 };
	if (S >= 2 * W)
		time += ((X < Y) ? X : Y) * (2 * W);
	else
		time += ((X < Y) ? X : Y) * S;
	left = (X < Y) ? (Y - X) : (X - Y);
	if (S < W)
	{
		time += (left / 2) * 2 * S;
		left %= 2;
	}
	time += left * W;
	cout << time;
}