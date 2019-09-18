// 2751번 : 수 정렬하기 2
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	size_t N; cin >> N;
	vector<int> v(N);
	for (int& item : v)
		cin >> item;
	sort(v.begin(), v.end());
	for (int& item : v)
		cout << item << '\n';
}

// merge sort 구현
/*
void merge(int list[], int left, int middle, int right)
{
	int i{ left }, j{ middle + 1 }, k{ left }, tmp;
	int* sorted = new int[right + 1];

	while (i <= middle && j <= right)
	{
		list[i] < list[j] ?
		sorted[k++] = list[i++] : sorted[k++] = list[j++];
	}

	tmp = (i > middle) ? j : i;
	while (k <= right)
	{
		sorted[k++] = list[tmp++];
	}

	for (size_t l = left; l <= right; l++)
	{
		list[l] = sorted[l];
	}

	delete[] sorted;
}

void merge_sort(int list[], int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) / 2;
		merge_sort(list, left, middle);
		merge_sort(list, middle + 1, right);
		merge(list, left, middle, right);
	}
}

int main()
{
	int N, tmp; cin >> N;
	int* list = new int[N];
	for (size_t i{ 0 }; i < N; i++)
	{
		cin >> tmp;
		list[i] = tmp;
	}

	merge_sort(list, 0, N - 1);
	for (size_t i{ 0 }; i < N; i++)
	{
		cout << list[i] << '\n';
	}
}
*/