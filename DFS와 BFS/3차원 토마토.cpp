// 7569번 : 3차원 토마토

#include <iostream>
#include <queue>
using namespace std;

struct Tomato
{
	int x{ 0 };
	int y{ 0 };
	int z{ 0 };
	int day{ 0 };
};

int main()
{
	size_t M, N, H;
	cin >> M >> N >> H;
	int*** box = new int**[H];
	for (size_t i = 0; i < H; i++)
	{
		box[i] = new int* [N];
		for (size_t j = 0; j < N; j++)
			box[i][j] = new int[M];
	}
	
	queue<Tomato> BFS;
	size_t total_tomato{ 0 };
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> box[i][j][k];
				if (box[i][j][k] != -1) total_tomato++;
				if (box[i][j][k] == 1) BFS.push({ k, j, i });
			}
		}
	}

	size_t riped_tomato{ 0 }, last_poped_day{ 0 };
	int x_now, y_now, z_now;
	int dx[6] = {0, 0, 0, 0, 1, -1};
	int dy[6] = {0, 0, 1, -1, 0, 0};
	int dz[6] = {1, -1, 0, 0, 0, 0};

	do
	{
		Tomato now = BFS.front(); 
		BFS.pop(); riped_tomato++;
		last_poped_day = now.day;
		for (size_t i = 0; i < 6; i++)
		{
			x_now = now.x + dx[i];
			y_now = now.y + dy[i];
			z_now = now.z + dz[i];
			if (x_now < 0 || x_now >= M) continue;
			if (y_now < 0 || y_now >= N) continue;
			if (z_now < 0 || z_now >= H) continue;
			if (box[z_now][y_now][x_now] == 0)
			{
				box[z_now][y_now][x_now] = 1;
				BFS.push({ x_now, y_now, z_now, now.day + 1 });
			}
		}
	} while (!BFS.empty());

	if (riped_tomato == total_tomato)
		cout << last_poped_day << endl;
	else
		cout << -1 << endl;
}
	