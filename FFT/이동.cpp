#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int X[60000], Y[60000];

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

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> X[i];
    for (int i = 0; i < N; ++i)
        cin >> Y[i];

    vector<complex<double>> f(N * 2);
    for (int i = 0; i < N; ++i)
        f[i + N] = f[i] = {X[i], 0};

    vector<complex<double>> g(N);
    for (int i = 0; i < N; ++i)
        g[i] = {Y[(N - 1) - i], 0};

    vector<complex<double>> h = convolution(f, g);

    double ans = -1;
    for (int i = N - 1; i < 2 * N - 1; ++i)
        ans = max(ans, h[i].real());

    cout << (ll)round(ans) << '\n';
}

/*

N = 4

1 2 3 4 1 2 3 4
5 8 7 6 0 0 0 0


N = 5
1 2 3 4 5
5 4 3 2 1

*/