#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    if (N == 0)
    {
        cout << 0 << '\n';
    }
    else
    {
        bool sign = (N > 0);
        N = abs(N);

        vector<int> v;
        while (N > 0)
        {
            v.push_back(N % 3);
            N /= 3;
        }

        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i] == 2 || v[i] == 3)
            {
                if (i != v.size() - 1)
                    v[i + 1] += 1;
                else
                    v.push_back(1);

                v[i] = (v[i] == 2) ? -1 : 0;
            }
        }

        for (int i = v.size() - 1; i >= 0; --i)
        {
            if (v[i] == -1)
                cout << (sign ? 'T' : '1');
            else if (v[i] == 0)
                cout << '0';
            else
                cout << (sign ? '1' : 'T');
        }

        cout << '\n';
    }
}

/*

10 -> 101
5 -> 12 -> 10 + 2 -> 010 + 01T
8 -> 22 -> 3T -> 2TT -> 1TTT

*/