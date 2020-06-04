#include <iostream>
#include <array>
#include <string>
using namespace std;

int main()
{
    size_t N, M;
    cin >> N >> M;

    // 제대로 칠해진 상태인 8*8 보드
    array<array<char, 8>, 8> white;
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            // 삼항 연산자, if else문을 대체합니다.
            bool flag = (i % 2 == 0) ? 0 : 1;
            white[i][j] = ((j + flag) % 2 == 0) ? 'W' : 'B';
        }
    }

    array<string, 50> board;
    for (size_t i = 0; i < N; i++)
        cin >> board[i];

    // 채울 최소 칸수
    int min_cnt = 2500;

    // 시작하는 행과 열 결정하기
    for (size_t startRow = 0; startRow + 7 < N; startRow++)
    {
        for (size_t startColumn = 0; startColumn + 7 < M; startColumn++)
        {
            int cnt = 0;

            // 시작 행과 열에 대해 칸 비교하기
            for (size_t i = startRow; i < startRow + 8; i++)
            {
                for (size_t j = startColumn; j < startColumn + 8; j++)
                {
                    if (board[i][j] != white[i - startRow][j - startColumn])
                        cnt++;
                }
            }

            // min 함수로 칸을 채우는 2가지 경우 중 더 적은 경우의 수를 고릅니다.
            cnt = min(cnt, 64 - cnt);

            // min 함수로 현재 칸을 채우는 갯수가 최솟값보다 작다면 갱신합니다.
            min_cnt = min(cnt, min_cnt);
        }
    }

    cout << min_cnt;
}