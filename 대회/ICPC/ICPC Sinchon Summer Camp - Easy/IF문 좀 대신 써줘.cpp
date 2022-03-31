#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<string, int> P;
typedef pair<int, int> intP;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    int curName = 0, curPower = 0;
    cin >> N >> M;

    vector<P> name(N);
    vector<intP> power(M);
    vector<string> ans(M);
    for (size_t i = 0; i < N; i++)
        cin >> name[i].first >> name[i].second;
    for (size_t i = 0; i < M; i++)
    {
        cin >> power[i].first;
        power[i].second = i;
    }

    sort(power.begin(), power.end());
    while (curName < N)
    {
        while (curPower < M && name[curName].second >= power[curPower].first)
        {
            ans[power[curPower].second] = name[curName].first;
            curPower++;
        }

        if (curPower == M)
            break;

        while (curName < N && name[curName].second < power[curPower].first)
            curName++;
    }

    for (string &str : ans)
        cout << str << '\n';
}