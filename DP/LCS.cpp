// 9251번: LCS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    vector<vector<int>> cnt(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    for (size_t i = 1; i <= str1.size(); i++)
    {
        for (size_t j = 1; j <= str2.size(); j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                cnt[i][j] = cnt[i - 1][j - 1] + 1;
            }
            else
            {
                cnt[i][j] = (cnt[i - 1][j] > cnt[i][j - 1]) ? cnt[i - 1][j] : cnt[i][j - 1];
            }
        }
    }
    cout << *(max_element(cnt[str1.size()].begin(), cnt[str1.size()].end()));
}