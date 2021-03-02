#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int bfs(int h, int w, int key, int cnt, vector<vector<char>>& arr, vector<P>& entrance)
{
    static int dx[4] = { 1, -1, 0, 0 };
    static int dy[4] = { 0, 0, 1, -1 };

    queue<P> Q;
    Q.push(P(-1, -1));

    bool visited[27][101][101];
    bool visited_external[27];
    memset(visited, false, sizeof(visited));
    memset(visited_external, false, sizeof(visited_external));
    visited_external[cnt] = true;

    int ans = 0;
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        // 건물 바깥
        if (x < 0 || x >= h || y < 0 || y >= w) {
            for (P& p : entrance) {
                int nextX = p.first;
                int nextY = p.second;

                if (visited[cnt][nextX][nextY]) {
                    continue;
                } else if (arr[nextX][nextY] >= 'A' && arr[nextX][nextY] <= 'Z') {
                    if (key & (1 << (arr[nextX][nextY] - 'A'))) {
                        visited[cnt][nextX][nextY] = true;
                        Q.push(P(nextX, nextY));
                    }
                } else if (arr[nextX][nextY] != '*') {
                    visited[cnt][nextX][nextY] = true;
                    Q.push(P(nextX, nextY));
                }
            }
            continue;
        }

        // 건물 안
        if (arr[x][y] == '$') {
            ans++;
        } else if (arr[x][y] >= 'a' && arr[x][y] <= 'z') {
            if (!(key & (1 << (arr[x][y] - 'a')))) {
                key |= (1 << (arr[x][y] - 'a'));
                visited[++cnt][x][y] = true;
            }
        }

        arr[x][y] = '.';
        for (size_t i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (nextX < 0 || nextX >= h || nextY < 0 || nextY >= w) {
                if (!visited_external[cnt]) {
                    visited_external[cnt] = true;
                    Q.push(P(nextX, nextY));
                }
            } else if (visited[cnt][nextX][nextY]) {
                continue;
            } else if (arr[nextX][nextY] >= 'A' && arr[nextX][nextY] <= 'Z') {
                if (key & (1 << (arr[nextX][nextY] - 'A'))) {
                    visited[cnt][nextX][nextY] = true;
                    Q.push(P(nextX, nextY));
                }
            } else if (arr[nextX][nextY] != '*') {
                visited[cnt][nextX][nextY] = true;
                Q.push(P(nextX, nextY));
            }
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    size_t T;
    cin >> T;

    for (size_t tc = 0; tc < T; tc++) {
        int h, w, start = 0, cnt = 0;
        cin >> h >> w;

        vector<vector<char>> arr(h, vector<char>(w));
        vector<P> entrance;
        for (size_t i = 0; i < h; i++) {
            string str;
            cin >> str;
            for (size_t j = 0; j < w; j++) {
                arr[i][j] = str[j];
                if (arr[i][j] != '*' && (i == 0 || i == h - 1 || j == 0 || j == w - 1))
                    entrance.push_back(P(i, j));
            }
        }

        string key_str;
        cin >> key_str;
        for (const char& c : key_str) {
            cnt++;
            start |= (1 << (c - 'a'));
        }

        cout << bfs(h, w, start, cnt, arr, entrance) << '\n';
    }
}