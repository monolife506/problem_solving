#include <iostream>
using namespace std;

int N, M, X;
int place[100000];

bool check(int H)
{
    if (M == 1)
        return (place[0] - H <= 0 && place[0] + H >= N);

    for (size_t i = 0; i < M; i++)
    {
        if (i == 0)
        {
            if (place[i] - H > 0 || place[i] + H < place[i + 1] - H)
                return false;
        }
        else if (i == M - 1)
        {
            if (place[i] - H > place[i - 1] + H || place[i] + H < N)
                return false;
        }
        else
        {
            if (place[i] - H > place[i - 1] + H || place[i] + H < place[i + 1] - H)
                return false;
        }
    }

    return true;
}

int binary_search()
{
    int left = 1;
    int right = 100000;
    int ans, middle;

    while (left <= right)
    {
        middle = (left + right) / 2;
        if (check(middle))
        {
            ans = middle;
            if (ans == 1)
                break;
            right = middle - 1;
        }
        else
            left = middle + 1;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        cin >> X;
        place[i] = X;
    }

    cout << binary_search();
}