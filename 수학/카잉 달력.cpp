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

// ������ �� == M, N�� �ּҰ����
// <x:y>�� ��Ÿ���� �� == (A % M == x)�� (A % N == y)�� ���ÿ� �����ϴ� A <= (������ ��)