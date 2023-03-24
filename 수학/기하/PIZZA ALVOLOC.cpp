// 12781번: PIZZA ALVOLOC

#include <iostream>
using namespace std;
typedef pair<int, int> P;

P p[4];

int ccw(int i, int j, int k)
{
    int cross = (p[j].first - p[i].first) * (p[k].second - p[i].second);
    cross -= (p[j].second - p[i].second) * (p[k].first - p[i].first);
    return (cross > 0) - (cross < 0);
}

int main()
{
    for (size_t i = 0; i < 4; i++)
        cin >> p[i].first >> p[i].second;

    cout << (ccw(0, 1, 2) * ccw(0, 1, 3) == -1);
}