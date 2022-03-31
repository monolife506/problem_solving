// 6549번: 히스토그램에서 가장 큰 직사각형
// 스택을 이용한 풀이

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;

int main()
{
    size_t N;
    cin >> N;
    while (N != 0)
    {
        vector<ll> H(N);
        for (size_t i = 0; i < N; i++)
            cin >> H[i];

        stack<ll> S;
        ll max_area = 0;
        for (size_t i = 0; i < N; i++)
        {
            if (!S.empty())
            {
                while (H[S.top()] > H[i])
                {
                    ll top = S.top();
                    S.pop();
                    int start = (S.empty()) ? 0 : S.top() + 1;
                    max_area = max(max_area, (i - start) * H[top]);
                    if (S.empty())
                        break;
                }
            }
            S.push(i);
        }
        while (!S.empty())
        {
            ll top = S.top();
            S.pop();
            if (!S.empty())
                max_area = max(max_area, (N - (S.top() + 1)) * H[top]);
            else
                max_area = max(max_area, N * H[top]);
        }
        cout << max_area << '\n';
        cin >> N;
    }
}
