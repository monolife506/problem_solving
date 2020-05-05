// 13975번: 파일 합치기 3
// 허프만 부호화
// https://ko.wikipedia.org/wiki/%ED%97%88%ED%94%84%EB%A7%8C_%EB%B6%80%ED%98%B8%ED%99%94

#include <iostream>
#include <queue>
using namespace std;
typedef unsigned long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    size_t T;
    cin >> T;

    size_t K;
    ll tmp;
    ll tmp_sum;
    ll total;
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (size_t tc = 0; tc < T; tc++)
    {
        cin >> K;
        for (size_t i = 0; i < K; i++)
        {
            cin >> tmp;
            pq.push(tmp);
        }

        total = 0;
        for (size_t i = 0; i < K - 1; i++)
        {
            tmp_sum = 0;
            for (size_t j = 0; j < 2; j++)
            {
                tmp = pq.top();
                tmp_sum += tmp;
                pq.pop();
            }
            pq.push(tmp_sum);
            total += tmp_sum;
        }

        pq.pop();
        cout << total << '\n';
    }
}
