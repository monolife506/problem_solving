// 9251번: LCS
// 9252번: LCS 2

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    str1 = '0' + str1;
    str2 = '0' + str2;

    int max_cnt = 0;
    int max_i;
    int max_j;
    vector<vector<int>> cnt(str1.size(), vector<int>(str2.size(), 0));

    for (size_t i = 1; i <= str1.size() - 1; i++)
    {
        for (size_t j = 1; j <= str2.size() - 1; j++)
        {
            if (str1[i] == str2[j])
            {
                cnt[i][j] = cnt[i - 1][j - 1] + 1;
                if (cnt[i][j] > max_cnt)
                {
                    max_cnt = cnt[i][j];
                    max_i = i;
                    max_j = j;
                }
            }
            else
                cnt[i][j] = (cnt[i - 1][j] > cnt[i][j - 1]) ? cnt[i - 1][j] : cnt[i][j - 1];
        }
    }

    stack<char> LCS;
    cout << max_cnt << '\n';
    while (max_cnt > 0)
    {
        if (str1[max_i] == str2[max_j])
        {
            LCS.push(str1[max_i]);
            max_i--;
            max_j--;
            max_cnt--;
        }
        else if (cnt[max_i - 1][max_j] > cnt[max_i][max_j - 1])
            max_i--;
        else
            max_j--;
    }

    while (!LCS.empty())
    {
        cout << LCS.top();
        LCS.pop();
    }
}