// 2108? : ???

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct num_count
{
	int num;
	size_t count{ 0 };
	num_count(int _num) : num(_num) {}
};

bool compare(const num_count& x, const num_count& y)
{
	if (x.count == y.count)
	{
		return x.num < y.num;
	}
	return x.count > y.count;
}

int main()
{
	size_t N; cin >> N;
	vector<short> list(N);
	vector<num_count> count_list;
	for (int i = -4000; i <= 4000; i++)
	{
		count_list.push_back(num_count(i));
	}
	for (short& num : list) 
	{
		cin >> num;
		count_list[num + 4000].count++;
	}
	sort(list.begin(), list.end());
	sort(count_list.begin(), count_list.end(), compare);

	// »ê¼úÆò±Õ
	double sum{ 0 }; 
	for (short& num : list)
	{
		sum += num;
	}
	sum /= N;
	cout << floor(sum + 0.5) << endl;

	// Áß¾Ó°ª
	cout << list[N / 2] << endl;

	// ÃÖºó°ª
	if (N != 1)
	{
		if (count_list[0].count == count_list[1].count)
		{
			cout << count_list[1].num << endl;
		}
		else
		{
			cout << count_list[0].num << endl;
		}
	}
	else
	{
		cout << list[0] << endl;
	}

	// ¹üÀ§
	short range{list[N - 1] - list[0]};
	cout << range << endl;
}