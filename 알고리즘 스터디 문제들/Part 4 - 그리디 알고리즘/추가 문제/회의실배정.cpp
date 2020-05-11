#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    size_t N;
    cin >> N;
    vector<pair<int, int>> C(N);
    for (size_t i = 0; i < N; i++)
        cin >> C[i].second >> C[i].first;

    // pair는 기본으로 정렬될 때 first 항목 기준 오름차순,
    // 만약 first값이 같다면 second 항목 기준 오름차순으로 정렬된다.
    sort(C.begin(), C.end());

    int cnt = 0;
    int cur = 0;
    for (size_t i = 0; i < N; i++)
    {
        if (cur <= C[i].second)
        {
            cur = C[i].first;
            cnt++;
        }
    }
    cout << cnt;
}