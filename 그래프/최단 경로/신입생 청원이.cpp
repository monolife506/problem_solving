#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
typedef pair<int, int> P;

const int INF = 987654321;

int N, M;
unordered_map<string, int> idx;
P lecture_t[500];
vector<P> graph[500];

int stoi_t(const string &s)
{
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

string itos_t(int t)
{
    ostringstream os;
    os << setfill('0') << setw(2) << t / 60;
    os << ":";
    os << setfill('0') << setw(2) << t % 60;
    return os.str();
}

int dijkstra(int start, int start_t, int end_t)
{
    priority_queue<pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>>> pq;
    vector<vector<int>> dist(500, vector<int>(1440, INF));
    pq.push({dist[start][start_t] = 0, {start, start_t}});

    while (!pq.empty())
    {
        int cur = pq.top().second.first;
        int t = pq.top().second.second;
        int d = pq.top().first;
        pq.pop();

        if (dist[cur][t] < d)
            continue;

        // 현재 강의실에 1분간 있기
        bool in_lecture = (t >= lecture_t[cur].first && t < lecture_t[cur].second);
        if (t < end_t && dist[cur][t + 1] > dist[cur][t] + !in_lecture)
        {
            dist[cur][t + 1] = dist[cur][t] + !in_lecture;
            pq.push({dist[cur][t + 1], {cur, t + 1}});
        }

        // 다른 강의실로 이동하기
        for (P &p : graph[cur])
        {
            int &nxt = p.first;
            int &w = p.second;
            if (t + w <= end_t && dist[nxt][t + w] > dist[cur][t] + w)
            {
                dist[nxt][t + w] = dist[cur][t] + w;
                pq.push({dist[nxt][t + w], {nxt, t + w}});
            }
        }
    }

    int min_d = INF;
    for (int i = 0; i < N; ++i)
        min_d = min(min_d, dist[i][end_t]);

    return (end_t - start_t) - min_d;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    int start, start_t = INF, end_t = 0;
    string start_name;
    for (int i = 0; i < N; ++i)
    {
        string name, lecture_begin, lecture_end;
        cin >> name >> lecture_begin >> lecture_end;

        int st = stoi_t(lecture_begin);
        int et = stoi_t(lecture_end);
        idx[name] = i;
        lecture_t[i] = {st, et};

        if (start_t > st || (start_t == st && start_name > name))
        {
            start = i;
            start_t = st;
            start_name = name;
        }
        if (end_t < et)
        {
            end_t = et;
        }
    }
    for (int i = 0; i < M; ++i)
    {
        string u_name, v_name, t;
        cin >> u_name >> v_name >> t;

        int u = idx[u_name];
        int v = idx[v_name];
        graph[u].push_back({v, stoi_t(t)});
        graph[v].push_back({u, stoi_t(t)});
    }

    cout << itos_t(dijkstra(start, start_t, end_t)) << '\n';
}