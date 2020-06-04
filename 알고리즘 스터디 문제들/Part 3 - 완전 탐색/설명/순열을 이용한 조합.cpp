#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // N은 숫자의 개수, M은 선택할 개수이다.
    size_t N, M;
    cin >> N >> M;

    // 선택할 숫자들이 N개 담긴 vector
    vector<int> nums(N);
    for (size_t i = 0; i < N; i++)
        cin >> nums[i];

    // 오름차순 출력을 위해 정렬
    sort(nums.begin(), nums.end());

    // 0 (false)과 1 (true)이 담긴 조합용 vector
    vector<bool> choice(N);
    for (size_t i = 0; i < M; i++)
    {
        // 0이 담긴 index가 선택하지 않는 항목의 index
        // 1이 담긴 index가 선택할 항목의 index
        // 즉 1은 M개, 0은 N - M개 들어있다.
        choice[i] = true;
    }

    do
    {
        for (size_t i = 0; i < N; i++)
        {
            if (choice[i] == true)      // index가 선택한 항목일 때
                cout << nums[i] << " "; // 출력.
        }
        cout << '\n';
    } while (prev_permutation(choice.begin(), choice.end()));
    // 이미 1이 앞에 와서 사전순 마지막으로 정렬된 상태이므로,
    // 사전순 처음 방향으로 모든 선택 경우를 탐색한다.
}