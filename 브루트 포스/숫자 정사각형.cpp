#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	size_t N, M; cin >> N >> M;
	vector<string> Rec(N);
	for (string& colum : Rec)
	{
		cin >> colum;
	}

	size_t max_count{ 0 }, max_size{ 1 }, tmp;
	max_count = (N > M) ? N : M;
	for (size_t i = 1; i <= max_count; i++)
	{
		for (size_t row = 0; row + i < N; row++)
		{
			for (size_t colum = 0; colum + i < M; colum++)
			{
				tmp = Rec[row][colum];
				if (tmp != Rec[row + i][colum + i])
					continue;
				else if (tmp != Rec[row + i][colum])
					continue;
				else if (tmp != Rec[row][colum + i])
					continue;
				else
					max_size = (i + 1) * (i + 1);
			}
		}
	}

	cout << max_size;
}