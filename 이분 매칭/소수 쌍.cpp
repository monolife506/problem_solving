#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int num[50], matched[50];
bool is_prime[2001], visited[50];
vector<int> graph[50];

void is_prime_sieve(int max_n)
{
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= max_n; ++i)
    {
        if (!is_prime[i])
            continue;
        for (int j = i * i; j <= max_n; j += i)
            is_prime[j] = false;
    }
}

// used: 처음 숫자와 매칭된 숫자의 index
bool match(int cur, int used)
{
    if (visited[cur])
        return false;

    visited[cur] = true;
    for (int nxt : graph[cur])
    {
        if (nxt == used)
            continue;

        if (matched[nxt] == -1 || match(matched[nxt], used))
        {
            matched[nxt] = cur;
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    is_prime_sieve(2000);

    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; ++i)
        cin >> num[i];

    for (size_t i = 1; i < N; ++i)
    {
        if (num[i] % 2 == 1)
            continue;
        for (size_t j = 1; j < N; ++j)
        {
            if (num[j] % 2 == 0 || !is_prime[num[i] + num[j]])
                continue;
            graph[i].push_back(j);
        }
    }

    vector<int> ans;
    for (size_t used = 1; used < N; ++used)
    {
        if (num[0] % 2 == num[used] % 2 || !is_prime[num[0] + num[used]])
            continue;

        int match_cnt = 0;
        memset(matched, -1, sizeof(matched));
        for (size_t i = 1; i < N; ++i)
        {
            if (i == used || num[i] % 2 == 1)
                continue;

            memset(visited, false, sizeof(visited));
            match_cnt += match(i, used);
        }

        if (match_cnt * 2 == N - 2)
            ans.push_back(num[used]);
    }

    if (ans.size() == 0)
    {
        cout << -1;
    }
    else
    {
        sort(ans.begin(), ans.end());
        for (int num : ans)
            cout << num << " ";
    }

    cout << '\n';
}