#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, char> users;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, P, W, L, G;
    cin >> N >> P >> W >> L >> G;

    string username;
    char flag;
    for (size_t i = 0; i < P; i++)
    {
        cin >> username >> flag;
        users[username] = flag;
    }

    int totalscore = 0;
    bool ans = false;
    for (size_t i = 0; i < N; i++)
    {
        cin >> username;
        if (users.find(username) == users.end())
        {
            totalscore = max(totalscore - L, 0);
            continue;
        }

        flag = users[username];
        if (flag == 'W')
        {
            totalscore += W;
            if (totalscore >= G)
                ans = true;
        }
        else
            totalscore = max(totalscore - L, 0);
    }

    if (ans)
        cout << "I AM NOT IRONMAN!!";
    else
        cout << "I AM IRONMAN!!";
}