// 7576번 : 토마토

#include <iostream>
#include <array>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	size_t M, N; cin >> M >> N;
	vector<vector<short>> box(N, vector<short>(M, 0));

	queue<int> Q;
	size_t total_tomato{0};
	vector<int> initial_riped;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			cin >> box[i][j];
			if (box[i][j] != -1)
				total_tomato++;
			if (box[i][j] == 1)
				Q.push(i * M + j);
		}
	}
	
	int current_x, current_y, day{ 0 };
	size_t riped_tomato{ 0 }, day_tomato{ Q.size() }, nextday_tomato{ 0 };
	array<short, 4> x_move = {0, 0, -1, 1};
	array<short, 4> y_move = {1, -1, 0, 0};
	
	do
	{
		int now = Q.front(); Q.pop(); 
		riped_tomato++; day_tomato--;
		for (size_t i = 0; i < 4; i++)
		{
			current_x = (now % M) + x_move[i];
			current_y = (now / M) + y_move[i];
			if (current_x < 0 || current_x >= M) continue;
			if (current_y < 0 || current_y >= N) continue;
			if (box[current_y][current_x] == 0)
			{
				box[current_y][current_x] = 1;
				Q.push(current_y * M + current_x);
				nextday_tomato++;
			}
		}

		if (day_tomato == 0 && !Q.empty())
		{
			day_tomato = nextday_tomato;
			nextday_tomato = 0; day++;
		}

	} while (!Q.empty());

	if (riped_tomato != total_tomato)
		cout << -1 << endl;
	else
		cout << day << endl;
}