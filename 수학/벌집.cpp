// 2292번 : 벌집

#include <iostream>
using namespace std;

int main()
{
	unsigned int N;
	cin >> N;
	for (size_t i = 0;;i++)
	{
		if (N >= (3 * i * (i - 1)) + 1 && N <= (3 * i * (i + 1)) + 1)
		{
			cout << i + 1;
			break;
		}
	}
}