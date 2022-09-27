#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

int a[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    ll sum = accumulate(a, a + N, 0LL);
    ll max_val = *max_element(a, a + N);

    cout << (sum - max_val >= max_val - 1 ? sum : (sum - max_val) * 2 + 1) << '\n';
}

/*

5 1 1 1
O | O | O | O | O

5 5 5 5
O | O | O | O | O |

*/