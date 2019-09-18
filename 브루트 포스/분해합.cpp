// 2231번 : 분해합

#include <iostream>
#include <string>
using namespace std;

int Decompsum(int num)
{
	string str_num = to_string(num);
	for (size_t i = 0; i < str_num.size(); i++)
		num += (str_num.at(i) - 48);
	return num;
}

int main()
{
	int N; cin >> N;
	for (size_t i = 1; i <= N; i++)
	{
		if (Decompsum(i) == N)
		{
			cout << i << endl;
			break;
		}
		else if (i == N)
			cout << 0 << endl;
	}
}
