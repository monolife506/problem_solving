#include <iostream>
#include <string>
#include <queue>
using namespace std;

// 직접 구현하는 경우
/*
int main()
{
	int* queue = new int[20000];
	int start{ 0 };
	int last{ 0 };
	
	string input; int push_num;
	size_t N; cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		cin >> input;
		if (input == "push")
		{
			cin >> push_num;
			queue[last++] = push_num;
		}
		else if (input == "pop")
		{	
			if (last - start != 0)
			{
				cout << queue[start] << '\n';
				queue[start++] = NULL;
			}
			else
				cout << -1 << '\n';
		}
		else if (input == "size")
			cout << last - start << '\n';
		else if (input == "empty")
		{
			if (last - start == 0)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (input == "front")
		{
			if (last - start != 0)
				cout << queue[start] << '\n';
			else
				cout << -1 << '\n';
		}
		else if (input == "back")
		{
			if (last - start != 0)
				cout << queue[last - 1] << '\n';
			else
				cout << -1 << '\n';
		}
	}

	delete[] queue;
}
*/

// STL을 이용하는 경우
int main()
{
	queue<int> Q;
	string input; int push_num;
	size_t N; cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		cin >> input;
		if (input == "push")
		{
			cin >> push_num;
			Q.push(push_num);
		}
		else if (input == "pop")
		{
			if (Q.empty()) cout << -1 << '\n';
			else
			{
				cout << Q.front() << '\n';
				Q.pop();
			}
		}
		else if (input == "size")
			cout << Q.size() << '\n';
		else if (input == "empty")
			cout << Q.empty() << '\n';
		else if (input == "front")
		{
			if (Q.empty()) cout << -1 << '\n';
			else cout << Q.front() << '\n';
		}
		else if (input == "back")
		{
			if (Q.empty()) cout << -1 << '\n';
			else cout << Q.back() << '\n';
		}
	}
}