// 1260¹ø : DFS¿Í BFS

#include <iostream>
#include <array>
#include <stack>
#include <queue>
using namespace std;

array<bool, 1001> visited{};
array<array<bool, 1001>, 1001> node{};

void DFS(int start, size_t points)
{
	stack<int> S; S.push(start);
	visited[start] = true;
	cout << start << " ";
	do 
	{
		for (size_t goal = 1; goal <= points; goal++)
		{
			if (!visited[goal] && node[S.top()][goal])
			{
				S.push(goal); visited[goal] = true;
				cout << goal << " "; break;
			}
			else if (goal == points) S.pop();
		}
	} while (!S.empty());
}

void BFS(int start, size_t points)
{
	queue<int> Q; Q.push(start);
	visited[start] = true;
	cout << start << " ";
	do
	{
		int now = Q.front(); Q.pop();
		for (size_t goal = 1; goal <= points; goal++)
		{
			if (!visited[goal] && node[now][goal])
			{
				Q.push(goal); visited[goal] = true;
				cout << goal << " ";
			}
		}
	} while (!Q.empty());
}

int main()
{
	size_t N, M, V;
	size_t tmp1, tmp2;
	cin >> N >> M >> V;
	for (size_t i = 0; i < M; i++)
	{
		cin >> tmp1 >> tmp2;
		node[tmp1][tmp2] = true;
		node[tmp2][tmp1] = true;
	}

	DFS(V, N);
	cout << '\n';
	visited = {};
	BFS(V, N);
}