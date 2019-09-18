// 6064번 : 카잉 달력

#include <iostream>
#include <vector>
using namespace std;

int gcd(int A, int B)
{
	return (A % B) ? gcd(B, A % B) : B;
}

int main()
{
	size_t T, M, N, x, y, lcm;
	cin >> T;
	vector<int> k(T);
	for (size_t i = 0; i < T; i++)
	{
		cin >> M >> N >> x >> y;
		lcm = M * N / gcd(M, N);
		if (N == y)
			y = 0;
		for (size_t j = x ;; j += M)
		{
			if (j % N == y)
			{
				k[i] = j;
				break;
			}
			else if (j > lcm)
			{
				k[i] = -1;
				break;
			}
		}
	}
	for (const int item : k)
		cout << item << '\n';
}

// 마지막 해 == M, N의 최소공배수
// <x:y>가 나타내는 해 == (A % M == x)와 (A % N == y)를 동시에 만족하는 A <= (마지막 해)