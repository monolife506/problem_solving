#include <iostream>
using namespace std;
typedef long long ll;

int num[100];
ll cache[21][100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; ++i)
        cin >> num[i];

    cache[num[0]][0] = 1;
    for (size_t i = 0; i < N - 2; ++i)
    {
        for (int n = 0; n <= 20; ++n)
        {
            if (n - num[i + 1] >= 0)
                cache[n - num[i + 1]][i + 1] += cache[n][i];
            if (n + num[i + 1] <= 20)
                cache[n + num[i + 1]][i + 1] += cache[n][i];
        }
    }

    cout << cache[num[N - 1]][N - 2] << '\n';
}