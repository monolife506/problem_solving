// 2261번: 가장 가까운 두 점

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> Point;

int getDist(const Point &A, const Point &B)
{
    return (B.first - A.first) * (B.first - A.first) +
           (B.second - A.second) * (B.second - A.second);
}

bool cmp(const Point &A, const Point &B) // Y축 기준 정렬
{
    if (A.second != B.second)
        return A.second < B.second;
    else
        return A.first < B.first;
}

int main()
{
    size_t N;
    cin >> N;
    vector<Point> input;
    set<Point> candidate;
    for (Point &point : input)
        cin >> point.first >> point.second;

    sort(input.begin(), input.end()); // X축 기준 정렬
    int start = 0;
    int min_dist = getDist(input[0], input[1]);
    candidate.insert(input[0], input[1]);
    for (size_t i = 2; i < N; i++) // i는 끝 점의 index이다.
    {
        // 시작 점은 끝점의 X좌표보다 작으므로, 지금까지의 점들이 한번씩은 후보자에 들어갔을 때
        // 남아있는 시작 점의 index만으로 탐색이 가능하다.
        while (start < i)
        {
            // X좌표간의 거리가 최소 거리보다 큰 점은 후보자에서 제외한다.
            int x_dist = input[i].first - input[start].first;
            if (x_dist * x_dist > min_dist)
            {
                candidate.erase(input[start]);
                start += 1; // 다음 후보자 탐색
            }
            else // 작다면 후보자에 넣어진 나머지 모든 점도 후보자가 됨이 자명하다.
                break;
        }

        sort(candidate.begin(), candidate.end(), cmp); // Y축 기준 정렬

        // 후보자 내에서, y좌표가 y - d ~ y + d인 점들만 고를 수 있도록 bound를 설정한다.
        Point y_low = {INT32_MIN, input[i].second - min_dist};
        Point y_max = {INT32_MAX, input[i].second + min_dist};
        auto start_point = lower_bound(candidate.begin(), candidate.end(), y_low, cmp);
        auto end_point = upper_bound(candidate.begin(), candidate.end(), y_max, cmp);

        // X좌표와 Y좌표 모두 범위 내엔 후보자 중에서 최단 거리를 탐색한다.
        for (auto it = start_point; it != end_point; ++it)
        {
            int dist = getDist(input[i], *it);
            if (dist < min_dist)
                min_dist = dist;
        }

        // 후보자에 현재 점을 추가하고, 다음 점으로 이동한다.
        candidate.insert(input[i]);
    }
}