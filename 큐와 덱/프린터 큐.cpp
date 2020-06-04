// 1966번 : 프린터 큐

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct document
{
	int importence;
	size_t order;
};

int main()
{
	size_t T; cin >> T;
	size_t N, M; int num, count{ 0 };
	for (size_t testcase = 0; testcase < T; testcase++)
	{
		count = 0;
		queue<document> print;
		vector<int> priority;
		cin >> N >> M;
		for (size_t i = 0; i < N; i++)
		{
			cin >> num;
			print.push({num, i});
			priority.push_back(num);
		}
		sort(priority.begin(), priority.end());
		num = priority[--N];
		
		while (!print.empty())
		{
			if (print.front().importence == num)
			{
				count++;
				if (print.front().order == M)
					break;
				print.pop();
				num = priority[--N];
			}
			else
			{
				document now = print.front();
				print.pop();
				print.push(now);
			}
		}

		cout << count << '\n';
	}
}
