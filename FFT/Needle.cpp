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

    int nu;
    cin >> nu;

    vector<complex<double>> f(60001, {0, 0});
    for (int i = 0; i < nu; ++i)
    {
        int x;
        cin >> x;
        f[x + 30000] = {1, 0};
    }

    int nm;
    cin >> nm;

    vector<bool> flag(120001, false);
    for (int i = 0; i < nm; ++i)
    {
        int x;
        cin >> x;
        flag[(x + 30000) * 2] = true;
    }

    int nl;
    cin >> nl;

    vector<complex<double>> g(60001, {0, 0});
    for (int i = 0; i < nl; ++i)
    {
        int x;
        cin >> x;
        g[x + 30000] = {1, 0};
    }

    vector<complex<double>> h = convolution(f, g);

    ll ans = 0;
    for (int i = 0; i <= 120000; i += 2)
    {
        if (i >= h.size())
            break;

        ans += (ll)round(h[i].real()) * flag[i];
    }

    cout << ans << '\n';
}

/*

0 0 0 1
0 0 1 0
0 1 0 0

k - d
k
k + d

*/