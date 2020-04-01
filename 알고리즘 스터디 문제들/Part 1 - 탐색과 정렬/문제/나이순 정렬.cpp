#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, string> &A, const pair<int, string> &B)
{
    return A.first < B.first;
}

int main()
{
    size_t N;
    cin >> N;

    vector<pair<int, string>> v(N);
    for (size_t i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;

    stable_sort(v.begin(), v.end(), cmp);
    for (size_t i = 0; i < N; i++)
        cout << v[i].first << " " << v[i].second << '\n';
}