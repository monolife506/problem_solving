#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;
const int MAX_NUM = 100000;

struct Query
{
    int idx, l, r;
    Query(int idx = 0, int l = 0, int r = 0) : idx(idx), l(l), r(r) {}
};

size_t N, M;
int A[MAX_N + 1];
Query query[MAX_M];

int max_cnt, num_cnt[MAX_NUM + 1], count_cnt[MAX_NUM + 1], result[MAX_M];

void insert_num(int num)
{
    ++count_cnt[num_cnt[num] + 1];
    --count_cnt[num_cnt[num]];
    max_cnt = max(max_cnt, num_cnt[num] + 1);

    ++num_cnt[num];
}

void delete_num(int num)
{
    ++count_cnt[num_cnt[num] - 1];
    --count_cnt[num_cnt[num]];
    if (num_cnt[num] == max_cnt && count_cnt[num_cnt[num]] == 0)
        max_cnt = num_cnt[num] - 1;

    --num_cnt[num];
}

void get_result()
{
    int sqrt_N = sqrt(N);
    sort(query, query + M,
         [sqrt_N](Query &lhs, Query &rhs) -> bool
         {
             if (lhs.l / sqrt_N != rhs.l / sqrt_N)
                 return lhs.l / sqrt_N < rhs.l / sqrt_N;
             else
                 return lhs.r < rhs.r;
         });

    int l = query[0].l, r = query[0].r;
    for (size_t i = l; i <= r; ++i)
        insert_num(A[i]);

    result[query[0].idx] = max_cnt;
    for (size_t i = 1; i < M; ++i)
    {
        while (l < query[i].l)
            delete_num(A[l++]);
        while (l > query[i].l)
            insert_num(A[--l]);
        while (r < query[i].r)
            insert_num(A[++r]);
        while (r > query[i].r)
            delete_num(A[r--]);

        result[query[i].idx] = max_cnt;
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
        cin >> query[i].l >> query[i].r;
        query[i].idx = i;
    }

    get_result();
    for (size_t i = 0; i < M; ++i)
        cout << result[i] << '\n';
}