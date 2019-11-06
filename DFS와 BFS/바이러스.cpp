// 2606번 : 바이러스

#include <iostream>
#include <array>
#include <stack>
using namespace std;

array<array<bool, 101>, 101> connect{};
array<bool, 101> virus{};

int main()
{
	size_t N, pairs; 
	cin >> N >> pairs;

	size_t c1, c2;
	for (size_t i = 0; i < pairs; i++)
	{
		cin >> c1 >> c2;
		connect[c1][c2] = true;
		connect[c2][c1] = true;
	}

	int ans{ 0 };
	virus[1] = true; 
	stack<int> dfs; dfs.push(1);
	while (!dfs.empty())
	{
		for (size_t goal = 1; goal < 101; goal++)
		{
			if (connect[dfs.top()][goal] && !virus[goal])
			{
				dfs.push(goal); virus[goal] = true;
				ans++; break;
			}
			else if (goal == 100)
			{
				dfs.pop();
			}
		}
	}
	cout << ans;
}