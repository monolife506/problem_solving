#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool is_prime[1000001];

void sieve()
{
    fill_n(&is_prime[0], 1000001, true);
    for (ll i = 4; i <= 1000000; i += 2)
        is_prime[i] = false;
    for (ll i = 3; i <= 1000000; i += 2)
    {
        if (!is_prime[i])
            continue;
        for (ll j = i * i; j <= 1000000; j += i * 2)
            is_prime[j] = false;
    }
}

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

    sieve();

    vector<complex<double>> f(1000001, {0, 0});
    for (int i = 2; i <= 500000; ++i)
    {
        if (is_prime[i])
            f[i * 2] = {1, 0};
    }

    vector<complex<double>> g(1000001, {0, 0});
    for (int i = 3; i <= 1000000; ++i)
    {
        if (is_prime[i])
            g[i] = {1, 0};
    }

    vector<complex<double>> h = convolution(f, g);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; ++tc)
    {
        int N;
        cin >> N;
        cout << (ll)round(h[N].real()) << '\n';
    }
}

/*


*/