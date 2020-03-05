// 1654번: 랜선 자르기

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll getSum(const vector<ll> &v, int L)
{
    ll val = 0;
    for (const ll item : v)
        val += (item / L);
    return val;
}

// 만들 수 있는 랜선의 개수가 N개 이상인 최대 길이 찾기
// 검색 범위: 1 ~ (K개의 랜선중 최대 길이)
int search(const vector<ll> &v, ll left, ll right, size_t N)
{
    int middle = (left + right) / 2;
    ll cnt = getSum(v, middle);

    if (cnt < N)
        return search(v, left, middle - 1, N);
    else
    {
        if (getSum(v, middle + 1) < N)
            return middle;
        else
            return search(v, middle + 1, right, N);
    }
}

int main()
{
    size_t K, N;
    cin >> K >> N;
    vector<ll> cable(K);
    int max_cable = 0;
    for (ll &item : cable)
    {
        cin >> item;
        if (item > max_cable)
            max_cable = item;
    }
    cout << search(cable, 1, max_cable, N);
}
