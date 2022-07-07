#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    set<int> num;
    for (int i = 1; i <= 2 * N; ++i)
        num.insert(i);

    vector<pair<char, int>> block(M);
    vector<vector<int>> chain(M);

    int one_idx = -1;
    for (int i = 0; i < M; ++i)
    {
        char buffer[6];
        cin >> block[i].first >> buffer >> block[i].second;
        num.erase(block[i].second);

        if (block[i].second == 1)
            one_idx = i;
    }

    if (one_idx == -1 || block[0].first == 'B')
    {
        cout << "NO" << '\n';
    }
    else
    {
        bool flag = true;
        for (int i = 0; i < M - 1; ++i)
        {
            if (block[i].first == block[i + 1].first)
            {
                auto it = num.upper_bound(block[i].second);
                if (it == num.end())
                {
                    flag = false;
                    break;
                }
                else
                {
                    chain[i].push_back(*it);
                    num.erase(*it);
                }
            }
        }

        if (block[M - 1].first == 'A')
        {
            auto it = num.upper_bound(block[M - 1].second);
            if (it == num.end())
            {
                flag = false;
            }
            else
            {
                chain[M - 1].push_back(*it);
                num.erase(*it);
            }
        }

        if (flag)
        {
            for (auto it = num.begin(); it != num.end(); ++it)
                chain[one_idx].push_back(*it);
            sort(chain[one_idx].begin(), chain[one_idx].end());

            cout << "YES" << '\n';
            for (int i = 0; i < M; ++i)
            {
                cout << block[i].first << " BLOCK " << block[i].second << '\n';

                char robot = (block[i].first == 'A') ? 'B' : 'A';
                for (int j = 0; j < chain[i].size(); ++j)
                {
                    cout << robot << " CHAIN " << chain[i][j] << '\n';
                    robot = (robot == 'A') ? 'B' : 'A';
                }
            }
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}