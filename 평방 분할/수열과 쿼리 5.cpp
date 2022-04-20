#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int sqrt_N;

struct Query
{
    int idx, i, j;
    Query(int idx = -1, int i = 0, int j = 0) : idx(idx), i(i), j(j) {}

    bool operator<(const Query &rhs) const
    {
        if (i / sqrt_N != rhs.i / sqrt_N)
            return (i / sqrt_N < rhs.i / sqrt_N);
        else
            return j < rhs.j;
    }
};

size_t N, M;
int A[100001], cnt[1000001], result[100000];
Query query[100000];

void get_results() // mo's algorithm
{
    sqrt_N = sqrt(N);
    sort(query, query + M);

    int total_cnt = 0, i = query[0].i, j = query[0].j;
    for (size_t idx = i; idx <= j; ++idx)
    {
        if (cnt[A[idx]]++ == 0)
            ++total_cnt;
    }
    result[query[0].idx] = total_cnt;

    for (size_t idx = 1; idx < M; ++idx)
    {
        while (query[idx].i < i)
        {
            if (cnt[A[--i]]++ == 0)
                ++total_cnt;
        }
        while (query[idx].i > i)
        {
            if (--cnt[A[i++]] == 0)
                --total_cnt;
        }
        while (query[idx].j < j)
        {
            if (--cnt[A[j--]] == 0)
                --total_cnt;
        }
        while (query[idx].j > j)
        {
            if (cnt[A[++j]]++ == 0)
                ++total_cnt;
        }

        result[query[idx].idx] = total_cnt;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (size_t i = 1; i <= N; ++i)
        cin >> A[i];

    cin >> M;
    for (size_t i = 0; i < M; ++i)
    {
        query[i].idx = i;
        cin >> query[i].i >> query[i].j;
    }

    get_results();
    for (size_t i = 0; i < M; ++i)
        cout << result[i] << '\n';
}