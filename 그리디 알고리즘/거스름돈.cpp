#include <iostream>
#include <array>
using namespace std;

int main()
{
	size_t N; cin >> N;
	N = 1000 - N;
	array<int, 6> money{ 500, 100, 50, 10, 5, 1 };

	size_t count{ 0 };
	for (size_t i = 0; N != 0; i++)
	{
		count += (N / money[i]);
		N = (N % money[i]);
	}
	cout << count;
}