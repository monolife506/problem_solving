// 1016번: 제곱 ㄴㄴ 수

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
typedef unsigned long long ll;

bool arr[10000001];

int main()
{
    ll minNum, maxNum;
    cin >> minNum >> maxNum;
    memset(arr, 0, sizeof(arr));

    for (size_t i = 2; i * i <= maxNum; i++)
    {
        ll startNum = minNum / (i * i);
        if (startNum * i * i != minNum)
            startNum++;

        for (size_t j = startNum * i * i; j <= maxNum; j += (i * i))
        {
            if (j >= minNum)
                arr[j - minNum] = true;
        }
    }

    ll cnt = 0;
    for (size_t i = 0; i < maxNum - minNum + 1; i++)
    {
        if (!arr[i])
            cnt++;
    }

    cout << cnt;
}

// 1 2 3 5 6 7 10
