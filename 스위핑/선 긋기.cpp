// 2170번: 선 긋기

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Line
{
    int start;
    int end;
};

bool cmp(const Line &A, const Line &B)
{
    return A.start < B.start;
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    size_t N;
    cin >> N;
    vector<Line> lines(N);
    for (Line &item : lines)
        cin >> item.start >> item.end;

    sort(lines.begin(), lines.end(), cmp);
    unsigned int total = lines[0].end - lines[0].start;
    int end = lines[0].end;
    for (size_t i = 1; i < N; i++)
    {
        if (lines[i].start <= end)
        {
            if (end < lines[i].end)
            {
                total += lines[i].end - end;
                end = lines[i].end;
            }
        }
        else
        {
            total += lines[i].end - lines[i].start;
            end = lines[i].end;
        }
    }
    cout << total;
}

// 1 100
// 4 23
// 5 97
// 49 94