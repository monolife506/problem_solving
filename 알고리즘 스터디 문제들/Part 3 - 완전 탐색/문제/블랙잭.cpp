#include <iostream>
#include <vector>
using namespace std;

int main()
{
    size_t N, M;
    cin >> N >> M;

    vector<int> cards(N);
    for (size_t i = 0; i < N; i++)
        cin >> cards[i];

    int min_diff = 300'000;
    int diff;
    int sum;

    for (size_t i = 0; i < N - 2; i++)
    {
        for (size_t j = i + 1; j < N - 1; j++)
        {
            for (size_t k = j + 1; k < N; k++)
            {
                diff = M - (cards[i] + cards[j] + cards[k]);
                if (diff >= 0 && min_diff >= diff)
                {
                    min_diff = diff;
                    sum = cards[i] + cards[j] + cards[k];
                }
            }
        }
    }

    cout << sum;
}