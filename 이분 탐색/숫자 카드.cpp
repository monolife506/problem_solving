#include <algorithm>
#include <iostream>
using namespace std;

int cards[500000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, M;
    cin >> N;
    for (size_t i = 0; i < N; ++i)
        cin >> cards[i];

    sort(cards, cards + N);

    cin >> M;
    for (size_t i = 0; i < M; ++i)
    {
        int num;
        cin >> num;
        cout << binary_search(cards, cards + N, num) << " ";
    }

    cout << '\n';
}