// 17144번: 미세먼지 안녕!

#include <iostream>
#include <queue>
using namespace std;

struct Dust {
    int r;
    int c;
    int dust;

    Dust(int _r, int _c, int _dust)
        : r(_r)
        , c(_c)
        , dust(_dust)
    {
    }
};

int R, C, T;
int map[50][50];
int cleanerUpR, cleanerUpC = -1;
int cleanerDownR, cleanerDownC;

int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

void spread()
{
    queue<Dust> Q;
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            if (map[i][j] >= 5)
                Q.push(Dust(i, j, map[i][j]));
        }
    }

    while (!Q.empty()) {
        Dust cur = Q.front();
        Q.pop();
        int spreadCnt = 0;
        for (size_t i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];
            if (r < 0 || r >= R || c < 0 || c >= C || map[r][c] == -1)
                continue;

            map[r][c] += (cur.dust / 5);
            spreadCnt++;
        }
        map[cur.r][cur.c] -= ((cur.dust / 5) * spreadCnt);
    }
}

void moving()
{
    // 위쪽 공기청정기
    int r = cleanerUpR - 1, c = cleanerUpC;
    while (r > 0) {
        map[r][c] = map[r - 1][c];
        r--;
    }
    while (c < C - 1) {
        map[r][c] = map[r][c + 1];
        c++;
    }
    while (r < cleanerUpR) {
        map[r][c] = map[r + 1][c];
        r++;
    }
    while (c > 0) {
        map[r][c] = map[r][c - 1];
        c--;
    }
    map[r][1] = 0;

    // 아래쪽 공기청정기
    r = cleanerDownR + 1, c = cleanerDownC;
    while (r < R - 1) {
        map[r][c] = map[r + 1][c];
        r++;
    }
    while (c < C - 1) {
        map[r][c] = map[r][c + 1];
        c++;
    }
    while (r > cleanerDownR) {
        map[r][c] = map[r - 1][c];
        r--;
    }
    while (c > 0) {
        map[r][c] = map[r][c - 1];
        c--;
    }
    map[r][1] = 0;
}

int main()
{
    cin >> R >> C >> T;
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == -1) {
                if (cleanerUpC == -1) {
                    cleanerUpR = i;
                    cleanerUpC = j;
                } else {
                    cleanerDownR = i;
                    cleanerDownC = j;
                }
            }
        }
    }

    for (size_t sec = 0; sec < T; sec++) {
        spread(); // 미세먼지 확산
        moving(); // 공기청정기 작동
    }

    int ans = 0;
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            if (map[i][j] != -1)
                ans += map[i][j];
        }
    }
    cout << ans;
}