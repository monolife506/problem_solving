#include <iostream>
#include <string>
using namespace std;

int main()
{
	int size{ 0 }, A, B; string board, result;
	cin >> board;
	for (size_t i = 0; i < board.length(); i++)
	{
		if (board[i] == 'X')
		{
			size++;
		}
		
		if (board[i] == '.')
		{
			if (size % 2 != 0)
			{
				cout << -1;
				return 0;
			}
			A = (size / 4) * 4; size %= 4;
			B = size;
			result.append(A, 'A');
			result.append(B, 'B');
			result.push_back('.');
			size = 0;
		}
		else if (i == board.length() - 1)
		{
			if (size % 2 != 0)
			{
				cout << -1;
				return 0;
			}
			A = (size / 4) * 4; size %= 4;
			B = size;
			result.append(A, 'A');
			result.append(B, 'B');
		}
	}
	cout << result;
}