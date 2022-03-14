#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P;

const int INF = 987654321;

int N, M;
char maze[101][101];

int bfs(P start, P dest)
{
	static const int dy[] = {-1, 0, 1, 0};
	static const int dx[] = {0, 1, 0, -1};

	queue<P> q;
	vector<vector<int>> dist(N, vector<int>(M, INF));

	q.push(start);
	dist[start.first][start.second] = 0;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (size_t i = 0; i < 4; ++i)
		{
			int nxt_y = y + dy[i];
			int nxt_x = x + dx[i];
			if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= M)
				continue;
			if (maze[nxt_y][nxt_x] == '0')
				continue;

			if (dist[nxt_y][nxt_x] > dist[y][x] + 1)
			{
				dist[nxt_y][nxt_x] = dist[y][x] + 1;
				q.push({nxt_y, nxt_x});
			}
		}
	}

	return dist[dest.first][dest.second];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> maze[i];

	cout << bfs({0, 0}, {N - 1, M - 1}) + 1 << '\n';
}