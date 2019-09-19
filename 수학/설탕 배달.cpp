// 2839번 : 설탕 배달

#include <iostream>
using namespace std;

int main()
{
	unsigned int N;
	cin >> N;
	for (int i = N / 5; i >= 0; i--)
	{
		if ((N - (5 * i)) % 3 == 0)
		{
			cout << i + ((N - (5 * i)) / 3);
			break;
		}
		else if (i == 0 && N % 3 == 0)
		{
			cout << N / 3;
			break;
		}
		else if (i == 0)
		{
			cout << -1;
			break;
		}
	}
}