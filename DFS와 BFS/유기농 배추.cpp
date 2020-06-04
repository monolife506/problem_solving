// 1012번 : 유기농 배추

#include <iostream>
#include <vector>
using namespace std;

size_t T, M, N, K;
void DFS(int from, vector<bool>& ck, vector<vector<bool>>& con)
{
	for (size_t to = 0; to < N * M; to++)
	{
		if (ck[to] && con[from][to])
		{
			ck[to] = false;
			DFS(to, ck, con);
		}
	}
}

int main()
{
	int X, Y, cl; cin >> T;
	for (size_t testcase = 0; testcase < T; testcase++)
	{
		cin >> M >> N >> K;
		vector<bool> check(N * M, 0);
		vector<vector<bool>> connect(N * M, vector<bool>(N * M, 0));
		for (size_t i = 0; i < K; i++)
		{
			cin >> X >> Y;
			cl = X + M * Y;
			check[cl] = true;

			if (Y != 0) connect[cl][cl - M] = true;
			if (Y != N - 1) connect[cl][cl + M] = true;
			if (X != 0) connect[cl][cl - 1] = true;
			if (X != M - 1) connect[cl][cl + 1] = true;
		}

		int ans{ 0 };
		for (size_t j = 0; j < N * M; j++)
		{
			if (check[j])
			{
				DFS(j, check, connect);
				ans++;
			}
		}
		cout << ans << '\n';
	}
}