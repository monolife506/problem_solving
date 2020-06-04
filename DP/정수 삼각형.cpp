// 1932번 : 정수 삼각형

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 재귀 풀이
/*
int DP(int line, int order, vector<vector<int>>& input, vector<vector<int>>& sum)
{
	if (line == 0)
	{
		if (sum[line][order] == -1)
			sum[line][order] = input[line][order];
	}
	else if (order == 0)
	{
		if (sum[line - 1][order] == -1)
			sum[line - 1][order] = DP(line - 1, order, input, sum);
		sum[line][order] = sum[line - 1][order] + input[line][order];
		
	}
	else if (order == line)
	{
		if (sum[line - 1][order - 1] == -1)
			sum[line - 1][order - 1] = DP(line - 1, order - 1, input, sum);
		sum[line][order] = sum[line - 1][order - 1] + input[line][order];
	}
	else
	{
		if (sum[line - 1][order] == -1)
			sum[line - 1][order] = DP(line - 1, order, input, sum);
		if (sum[line - 1][order - 1] == -1)
			sum[line - 1][order - 1] = DP(line - 1, order - 1, input, sum);

		if (sum[line - 1][order] >= sum[line - 1][order - 1])
			sum[line][order] = sum[line - 1][order] + input[line][order];
		else
			sum[line][order] = sum[line - 1][order - 1] + input[line][order];
	}
	return sum[line][order];
}
*/

// for문 풀이
void DP(vector<vector<int>>& input, vector<vector<int>>& sum)
{
	for (size_t line = 0; line < input.size(); line++)
	{
		for (size_t order = 0; order <= line; order++)
		{
			if (line == 0)
			{
				sum[line][order] = input[line][order];
				continue;
			}
			else if (order == 0)
				sum[line][order] = sum[line - 1][order];
			else if (order == line)
				sum[line][order] = sum[line - 1][order - 1];
			else
			{
				if (sum[line - 1][order] >= sum[line - 1][order - 1])
					sum[line][order] = sum[line - 1][order];
				else 
					sum[line][order] = sum[line - 1][order - 1];
			}
			sum[line][order] += input[line][order];
		}
	}
}

int main()
{
	size_t N; cin >> N; 
	vector<vector<int>> tri1(N);
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j <= i; j++)
		{
			int tmp; cin >> tmp;
			tri1[i].push_back(tmp);
		}
	}
	vector<vector<int>> tri2;
	for (size_t i = 0; i < N; i++)
		tri2.push_back(vector<int>(i + 1));
	
	DP(tri1, tri2);
	cout << *max_element(tri2[N - 1].begin(), tri2[N - 1].end());
}