// 1002번 문제 : 터렛

#include <iostream>
#include <vector>
#include <array>
using namespace std;

short circle_check(int X1, int Y1, int R1, int X2, int Y2, int R2)
{
	int L_square{ (X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2) }; 
	int R_square1{ (R1 + R2) * (R1 + R2) };
	if (L_square > R_square1)
		return 0;
	else if (L_square == R_square1)
		return 1;
	else
	{
		int R_square2{ (R1 - R2) * (R1 - R2) };
		if (L_square == 0 && R_square2 == 0)
			return -1;
		else if (L_square > R_square2)
			return 2;
		else if (L_square == R_square2)
			return 1;
		else
			return 0;
	}
}

int main()
{
	size_t T; cin >> T;
	vector<array<int, 6>> C(T);
	for (auto& arr : C)
	{
		for (auto& item : arr)
			cin >> item;
	}
	for (auto& arr : C)
		cout << circle_check(arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]) << '\n';
}