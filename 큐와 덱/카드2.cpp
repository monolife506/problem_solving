// 2164¹ø : Ä«µå2

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	size_t N; cin >> N;
	queue<int> Q;
	for (size_t i = 1; i <= N; i++)
		Q.push(i);

	int poped;
	while (Q.size() > 1)
	{
		Q.pop();
		if (Q.size() == 1)
			break;
		poped = Q.front();
		Q.pop(); Q.push(poped);
	}
	cout << Q.front() << endl;
}