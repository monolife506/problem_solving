#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void FFT(vector<complex<double>> &f, complex<double> w)
{
    if (f.size() == 1)
        return;

    int n = f.size();
    vector<complex<double>> even(n / 2), odd(n / 2);
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
            even[i / 2] = f[i];
        else
            odd[i / 2] = f[i];
    }

    FFT(even, w * w);
    FFT(odd, w * w);

    complex<double> x(1, 0);
    for (int i = 0; i < n / 2; ++i)
    {
        f[i] = even[i] + x * odd[i];
        f[i + n / 2] = even[i] - x * odd[i];
        x *= w;
    }
}

vector<complex<double>> convolution(vector<complex<double>> &f, vector<complex<double>> &g)
{
    int n = 2;
    while (f.size() + g.size() >= n)
        n *= 2;

    f.resize(n);
    g.resize(n);

    complex<double> x1(cos(2 * numbers::pi / n), sin(2 * numbers::pi / n));
    FFT(f, x1);
    FFT(g, x1);

    vector<complex<double>> h(n);
    for (int i = 0; i < n; ++i)
        h[i] = f[i] * g[i];

    FFT(h, complex<double>(x1.real(), -x1.imag()));
    for (int i = 0; i < n; ++i)
        h[i] /= complex<double>(n, 0);

    return h;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a, b;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<complex<double>> f(a.length());
    for (int i = 0; i < a.length(); ++i)
        f[i] = {(double)(a[i] - '0'), 0};

    vector<complex<double>> g(b.length());
    for (int i = 0; i < b.length(); ++i)
        g[i] = {(double)(b[i] - '0'), 0};

    vector<complex<double>> h = convolution(f, g);

    vector<ll> ans(h.size());
    for (int i = 0; i < h.size(); ++i)
        ans[i] = (ll)round(h[i].real());
    for (int i = 0; i < h.size(); ++i)
    {
        if (ans[i] >= 10)
        {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }

    bool leading_zero = true;
    for (int i = h.size() - 1; i >= 0; --i)
    {
        if (ans[i] != 0)
            leading_zero = false;
        if (!leading_zero)
            cout << ans[i];
    }

    if (leading_zero)
        cout << 0;

    cout << '\n';
}

/*

9 9
9 9

81
170
1

*/