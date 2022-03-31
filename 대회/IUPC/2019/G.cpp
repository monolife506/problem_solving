#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char buffer1[101], buffer2[101];

int main()
{
    int cnt[26] = {3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
    int N, M;

    vector<int> arr;
    queue<int> name1, name2;

    cin >> N >> M;
    cin >> buffer1 >> buffer2;
    for (size_t i = 0; i < N; i++)
        name1.push(cnt[buffer1[i] - 'A']);
    for (size_t i = 0; i < M; i++)
        name2.push(cnt[buffer2[i] - 'A']);

    while (!name1.empty() || !name2.empty())
    {
        if (!name1.empty())
        {
            arr.push_back(name1.front());
            name1.pop();
        }
        if (!name2.empty())
        {
            arr.push_back(name2.front());
            name2.pop();
        }
    }

    int vecSize;
    for (size_t i = 0; i < N + M - 2; i++)
    {
        vecSize = arr.size();
        for (size_t j = 0; j < vecSize - 1; j++)
            arr[j] = (arr[j] + arr[j + 1]) % 10;
        arr.pop_back();
    }
    cout << arr[0] * 10 + arr[1] << '%';
}