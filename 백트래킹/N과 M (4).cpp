// 15652번 : N과 M (4)
// 중복조합

#include <iostream>
#include <vector>
using namespace std;

void H(vector<short>& selected, int start, int n, int r, int target)
{
	if (r == 0)
	{
		for (const short& item : selected)
			cout << item << " ";
		cout << '\n';
	}
	else
	{
		for (size_t i = start; i < n; i++)
		{
			
		}
	}
}

int main()
{
	size_t N, M;
	cin >> N >> M;

	vector<short> selected(M);
	H(selected, 0, N, M, 1);
}