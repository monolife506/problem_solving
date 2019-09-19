// 1018번 : 체스판 다시 칠하기

#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main()
{
	size_t N, M; 
	cin >> N >> M;
	vector<vector<char>> board(N, vector<char>(M));
	for (auto& line : board)
	{
		for (auto& point : line)
		{
			cin >> point;
		}
	}

	array<array<char, 8>, 8> black; 
	array<array<char, 8>, 8> white;
	
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			if (i % 2 == 0 && j % 2 == 0)
			{
				black[i][j] = 'B';
				white[i][j] = 'W';
			}
			else if (i % 2 == 1 && j % 2 == 0)
			{
				black[i][j] = 'W';
				white[i][j] = 'B';
			}
			else if (i % 2 == 0 && j % 2 == 1)
			{
				black[i][j] = 'W';
				white[i][j] = 'B';
			}
			else
			{
				black[i][j] = 'B';
				white[i][j] = 'W';
			}
		}
	}

	int lowest{ -1 };
	int tmp1, tmp2;
	for (size_t i = 0; i + 7 < N; i++)
	{
		for (size_t j = 0; j + 7 < M; j++)
		{
			tmp1 = 0;
			for (size_t W = i; W < i + 8; W++)
			{
				for (size_t D = j; D < j + 8; D++)
				{
					if (black[W - i][D - j] != board[W][D])
					{
						tmp1++;
					}
				}
			}

			tmp2 = 0;
			for (size_t W = i; W < i + 8; W++)
			{
				for (size_t D = j; D < j + 8; D++)
				{
					if (white[W - i][D - j] != board[W][D])
					{
						tmp2++;
					}
				}
			}

			if (tmp1 < tmp2)
			{
				if (lowest == -1)
				{
					lowest = tmp1;
				}
				else
				{
					if (tmp1 < lowest)
					{
						lowest = tmp1;
					}
				}
			}
			else
			{
				if (lowest == -1)
				{
					lowest = tmp2;
				}
				else
				{
					if (tmp2 < lowest)
					{
						lowest = tmp2;
					}
				}
			}
		}
	}

	cout << lowest << endl;
}