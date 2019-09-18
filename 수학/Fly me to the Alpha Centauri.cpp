// 1011번 : Fly me to the Alpha Centauri

#include <iostream>
using namespace std;

unsigned sigma_n(int N)
{
	return N * (N + 1) / 2;
}

int main()
{
	size_t T; cin >> T;
	unsigned* X = new unsigned[T]; unsigned* Y = new unsigned[T];
	for (size_t i = 0; i < T; i++)
	{
		cin >> X[i] >> Y[i];
	}
	for (size_t i = 0; i < T; i++)
	{
		unsigned count{ 0 };
		unsigned left{ Y[i] - X[i] };
		unsigned bm{ 0 };
		while (left != 0)
		{
			if (left >= sigma_n(bm) && left < sigma_n(bm + 1))
			{
				count++;
				left -= bm;
			}
			else if (left >= sigma_n(bm))
			{
				count++; bm++;
				left -= bm;
			}
			else
			{
				count++; bm--;
				left -= bm;
			}
		}
		cout << count << '\n';
	}
	delete[] X; delete[] Y;
}