// 2565번: 전깃줄

#include <iostream>
#include <array>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

array<int, 500> cnt{};

int main()
{
    size_t N;
    cin >> N;

    pair<int, int> line;
    vector<pair<int, int>> lines;
    for (size_t i = 0; i < N; i++)
    {
        cin >> line.first >> line.second;
        lines.push_back(line);
    }
    sort(lines.begin(), lines.end());

    size_t len{};
    for (size_t i = 0; i < N - 1; i++)
    {
        for (size_t j = i + 1; j < N; j++)
        {
            if (cnt[j] < cnt[i] + 1 && lines[i].second < lines[j].second)
            {
                cnt[j] = cnt[i] + 1;
                if (cnt[j] > len)
                {
                    len = cnt[j];
                }
            }
        }
    }
    cout << N - (len + 1);
}