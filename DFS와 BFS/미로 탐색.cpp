// 2178¹ø : ¹Ì·Î Å½»ö

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main()
{
	size_t moving{ 1 };
	size_t N, M; cin >> N >> M;
	vector<vector<bool>> maze(N, vector<bool>(M, 0));
	
	char input[101];
	for (size_t i = 0; i < N; i++)
	{
		cin >> input;
		for (size_t j = 0; j < M; j++)
			maze[i][j] = input[j] - '0';
	}
	 
	size_t first{1}, next{0};
	queue<pair<int, int>> Q; 
	pair<int, int> now; pair<int, int> goal{ make_pair(N - 1, M - 1) };
	Q.push(make_pair(0, 0));
	int current_x, current_y;
	int x_move[4] = { 0, 0, -1, 1 };
	int y_move[4] = { 1, -1, 0, 0 };

	do
	{
		now = Q.front(); Q.pop(); first--;
		if (now == goal) break;
		for (size_t i = 0; i < 4; i++)
		{
			current_x = now.second + x_move[i];
			current_y = now.first + y_move[i];
			if (current_x < 0 || current_x >= M) continue;
			if (current_y < 0 || current_y >= N) continue;
			if (maze[current_y][current_x] == 1)
			{
				maze[current_y][current_x] = 0;
				Q.push(make_pair(current_y, current_x));
				next++;
			}
		}

		if (first == 0 && !Q.empty())
		{
			first = next;
			next = 0; moving++;
		}
	} while (!Q.empty());

	cout << moving << endl;
}

