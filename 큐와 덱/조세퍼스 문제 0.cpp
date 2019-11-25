// 11866번 : 조세퍼스 문제 0

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	size_t N, K; cin >> N >> K;
	queue<int> Q;
	for (size_t i = 1; i <= N; i++)
		Q.push(i);
	
	vector<int> nums;
	int now, count{ 1 };
	while (!Q.empty())
	{
		now = Q.front(); Q.pop();
		if (count == K)
		{
			nums.push_back(now);
			count = 0;
		}
		else
			Q.push(now);
		count++;
	}

	cout << "<";
	for (size_t i = 0; i < N; i++)
	{
		cout << nums[i];
		if (i != N - 1)
			cout << ", ";
	}
	cout << ">";
}	
