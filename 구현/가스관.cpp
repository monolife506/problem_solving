#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MAX = 25;
const int BLOCK_CNT = 7;
const char blocks[] = {'|', '-', '+', '1', '2', '3', '4', '.'};
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int R, C;
char europa[MAX + 1][MAX + 1];

unordered_map<char, int> idx;
vector<bool> flag[BLOCK_CNT + 1];

pair<int, int> solve()
{
    flag[idx['|'] = 0] = {true, false, true, false};
    flag[idx['-'] = 1] = {false, true, false, true};
    flag[idx['+'] = 2] = {true, true, true, true};
    flag[idx['1'] = 3] = {true, true, false, false};
    flag[idx['2'] = 4] = {false, true, true, false};
    flag[idx['3'] = 5] = {false, false, true, true};
    flag[idx['4'] = 6] = {true, false, false, true};
    flag[idx['.'] = idx['M'] = idx['Z'] = 7] = {false, false, false, false};

    pair<int, int> ret = {-1, -1};

    for (size_t i = 0; i < R; i++)
    {
        for (size_t j = 0; j < C; j++)
        {
            if (europa[i][j] != '.')
                continue;

            for (size_t block_idx = 0; block_idx < BLOCK_CNT; block_idx++)
            {
                bool is_valid = true;
                for (size_t k = 0; k < 4; k++)
                {
                    int nxt_i = i + dy[k];
                    int nxt_j = j + dx[k];
                    if (nxt_i < 0 || nxt_i >= R || nxt_j < 0 || nxt_j >= C)
                    {
                        if (flag[block_idx][k])
                        {
                            is_valid = false;
                            break;
                        }

                        continue;
                    }

                    char &nxt = europa[nxt_i][nxt_j];
                    if (flag[block_idx][k] && (nxt == 'M' || nxt == 'Z'))
                    {
                        is_valid = false;
                        break;
                    }
                    if (flag[block_idx][k] != flag[idx[nxt]][(k + 2) % 4])
                    {
                        is_valid = false;
                        break;
                    }
                }

                if (is_valid)
                {
                    europa[i][j] = blocks[block_idx];
                    ret.first = i + 1;
                    ret.second = j + 1;
                    return ret;
                }
            }
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;
    for (size_t i = 0; i < R; i++)
        cin >> europa[i];

    pair<int, int> ans = solve();
    cout << ans.first << " " << ans.second << " "
         << europa[ans.first - 1][ans.second - 1] << '\n';
}