// 2448번: 별 찍기 11

#include <iostream>
using namespace std;

void print(int depth, int line)
{
    if (depth == 3)
    {
        switch (line)
        {
        case 0:
            cout << "*";
            break;

        case 1:
            cout << "* *";
            break;

        case 2:
            cout << "*****";
            break;
        }
        return;
    }

    int formline = line % (depth / 2);
    if (line < (depth / 2))
        print(depth / 2, formline);
    else
    {
        int midWhitespace = (depth - 1) - 2 * (line - (depth / 2));

        print(depth / 2, formline);
        for (size_t i = 0; i < midWhitespace; i++) // 중간 공백
            cout << " ";
        print(depth / 2, formline);
    }
}

int main()
{
    int N;
    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        int whitespace = N - (i + 1);
        for (size_t i = 0; i < whitespace; i++) // 시작 공백
            cout << " ";
        print(N, i);
        for (size_t i = 0; i < whitespace; i++) // 끝 공백
            cout << " ";

        cout << '\n';
    }
}

// 2 -> 5 -> 11 -> 23
// 3 -> 6 -> 12 -> 24