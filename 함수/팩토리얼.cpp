#include <iostream>
using namespace std;

unsigned fac(int N)
{
	unsigned sum{ 1 };
	if (N <= 1)
	{
		return 1;
	}
	else
	{
		return N * fac(N - 1);
	}
}

int main()
{
	int N; cin >> N;
	cout << fac(N) << endl;
}