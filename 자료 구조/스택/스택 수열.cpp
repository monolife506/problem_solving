// 1874번 : 스택 수열

#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main()
{
	size_t N; cin >> N;

	int input_num;
	queue<int> seq_ans;
	for (size_t i = 0; i < N; i++)
	{
		cin >> input_num;
		seq_ans.push(input_num);
	}

	stack<int> seq;
	string operation;
	int push_num{ 1 };
	bool isValidSeq{ true };

	while (!seq_ans.empty())
	{
		if (seq.empty())
		{
			seq.push(push_num++);
			operation += '+';
			if (seq.top() > N)
			{
				isValidSeq = false;
				break;
			}
		}	
		else if (seq.top() == seq_ans.front())
		{
			seq.pop();
			seq_ans.pop();
			operation += '-';
		}
		else
		{
			seq.push(push_num++);
			operation += '+';
			if (seq.top() > N)
			{
				isValidSeq = false;
				break;
			}
		}
	}

	if (isValidSeq)
	{
		for (const char& ch : operation)
		{
			cout << ch << '\n';
		}
	}
	else
	{
		cout << "NO";
	}
}
