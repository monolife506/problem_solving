#include <iostream>
using namespace std;

int num[200];
int cache[200];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; ++i)
    {
        cin >> num[i];
        cache[i] = 1;
    }

    int max_len = 1;
    for (size_t i = 0; i < N - 1; ++i)
    {
        for (size_t j = i + 1; j < N; ++j)
        {
            if (num[i] < num[j])
            {
                cache[j] = max(cache[j], cache[i] + 1);
                max_len = max(max_len, cache[j]);
            }
        }
    }

    cout << N - max_len << '\n';
}

// 2 1
// 1 3 2