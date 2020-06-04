// 17298번 : 오큰수

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	size_t N; 
	cin >> N;

	int cur_num;
	stack<int> nums;
	for (size_t i = 0; i < N; i++)
	{
		cin >> cur_num;
		nums.push(cur_num);
	}
	
	stack<int> choice;
	stack<int> NGE;
	for (size_t i = 0; i < N; i++)
	{
		cur_num = nums.top();
		nums.pop();

		while (!choice.empty() && choice.top() <= cur_num) choice.pop();
		if (choice.empty())
		{
			NGE.push(-1);
			choice.push(cur_num);
		}
		else
		{
			NGE.push(choice.top());
			choice.push(cur_num);
		}
	}

	while (!NGE.empty())
	{
		cout << NGE.top() << " ";
		NGE.pop();
	}
}