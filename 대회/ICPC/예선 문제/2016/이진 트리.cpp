#include <iostream>
#include <cmath>
using namespace std;

int k, treesize;
int tree[2097152]; // 2^21
int maxw[2097152];

int setmaxw(int cur)
{
    if ()
    {
        maxw[cur] = tree[cur];
        return maxw[cur];
    }

    int left = setmaxw(cur * 2);
    int right = setmaxw(cur * 2 + 1);
    maxw[cur] = max(left, right) + tree[cur];

    return maxw[cur];
}

void addw(int cur)
{
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    treesize = pow(2, k + 1);
    for (size_t i = 2; i < treesize; i++)
        cin >> tree[i];
}

// 최댓값 얻기
//