// 15898번: 파이의 아틀리에 ~신비한 대회의 연금술사~

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, char> P;

int maxQual = 0;   // 최대 품질
P ingre[10][4][4]; // 재료들의 배열

void addtoPot(int ingreNum, int initPlace, int rotation, vector<vector<P>> &pot)
{
    // 삽입 위치에 따라 삽입
    if (initPlace == 2 || initPlace == 3)
        initPlace += 3;

    int initRow = initPlace / 5;
    int initCol = initPlace % 5;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            P &cur = pot[initRow + i][initCol + j];
            switch (rotation)
            {
            case 0:
                cur.first += ingre[ingreNum][i][j].first;
                if (ingre[ingreNum][i][j].second != 'W')
                    cur.second = ingre[ingreNum][i][j].second;
                break;

            case 1:
                cur.first += ingre[ingreNum][j][3 - i].first;
                if (ingre[ingreNum][j][3 - i].second != 'W')
                    cur.second = ingre[ingreNum][j][3 - i].second;
                break;

            case 2:
                cur.first += ingre[ingreNum][3 - i][3 - j].first;
                if (ingre[ingreNum][3 - i][3 - j].second != 'W')
                    cur.second = ingre[ingreNum][3 - i][3 - j].second;
                break;

            case 3:
                cur.first += ingre[ingreNum][3 - j][i].first;
                if (ingre[ingreNum][3 - j][i].second != 'W')
                    cur.second = ingre[ingreNum][3 - j][i].second;
                break;
            }

            if (cur.first < 0)
                cur.first = 0;
            else if (cur.first > 9)
                cur.first = 9;
        }
    }
}

int getSum(vector<vector<P>> &pot)
{
    int qual = 0;
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            switch (pot[i][j].second)
            {
            case 'R':
                qual += (7 * pot[i][j].first);
                break;
            case 'B':
                qual += (5 * pot[i][j].first);
                break;
            case 'G':
                qual += (3 * pot[i][j].first);
                break;
            case 'Y':
                qual += (2 * pot[i][j].first);
                break;
            default:
                break;
            }
        }
    }

    return qual;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (size_t j = 0; j < 4; j++)
            for (size_t k = 0; k < 4; k++)
                cin >> ingre[i][j][k].first;

        for (size_t j = 0; j < 4; j++)
            for (size_t k = 0; k < 4; k++)
                cin >> ingre[i][j][k].second;
    }

    vector<bool> choice(N, false); // 선택한 3개의 재료
    vector<int> order;             // 재료 3개를 넣는 순서
    vector<vector<P>> pot(5);      // 가마솥

    for (size_t i = 0; i < 3; i++)
        choice[i] = true;

    do
    {
        order.clear();
        for (int i = 0; i < N; i++)
        {
            if (choice[i])
                order.push_back(i);
        }

        do
        {
            for (int initPlace1 = 0; initPlace1 < 4; initPlace1++)
            {
                for (int rotation1 = 0; rotation1 < 4; rotation1++)
                {
                    for (int initPlace2 = 0; initPlace2 < 4; initPlace2++)
                    {
                        for (int rotation2 = 0; rotation2 < 4; rotation2++)
                        {
                            for (int initPlace3 = 0; initPlace3 < 4; initPlace3++)
                            {
                                for (int rotation3 = 0; rotation3 < 4; rotation3++)
                                {
                                    fill(pot.begin(), pot.end(), vector<P>(5, P(0, 'W')));
                                    addtoPot(order[0], initPlace1, rotation1, pot);
                                    addtoPot(order[1], initPlace2, rotation2, pot);
                                    addtoPot(order[2], initPlace3, rotation3, pot);
                                    maxQual = max(maxQual, getSum(pot));
                                }
                            }
                        }
                    }
                }
            }
        } while (next_permutation(order.begin(), order.end()));
    } while (prev_permutation(choice.begin(), choice.end()));

    cout << maxQual;
}

// 1번 회전
// -8 9 -6 6
// 2 5 8 3
// -3 1 -6 3
// -1 -1 8 -9

// 2번 회전
// -1 -3 2 -8
// -1 1 5 9
// 8 -6 8 -6
// -9 3 3 6

// 3번 회전
// -9 8 -1 -1
// 3 -6 1 -3
// 3 8 5 2
// 6 -6 9 -8