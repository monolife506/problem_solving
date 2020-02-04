// 14889번: 스타트와 링크

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

array<array<int, 20>, 20> table;

int main()
{
    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
            cin >> table[i][j];
    }

    int min_diff;
    bool min_diff_flag = false;
    vector<bool> select(N / 2, 0);
    for (size_t i = 0; i < N / 2; i++)
        select.push_back(1);

    do
    {
        int start_stat = 0;
        int link_stat = 0;
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                if (select[i] && select[j])
                    start_stat += table[i][j];
                else if (!select[i] && !select[j])
                    link_stat += table[i][j];
            }
        }

        int diff = abs(start_stat - link_stat);
        if (!min_diff_flag || diff < min_diff)
        {
            min_diff_flag = true;
            min_diff = diff;
        }

    } while (next_permutation(select.begin(), select.end()));
    cout << min_diff;
}