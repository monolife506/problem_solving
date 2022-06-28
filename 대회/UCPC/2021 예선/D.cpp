#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

char color[300001];
int score[300001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N >> color;
    for (int i = 0; i < N; ++i)
        cin >> score[i];

    vector<int> num;
    int max_num = score[0];
    bool is_first = true;

    for (int i = 1; i < N; ++i)
    {
        if (color[i] != color[i - 1])
        {
            if (!is_first)
                num.push_back(max_num);
            max_num = 0;
            is_first = false;
        }

        max_num = max(score[i], max_num);
    }

    sort(num.begin(), num.end(), greater<int>());

    ll ans = 0;
    for (int i = 0; i < (num.size() + 2 - 1) / 2; ++i)
        ans += num[i];

    cout << ans << '\n';
}

/*

(W) B W (B) -> (1W), (1B)
(W) B W B (W) -> (1W, 1B), (2B)
(W) B W B W (B) -> (2W), (1W, 1B), (2B)
(W) B W B W B (W) -> (2W, 1B), (1W, 2B), (3B)

*/