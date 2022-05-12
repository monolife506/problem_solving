#include <cmath>
#include <deque>
#include <iostream>
using namespace std;

int N;

void shuffle(deque<int> &cards, int k)
{
    deque<int> poped;

    bool flag = false;
    while (k >= 0)
    {
        int r = (flag) ? (int)pow(2, (k + 1)) - 1 : N - 1;
        int l = r - (int)pow(2, k) + 1;

        // 카드 빼기
        for (int i = l; i <= r; ++i)
            poped.push_back(cards[i]);
        for (int i = l - 1; i >= 0; --i)
            cards[i + (r - l + 1)] = cards[i];
        for (int i = 0; i < (r - l + 1); ++i)
            cards.pop_front();

        // 카드 넣기
        while (!poped.empty())
        {
            cards.push_front(poped.back());
            poped.pop_back();
        }

        flag = true;
        --k;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    deque<int> result(N);
    for (int i = 0; i < N; ++i)
        cin >> result[i];

    for (int k1 = 1; (int)pow(2, k1) < N; ++k1)
    {
        for (int k2 = 1; (int)pow(2, k2) < N; ++k2)
        {
            deque<int> cards(N);
            for (int i = 0; i < N; ++i)
                cards[i] = i + 1;

            shuffle(cards, k1);
            shuffle(cards, k2);
            if (cards == result)
            {
                cout << k1 << " " << k2 << '\n';
                return 0;
            }
        }
    }
}

// 2^k 개 위로 -> 2^(k - 1)개 위로 -> 2^(k - 2)개 위로 -> ... -> 1개 위로