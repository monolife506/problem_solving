// 2630번: 색종이 만들기

#include <iostream>
#include <array>
using namespace std;

int blue = 0;
int white = 0;
array<array<bool, 128>, 128> paper;

void quadtree(int startX, int startY, int endX, int endY)
{
    bool first = paper[startX][startY];
    bool flag = false;
    for (size_t i = startX; i < endX; i++)
    {
        for (size_t j = startY; j < endY; j++)
        {
            if (first != paper[i][j])
            {
                flag = true;
                break;
            }
        }

        if (flag)
            break;
    }

    if (flag)
    {
        quadtree(startX, startY, (startX + endX) / 2, (startY + endY) / 2);
        quadtree((startX + endX) / 2, startY, endX, (startY + endY) / 2);
        quadtree(startX, (startY + endY) / 2, (startX + endX) / 2, endY);
        quadtree((startX + endX) / 2, (startY + endY) / 2, endX, endY);
    }
    else
        first ? ++blue : ++white;
}

int main()
{
    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
            cin >> paper[i][j];
    }

    quadtree(0, 0, N, N);
    cout << white << '\n'
         << blue;
}