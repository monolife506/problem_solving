#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    map<int, vector<int>> sol;

    sol[c].push_back(b);
    for (int x = b - 1; max(a * (x - b) * (x - b) + c, d) > d; --x)
        sol[a * (x - b) * (x - b) + c].push_back(x);
    for (int x = b + 1; max(a * (x - b) * (x - b) + c, d) > d; ++x)
        sol[a * (x - b) * (x - b) + c].push_back(x);

    int N, ans = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int u, v;
        cin >> u >> v;

        for (int x : sol[u])
        {
            if (x == v)
                ++ans;
        }
    }

    cout << ans << '\n';
}

/*

a(x - b)^2 + c = u -> x1, x2
a^2x - 2abx + ab^2 + c - u
x1 or x2 = v

*/