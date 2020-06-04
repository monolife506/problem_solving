// 1992번: 쿼드트리

#include <iostream>
#include <array>
#include <string>
using namespace std;

string ans;
array<string, 64> map;

void quadtree(int N, int X, int Y)
{
    for (size_t i = Y; i < Y + N; i++)
    {
        for (size_t j = X; j < X + N; j++)
        {
            if (map[Y][X] != map[i][j])
            {
                ans.push_back('(');
                quadtree(N / 2, X, Y);
                quadtree(N / 2, (2 * X + N) / 2, Y);
                quadtree(N / 2, X, (2 * Y + N) / 2);
                quadtree(N / 2, (2 * X + N) / 2, (2 * Y + N) / 2);
                ans.push_back(')');
                return;
            }
        }
    }
    ans.push_back(map[Y][X]);
}

int main()
{
    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> map[i];
    quadtree(N, 0, 0);
    cout << ans;
}