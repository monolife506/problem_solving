#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, R = 0, G = 0, B = 0;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;
    }
    for (int i = 0; i < M; ++i)
    {
        int v, w;
        char c;
        cin >> v >> w >> c;
        if (c == 'R')
            ++R;
        else if (c == 'G')
            ++G;
        else // c == 'B'
            ++B;
    }

    if (G % 2 == 0)
    {
        cout << (R > B ? "jhnah917" : "jhnan917") << '\n';
    }
    else // G % 2 == 1
    {
        cout << (R >= B ? "jhnah917" : "jhnan917") << '\n';
    }
}

/*

R B G G G
G G G B R

G G G G R B R B


G B

*/