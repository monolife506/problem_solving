#include <iostream>
#include <vector>
using namespace std;

int cache[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&cache[0], 100001, 987654321);

    int N;
    cin >> N;

    vector<int> square_num;
    for (int i = 1; i * i <= N; ++i)
        square_num.push_back(i * i);

    cache[0] = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int num : square_num)
        {
            if (i + num <= N)
                cache[i + num] = min(cache[i + num], cache[i] + 1);
        }
    }

    cout << cache[N] << '\n';
}