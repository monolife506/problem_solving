// 2110번: 공유기 설치

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool getGapPos(const vector<int> &v, int min_gap, int C)
{
    int cnt = 1;
    int gap = 0;
    for (size_t i = 1; i < v.size(); i++)
    {
        gap += (v[i] - v[i - 1]);
        if (gap >= min_gap)
        {
            cnt += 1;
            gap = 0;
        }

        if (cnt >= C)
            break;
    }
    return (cnt >= C);
}

int search(const vector<int> &v, int left, int right, int C)
{
    int middle = (left + right) / 2;
    bool is_gap_possible = getGapPos(v, middle, C);

    if (is_gap_possible)
    {
        if (getGapPos(v, middle + 1, C))
            return search(v, middle + 1, right, C);
        else
            return middle;
    }
    else
        return search(v, left, middle - 1, C);
}

int main()
{
    size_t N, C;
    cin >> N >> C;
    vector<int> house(N);
    for (int &item : house)
        cin >> item;

    sort(house.begin(), house.end());
    cout << search(house, 1, house[N - 1] - house[0], C);
}
