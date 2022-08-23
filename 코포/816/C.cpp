#include <iostream>
using namespace std;
typedef long long ll;

int a[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    ll sum = 1;
    ll tmp = 1;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] != a[i - 1])
            ++tmp;

        sum += tmp;
    }

    tmp = sum;
    for (int i = 1; i < n; ++i)
    {
        tmp -= 1;
        if (a[i] != a[i - 1])
            tmp -= (n - i);
        sum += tmp;
    }

    for (int q = 0; q < m; ++q)
    {
        int i, x;
        cin >> i >> x;

        --i;

        if (i + 1 < n)
        {
            if (a[i] == a[i + 1])
            {
                if (x != a[i + 1])
                    sum += 1LL * (n - (i + 1)) * (i + 1);
            }
            else
            {
                if (x == a[i + 1])
                    sum -= 1LL * (n - (i + 1)) * (i + 1);
            }
        }

        if (i - 1 >= 0)
        {
            if (a[i] == a[i - 1])
            {
                if (x != a[i - 1])
                    sum += 1LL * (n - i) * i;
            }
            else
            {
                if (x == a[i - 1])
                    sum -= 1LL * (n - i) * i;
            }
        }

        a[i] = x;

        cout << sum << '\n';
    }
}

/*

1 2 3 5 5 6
1 2 3 4 4 5
  1 2 3 3 4
    1 2 2 3
      1 1 2
        1 2
          1

i == 3
- (n - (i + 1)) * (i + 1)

1 2 3 4 4 5
1 2 3 4 4 5
  1 2 3 3 4
    1 2 2 3
      1 1 2
        1 2
          1

i == 4
- (n - i) * i

1 2 3
1 2 3
  1 2
    1

i == 2
- (n - i) * i

1 2 2
1 2 2
  1 1
    1

*/