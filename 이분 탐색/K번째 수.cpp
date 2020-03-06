// 1300번: K번째 수

#include <iostream>
using namespace std;
typedef unsigned long long ll;

ll getcnt(ll num, ll N)
{
    ll cnt = 0;
    for (size_t i = 1; i <= N; i++)
    {
        ll tmp = num / i;
        cnt += (tmp > N) ? N : tmp;
    }
    return cnt;
}

// 처음으로 target개의 숫자보다 같거나 커지는 수 구하기
ll search(ll left, ll right, ll target, ll N)
{
    ll middle = (left + right) / 2;
    ll cur = getcnt(middle, N);

    if (cur < target)
        return search(middle + 1, right, target, N);
    else
    {
        if (getcnt(middle - 1, N) >= target)
            return search(left, middle - 1, target, N);
        else
            return middle;
    }
}

int main()
{
    ll N, K;
    cin >> N >> K;
    cout << search(1, N * N, K, N);
}

// N == 3
// 1 2 3
// 2 4 6
// 3 6 9
// => 1 2 2 3 3 4 6 6 9
// => 1 3 3 5 5 6 8 8 9

// N == 4
// 1  2  3  4
// 2  4  6  8
// 3  6  9  12
// 4  8  12 16
// => 1 2 2 3 3 4 4 4 6 6 8 8 9 12 12 16

// N == 5
// 1  2  3  4  5
// 2  4  6  8  10
// 3  6  9  12 15
// 4  8  12 16 20
// 5  10 15 20 25
// => 1 2 2 3 3 4 4 4 5 5 6 6 8 8 9 10 10 12 12 15 15 16 20 20 25
