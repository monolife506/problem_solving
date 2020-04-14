#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

// 외판원이 이동할때 드는 비용
array<array<int, 10>, 10> W;

int main()
{
    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
            cin >> W[i][j];
    }

    vector<int> order(N);
    for (size_t i = 0; i < N; i++)
        order[i] = i;

    int cur_val;
    int min_val = 1'000'000 * 10;

    do
    {
        cur_val = 0;
        for (size_t i = 0; i < N - 1; i++)
        {
            cur_val += W[order[i]][order[i + 1]];

            // 도시를 이동할 방법이 없는 경우
            if (W[order[i]][order[i + 1]] == 0)
                break;

            // 마지막으로 시작점 도시로 돌아가는 경우
            if (i == N - 2)
            {
                cur_val += W[order[i + 1]][order[0]];
                if (W[order[i + 1]][order[0]] == 0)
                    break;
                else if (cur_val < min_val)
                    min_val = cur_val;
            }
        }

    } while (next_permutation(order.begin(), order.end()));

    cout << min_val;
}