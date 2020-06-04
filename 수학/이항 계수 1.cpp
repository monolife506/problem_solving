// 11050번 : 이항 계수 1

#include <iostream>
using namespace std;

int C(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}
	else if (n == k)
	{
		return 1;
	}
	else
	{
		return C(n - 1, k - 1) + C(n - 1, k);
	}
}

int main()
{
	size_t n, k;
	cin >> n >> k;
	cout << C(n, k);
}