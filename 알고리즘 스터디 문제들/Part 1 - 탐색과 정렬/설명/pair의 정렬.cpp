#include <iostream>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

void array_display(const array<pair<int, int>, 6> &arr)
{
    for (size_t i = 0; i < 6; i++)
        cout << arr[i].first << " " << arr[i].second << '\n';
}

// 이 cmp함수는 먼저 pair의 두번째 값을 기준으로 오름차순 정렬하며,
// 두번째 값이 같다면 첫번째 값을 기분으로 오름차순 정렬한다.
bool cmp(const pair<int, int> &A, const pair<int, int> &B)
{
    if (A.second != B.second)
        return A.second < B.second;
    else
        return A.first < B.first;
}

int main()
{
    // pair의 선언
    pair<int, int> mypair = make_pair(1, 10);

    // pair의 각 자료형은 달라도 상관 없다.
    pair<string, int> name_age = make_pair("안용모", 21);

    // first와 second로 각각의 데이터에 접근할 수 있다.
    cout << name_age.first << " " << name_age.second << '\n';

    array<pair<int, int>, 6> points;
    points[0] = make_pair(20, 4);
    points[1] = make_pair(30, -5);
    points[2] = make_pair(22, -12);
    points[3] = make_pair(30, 22);
    points[4] = make_pair(30, 40);
    points[5] = make_pair(50, -100);

    cout << "\n정렬 이전 배열\n";
    array_display(points);

    sort(points.begin(), points.end());
    cout << "\n기본 정렬 이후 배열\n";
    array_display(points);

    sort(points.begin(), points.end(), cmp);
    cout << "\n비교 함수를 이용한 정렬 이후 배열\n";
    array_display(points);
}