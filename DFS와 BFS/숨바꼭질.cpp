// 1697번 : 숨바꼭질

#include <iostream>
#include <queue>
using namespace std;

struct Moving
{
	int point{ 0 };
	size_t sec{ 0 };
};

int main()
{
	size_t lastsec;
	int N, K, point_now; cin >> N >> K;
	int check[200000] = {};
	queue<Moving> Q; Q.push({ N, 0 });
	do
	{
		Moving now = Q.front(); 
		Q.pop(); lastsec = now.sec;
		if (now.point == K) break;
		else if (now.point < K)
		{
			for (int i = -1; i < 2; i++)
			{
				if (i == 0) // X * 2
				{
					point_now = now.point * 2;
					if (point_now < 0 || check[point_now] == true) continue;
					Q.push({ point_now , now.sec + 1 });
					check[point_now] = true;
				}
				else if (i == 1) // X + 1
				{
					point_now = now.point + 1;
					if (point_now < 0 || point_now > K || check[point_now] == true) continue;
					Q.push({ point_now , now.sec + 1 });
					check[point_now] = true;
				}
				else // X - 1
				{
					point_now = now.point - 1;
					if (point_now < 0 || check[point_now] == true) continue;
					Q.push({ point_now , now.sec + 1 });
					check[point_now] = true;
				}
			}
		}
		else // X - 1
		{
			point_now = now.point - 1;
			Q.push({ point_now, now.sec + 1});
		}
	} while (!Q.empty());

	cout << lastsec;
}