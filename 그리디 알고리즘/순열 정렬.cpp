#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc)
    {
        int N;
        cin >> N;

        bool flag = true;

        int max_num;
        cin >> max_num;
        max_num = min(max_num, N - max_num + 1);
        for (int i = 2; i <= N; ++i)
        {
            int num;
            cin >> num;

            if (max_num <= num && max_num <= N - num + 1)
                max_num = min(num, N - num + 1);
            else if (max_num <= num)
                max_num = num;
            else if (max_num <= N - num + 1)
                max_num = N - num + 1;
            else
                flag = false;
        }

        cout << (flag ? "YES" : "NO") << '\n';
    }
}

/*

2 3 1

*/