// 2263번: 트리의 순회
// 분할 정복 기법

#include <iostream>
using namespace std;

int N;
int inorder[100001];
int postorder[100001];

void findroot(int start, int end, int shift)
{
    cout << postorder[end] << " ";
    if (start == end)
        return;

    for (size_t i = start + shift; i <= end + shift; i++)
    {
        if (inorder[i] == postorder[end])
        {
            if (i != start + shift)
                findroot(start, i - (shift + 1), shift); // 왼쪽 자식의 루트 찾기
            if (i != end + shift)
                findroot(i - shift, end - 1, shift + 1); // 오른쪽 자식의 루트 찾기
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> inorder[i];
    for (int i = 0; i < N; i++)
        cin >> postorder[i];

    findroot(0, N - 1, 0);
}

// DBEGFCA (DBAECFG) => A
// DB (shift == 0) && EGFC (shift == 1) => B
// D (shift == 0) && EGFC (shift == 1) => D
// EGFC (shift == 1) => C
// E (shift == 1) && GF (shift == 2) => E
// GF (shift == 2) => F
// G (shift == 3) => G
