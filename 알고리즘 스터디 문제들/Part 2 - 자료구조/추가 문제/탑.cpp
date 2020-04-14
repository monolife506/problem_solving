#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    size_t N;
    cin >> N;

    vector<int> H(N); // 탑들의 높이 / 신호를 수신한 탑의 번호
    for (size_t i = 0; i < N; i++)
        cin >> H[i];

    // 현재 전송중인 레이저 신호의 발생지(first)와, 높이(second)를 담는 스택
    stack<pair<int, int>> S;
    for (int i = N - 1; i >= 0; i--)
    {
        while (!S.empty() && S.top().second <= H[i])
        {
            H[S.top().first] = i + 1;
            S.pop();
        }
        S.push({i, H[i]});
    }

    while (!S.empty())
    {
        H[S.top().first] = 0;
        S.pop();
    }

    for (size_t i = 0; i < N; i++)
        cout << H[i] << " ";
}
