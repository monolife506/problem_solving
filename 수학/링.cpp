// 3036¹ø : ¸µ

#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
	int r = a % b;
	if (r == 0)
	{
		return b;
	}
	else
	{
		return gcd(b, r);
	}
}

int main()
{
	size_t N;
	cin >> N;

	vector<int> rings(N);
	for (int& r : rings)
	{
		cin >> r;
	}
	int gcd_num;
	for (size_t i = 1; i < N; i++)
	{
		gcd_num = gcd(rings[0], rings[i]);
		cout << rings[0] / gcd_num << '/' << rings[i] / gcd_num << '\n';
	}
}