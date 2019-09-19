// 1003번 : 피보나치 함수

#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main()
{
	size_t T; cin >> T;
	vector<short> cases(T);
	for (auto& N : cases)
	{
		cin >> N;
	}

	array<size_t, 2> zero; array<size_t, 2> one;
	for (auto& N : cases)
	{
		zero[0] = 1; zero[1] = 0;
		one[0] = 0; one[1] = 1;
		for (size_t i = 2; i <= N; i++)
		{
			zero[i % 2] += zero[(i + 1) % 2];
			one[i % 2] += one[(i + 1) % 2];
		}
		cout << zero[N % 2] << " " << one[N % 2] << "\n";
	} 
}