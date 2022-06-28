#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

bool is_prime[2501];

void get_prime(int l, int r, vector<int> &v)
{
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= r; ++i)
    {
        if (!is_prime[i])
            continue;
        for (int j = i * i; j <= r; j += i)
            is_prime[j] = false;
    }
    for (int i = l; i <= r; ++i)
    {
        if (is_prime[i])
            v.push_back(i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int K, N;
    cin >> K >> N;

    vector<int> prime;
    get_prime(2000, 2500, prime);
    for (int i = 0; i < K; ++i)
    {
        for (int j = 1; j <= N; ++j)
            cout << j * prime[i] << " ";
        cout << '\n';
    }
}

/*

a 2a 3a ... Na -> a 2a 3a ... (N - 1)a
b 2b 3b ... Nb -> b 2b 3b ... (N - 1)b

*/