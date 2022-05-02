#include <iostream>
using namespace std;

size_t N;
int inorder[100001], inorder_idx[100001], postorder[100001];

void find_root(int l, int r, int offset)
{
    cout << postorder[r - offset] << " ";

    int &root_idx = inorder_idx[postorder[r - offset]];
    if (root_idx > l)
        find_root(l, root_idx - 1, offset);
    if (root_idx < r)
        find_root(root_idx + 1, r, offset + 1);
}

int main()
{
    cin >> N;
    for (size_t i = 0; i < N; ++i)
    {
        cin >> inorder[i];
        inorder_idx[inorder[i]] = i;
    }
    for (size_t i = 0; i < N; ++i)
    {
        cin >> postorder[i];
    }

    find_root(0, N - 1, 0);
    cout << '\n';
}
