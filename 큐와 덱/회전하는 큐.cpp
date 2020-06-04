// 1021번 : 회전하는 큐

#include <iostream>	
#include <deque>
#include <queue>
using namespace std;

int main()
{
	size_t N, M; 
	cin >> N >> M;

	deque<int> D;
	for (size_t i = 1; i <= N; i++)
		D.push_back(i);

	int num; queue<int> pop_nums;
	for (size_t i = 0; i < M; i++)
	{
		cin >> num;
		pop_nums.push(num);
	}

	int now, poped;
	size_t count{ 0 }, diff;
	while (!pop_nums.empty())
	{
		now = pop_nums.front();
		if (now == D.front())
		{
			pop_nums.pop();
			D.pop_front();
		}
		else
		{
			diff = 0;
			while (now != D.front())
			{
				poped = D.back();
				D.pop_back();
				D.push_front(poped);
				diff++;
			}

			if (diff > D.size() / 2)
				diff = D.size() - diff;
			count += diff;
		} 
	}

	cout << count;
}