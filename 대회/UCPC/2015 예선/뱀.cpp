#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, char> Act;
typedef pair<int, int> Point;

ll L, N;
ll curX = 0;
ll curY = 0;
ll curDir = 1;              // 북 -> 동 -> 남 -> 서
ll xDir[4] = {0, 1, 0, -1}; // 북 -> 동 -> 남 -> 서
ll yDir[4] = {1, 0, -1, 0}; // 북 -> 동 -> 남 -> 서

vector<Act> acts;
vector<Point> points;
vector<ll> xList;
vector<ll> yList;
bool isBody[2001][2001];

ll getX(int X)
{
    return lower_bound(xList.begin(), xList.end(), X) - xList.begin();
}

ll getY(int Y)
{
    return lower_bound(yList.begin(), yList.end(), Y) - yList.begin();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> N;
    for (size_t i = 0; i < N; i++)
    {
        ll sec;
        char dir;
        cin >> sec >> dir;
        acts.push_back(Act(sec, dir));
    }

    // First point
    points.push_back(Point(curX, curY));
    xList.push_back(curX);
    yList.push_back(curY);
    for (Act &now : acts)
    {
        curX += (now.first * xDir[curDir]);
        curY += (now.first * yDir[curDir]);

        switch (now.second)
        {
        case 'L':
            if (curDir != 0)
                curDir = (curDir - 1) % 4;
            else
                curDir = 3;
            break;

        case 'R':
            curDir = (curDir + 1) % 4;
            break;
        }

        points.push_back(Point(curX, curY));
        xList.push_back(curX);
        yList.push_back(curY);
    }

    // Last Point
    switch (curDir)
    {
    case 0: // 북
        points.push_back(Point(curX, L + 1));
        xList.push_back(curX);
        yList.push_back(L + 1);
        break;
    case 1: // 동
        points.push_back(Point(L + 1, curY));
        xList.push_back(L + 1);
        yList.push_back(curY);
        break;
    case 2: // 남
        points.push_back(Point(curX, (-L - 1)));
        xList.push_back(curX);
        yList.push_back(-L - 1);
        break;
    case 3: // 서
        points.push_back(Point((-L - 1), curY));
        xList.push_back(-L - 1);
        yList.push_back(curY);
        break;
    }

    // 좌표 압축
    sort(xList.begin(), xList.end());
    sort(yList.begin(), yList.end());
    xList.erase(unique(xList.begin(), xList.end()), xList.end());
    yList.erase(unique(yList.begin(), yList.end()), yList.end());

    // 실제 계산
    ll ans = 0;
    bool bodyConflict = false;
    isBody[getX(points[0].first)][getY(points[0].second)] = true;

    for (size_t i = 1; i < points.size(); i++)
    {
        Point &curP = points[i - 1];
        Point &nextP = points[i];

        // 경로 진행
        ll X = getX(curP.first);
        ll Y = getY(curP.second);
        ll newX = getX(nextP.first);
        ll newY = getY(nextP.second);

        // 중간 충돌 확인
        if (X > newX)
        {
            for (ll j = 1; j <= X - newX; j++)
            {
                if (isBody[X - j][Y])
                {
                    ans += abs(curP.first - xList[X - j]);
                    bodyConflict = true;
                    break;
                }

                isBody[X - j][Y] = true;
            }
        }
        else if (X < newX)
        {
            for (ll j = 1; j <= newX - X; j++)
            {
                if (isBody[X + j][Y])
                {
                    ans += abs(curP.first - xList[X + j]);
                    bodyConflict = true;
                    break;
                }

                isBody[X + j][Y] = true;
            }
        }
        else if (Y > newY)
        {
            for (ll j = 1; j <= Y - newY; j++)
            {
                if (isBody[X][Y - j])
                {
                    ans += abs(curP.second - yList[Y - j]);
                    bodyConflict = true;
                    break;
                }

                isBody[X][Y - j] = true;
            }
        }
        else if (Y < newY)
        {
            for (ll j = 1; j <= newY - Y; j++)
            {
                if (isBody[X][Y + j])
                {
                    ans += abs(curP.second - yList[Y + j]);
                    bodyConflict = true;
                    break;
                }

                isBody[X][Y + j] = true;
            }
        }

        if (bodyConflict)
            break;

        // X좌표 초과
        if (abs(nextP.first) > L)
        {
            ll endX = ((nextP.first > 0) ? L : -L);
            ans += abs(curP.first - endX) + 1;
            break;
        }

        // Y좌표 초과
        if (abs(nextP.second) > L)
        {
            ll endY = ((nextP.second > 0) ? L : -L);
            ans += abs(curP.second - endY) + 1;
            break;
        }

        // 오류 없음
        ans += acts[i - 1].first;
    }

    cout << ans;
}