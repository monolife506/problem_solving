#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const double pi = acos(-1);

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
    // find n
    int n = 2;
    while (f.size() + g.size() >= n)
        n *= 2;

    f.resize(n);
    g.resize(n);

    // n-th root of unity -> w^n = 1
    complex<double> x1(cos(2 * pi / n), sin(2 * pi / n));

    // DFT
    FFT(f, x1);
    FFT(g, x1);

    // fg = h
    vector<complex<double>> h(n);
    for (int i = 0; i < n; ++i)
        h[i] = f[i] * g[i];

    // x1의 켤레 복소수
    complex<double> x1_bar(x1.real(), -x1.imag());

    // IDFT
    FFT(h, x1_bar);
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

    vector<bool> flag(200001, false);
    for (int i = 0; i < N; ++i)
    {
        int k;
        cin >> k;
        flag[k] = true;
    }

    vector<complex<double>> f(200001, {0, 0});
    for (int i = 1; i <= 200000; ++i)
    {
        if (flag[i])
            f[i] = {1, 0};
    }

    vector<complex<double>> g = f;
    vector<complex<double>> h = convolution(f, g);
    for (int i = 1; i <= 200000; ++i)
    {
        if (abs(round(h[i].real())) > 0)
            flag[i] = true;
    }

    int M;
    cin >> M;

    int ans = 0;
    for (int i = 0; i < M; ++i)
    {
        int d;
        cin >> d;
        if (flag[d])
            ans++;
    }

    cout << ans << '\n';
}