// 1202번: 보석 도둑

#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef unsigned long long ll;

struct J
{
    int M;
    int V;

    J(int m, int v) : M(m), V(v) {};
};
struct cmp
{
    bool operator()(J A, J B)
    {
        if (A.V != B.V)
            return A.V < B.V;
        else 
            return A.M < B.M;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    priority_queue<J, vector<J>, cmp> pq;
    multiset<int> S;

    for (int i = 0; i < N; i++)
    {
        int M, V;
        cin >> M >> V;
        pq.push(J(M, V));
    }
        
    for (int i = 0; i < K; i++)
    {
        int C;
        cin >> C;
        S.insert(C);
    }
        
    ll total = 0;
    while (!pq.empty() && !S.empty())
    {
        J jewel = pq.top();
        pq.pop();
        
        auto it = S.lower_bound(jewel.M);
        if (it != S.end())
        {
            total += jewel.V;
            S.erase(it);
        }
    }
    cout << total << '\n';
}