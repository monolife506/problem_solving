// 1700번: 멀티탭 스케줄링
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    size_t N, K;
    cin >> N >> K;

    vector<int> sc(K);
    for (size_t i = 0; i < K; i++)
        cin >> sc[i];

    set<int> S;
    set<int> tmp;
    int ans = 0;
    int pop_num;
    for (size_t i = 0; i < K; i++)
    {
        if (S.find(sc[i]) == S.end())
        {
            if (S.size() == N)
            {
                tmp = S;
                for (size_t j = i + 1; j < K; j++)
                {
                    if (S.find(sc[j]) != S.end())
                    {
                        pop_num = sc[j];
                        tmp.erase(sc[j]);
                        if (tmp.empty())
                            break;
                    }
                }
                if (!tmp.empty())
                    pop_num = *tmp.begin();
                S.erase(pop_num);
                ans++;
            }
            S.insert(sc[i]);
        }
    }
    cout << ans;
}