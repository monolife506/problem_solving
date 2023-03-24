// 2667�� : ������ȣ���̱�

#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

array<array<bool, 625>, 625> connect{};

int main()
{
	size_t N, CP; string tmp; cin >> N;
	vector<bool> maps(N * N, 0);

	// �����¿츦 ���� �̵��� �� �ִ� �׷����� ����
	for (size_t i = 0; i < N; i++)
	{
		cin >> tmp;
		for (size_t j = 0; j < N; j++)
		{
			CP = i * N + j;
			maps[CP] = tmp.at(j) - '0';
			if (i != 0)
				connect[CP][CP - N] = true;
			if (i != N - 1)
				connect[CP][CP + N] = true;
			if (j != 0)
				connect[CP][CP - 1] = true;
			if (j != N - 1)
				connect[CP][CP + 1] = true;
		}
	}
	
	// dfs�� �� ������ ũ�� ���ϱ�
	stack<int> dfs;
	vector<int> answers; int ans{ 1 };
	for (size_t i = 0; i < N * N; i++)
	{
		if (maps[i])
		{
			dfs.push(i); maps[i] = false;
			while (!dfs.empty())
			{
				for (size_t goal = 0; goal < N * N; goal++)
				{
					if (connect[dfs.top()][goal] && maps[goal])
					{
						dfs.push(goal); maps[goal] = false;
						ans++; break;
					}
					else if (goal == N * N - 1)
					{
						dfs.pop();
					}
				}
			}
			answers.push_back(ans); ans = 1;
		}
	}

	// �� vector sort & ���
	sort(answers.begin(), answers.end());
	cout << answers.size() << '\n';
	for (const int& item : answers)
		cout << item << '\n';
}