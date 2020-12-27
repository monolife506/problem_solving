#include <iostream>
#include <bitset>
using namespace std;

bitset<20> trains[100001];
bool flag[1 << 21];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, action, I, X;
    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        cin >> action;
        switch (action)
        {
        case 1:
            cin >> I >> X;
            trains[I].set(X - 1, 1);
            break;

        case 2:
            cin >> I >> X;
            trains[I].set(X - 1, 0);
            break;

        case 3:
            cin >> I;
            trains[I] <<= 1;
            break;

        case 4:
            cin >> I;
            trains[I] >>= 1;
            break;
        }
    }

    int ans = 0;
    for (size_t i = 1; i <= N; i++)
    {
        int cur = trains[i].to_ullong();
        if (!flag[cur])
        {
            flag[cur] = true;
            ans++;
        }
    }
    cout << ans;
}