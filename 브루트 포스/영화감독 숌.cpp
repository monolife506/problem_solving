// 1436번 : 영화감독 숌

#include <iostream>
#include <string>
using namespace std;

int main()
{
	size_t N, count = 0;
	string num_str;
	cin >> N;
	for (size_t i = 666;;i++) // 666 : 1, 2666799 : 100
	{
		num_str = to_string(i);
		if (num_str.find("666") != string::npos)
		{
			count++;
			if (count == N)
			{
				cout << i << endl;
				break;
			}
		}
	}
}