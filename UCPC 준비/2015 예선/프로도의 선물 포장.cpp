// 10881번: 프로도의 선물 포장

#include <iostream>
using namespace std;
typedef pair<int, int> P;

P gifts[3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; tc++)
    {
        int ans = INT32_MAX;
        for (size_t i = 0; i < 3; i++)
            cin >> gifts[i].first >> gifts[i].second;

        // Case 1
        for (size_t i = 0; i < 8; i++) // 회전 판단
        {
            int curWidth = 0;  // 가로
            int curHeight = 0; // 세로

            for (size_t j = 0; j < 3; j++) // 박스별 확인
            {
                if (i & (1 << j)) // 회전한 경우 (가로세로 변경)
                {
                    curWidth += gifts[j].second;
                    curHeight = max(gifts[j].first, curHeight);
                }
                else // 회전 안한 경우
                {
                    curWidth += gifts[j].first;
                    curHeight = max(gifts[j].second, curHeight);
                }
            }

            ans = min(ans, curWidth * curHeight);
        }

        // Case 2
        for (size_t i = 0; i < 3; i++) // 왼쪽에 있을 박스
        {
            int leftBox1 = (i + 1) % 3;
            int leftBox2 = (i + 2) % 3;

            for (size_t j = 0; j < 8; j++) // 회전 판단
            {
                int curWidth = (j & (1 << i)) ? gifts[i].second : gifts[i].first;  // 가로
                int curHeight = (j & (1 << i)) ? gifts[i].first : gifts[i].second; // 세로

                // 가로 (두 박스중에서 너비의 최댓값)
                // 세로 (두 박스의 높이의 합)

                if (!(j & (1 << leftBox1)) && !(j & (1 << leftBox2)))
                {
                    curWidth += max(gifts[leftBox1].first, gifts[leftBox2].first);
                    curHeight = max(curHeight, gifts[leftBox1].second + gifts[leftBox2].second);
                }
                else if ((j & (1 << leftBox1)) && !(j & (1 << leftBox2)))
                {
                    curWidth += max(gifts[leftBox1].second, gifts[leftBox2].first);
                    curHeight = max(curHeight, gifts[leftBox1].first + gifts[leftBox2].second);
                }
                else if (!(j & (1 << leftBox1)) && (j & (1 << leftBox2)))
                {
                    curWidth += max(gifts[leftBox1].first, gifts[leftBox2].second);
                    curHeight = max(curHeight, gifts[leftBox1].second + gifts[leftBox2].first);
                }
                else
                {
                    curWidth += max(gifts[leftBox1].second, gifts[leftBox2].second);
                    curHeight = max(curHeight, gifts[leftBox1].first + gifts[leftBox2].first);
                }

                ans = min(ans, curWidth * curHeight);
            }
        }

        cout << ans << '\n';
    }
}

// 위쪽에 삽입 or 오른쪽에 삽입
// 각각을 회전하는 경우이므로 총 8가지

// Case 1

// X X X
// X X X
// 0 1 2

// Case 2

// X X X
// X 2 X
// 0 1 X

// X X X
// X 2 X
// 1 0 X

// X X X
// X 1 X
// 2 0 X