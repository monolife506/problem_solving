#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> meeting;
bool infected[100001], last_infected[100001], first_infected[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, M;
    cin >> N >> M;
    for (size_t i = 0; i < M; ++i)
    {
        size_t k;
        cin >> k;

        vector<int> a(k);
        for (size_t j = 0; j < k; ++j)
            cin >> a[j];

        meeting.push_back(a);
    }
    for (size_t i = 1; i <= N; ++i)
    {
        cin >> last_infected[i];
        infected[i] = last_infected[i];
    }

    bool ans = true;
    int meeting_size = meeting.size();
    for (int i = meeting_size - 1; i >= 0; --i)
    {
        vector<int> &a = meeting[i];
        size_t a_size = a.size();

        bool infected_flag = false;
        bool not_infected_flag = false;
        for (size_t j = 0; j < a_size; ++j)
        {
            if (infected[a[j]])
                infected_flag = true;
            else
                not_infected_flag = true;
        }

        if (infected_flag && not_infected_flag)
            for (size_t j = 0; j < a_size; ++j)
                infected[a[j]] = false;
    }
    for (size_t i = 1; i <= N; ++i)
    {
        first_infected[i] = infected[i];
    }
    for (int i = 0; i < meeting_size; ++i)
    {
        vector<int> &a = meeting[i];
        size_t a_size = a.size();

        bool infected_flag = false;
        for (size_t j = 0; j < a_size; ++j)
            if (infected[a[j]])
                infected_flag = true;

        if (infected_flag)
            for (size_t j = 0; j < a_size; ++j)
                infected[a[j]] = true;
    }
    for (size_t i = 1; i <= N; ++i)
    {
        if (infected[i] != last_infected[i])
        {
            ans = false;
            break;
        }
    }

    cout << (ans ? "YES" : "NO") << '\n';
    if (ans)
    {
        for (size_t i = 1; i <= N; ++i)
            cout << first_infected[i] << " ";
        cout << '\n';
    }
}