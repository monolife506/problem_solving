// 10250╧Ь : ACM хёез

#include <iostream>
using namespace std;

int main()
{
	size_t T, H, W, N;
	cin >> T;
	size_t* floor = new size_t[T]; size_t* num = new size_t[T];
	for (size_t i = 0; i < T; i++)
	{
		cin >> H >> W >> N;
		(N % H == 0) ? floor[i] = H : floor[i] = (N % H);
		(N % H == 0) ? num[i] = N / H : num[i] = (N / H) + 1;
	}
	for (size_t i = 0; i < T; i++)
		cout << floor[i] * 100 + num[i] << '\n';
	delete[] floor; delete[] num;
}