#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int num[40000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> num[i];

    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        if (v.empty() || v.back() < num[i])
            v.push_back(num[i]);
        else
            *lower_bound(v.begin(), v.end(), num[i]) = num[i];
    }

    cout << v.size() << '\n';
}