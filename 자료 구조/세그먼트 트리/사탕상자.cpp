#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;

class SegmentTree
{
private:
    int n = MAX + 1; // 저장한 값의 개수
    vector<int> vec; // 세그먼트 트리의 정보를 저장하는 vector

    int kth(int cur, int lo, int hi, int k)
    {
        if (lo == hi)
            return lo;

        int mid = (lo + hi) / 2;
        int left_cnt = vec[cur * 2];

        if (k <= left_cnt) // k번째 수에 포함되지 않은 경우
            return kth(cur * 2, lo, mid, k);

        return kth(cur * 2 + 1, mid + 1, hi, k - left_cnt);
    }

    void update(int cur, int lo, int hi, int idx, int val)
    {
        if (idx < lo || idx > hi)
            return;

        vec[cur] += val;
        if (lo != hi)
        {
            int mid = (lo + hi) / 2;
            update(cur * 2, lo, mid, idx, val);
            update(cur * 2 + 1, mid + 1, hi, idx, val);
        }
    }

public:
    explicit SegmentTree() : vec(4 * n, 0) {}

    // k번째 값 얻기 + k번째 값 지우기
    int kth(int k) { return kth(1, 1, n, k); }

    // 특정 순위의 값 수정하기
    void update(int idx, int val) { update(1, 1, n, idx, val); }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    SegmentTree tree = SegmentTree();
    for (size_t i = 0; i < n; i++)
    {
        int A, B, C;
        cin >> A >> B;

        if (A == 1) // query
        {
            int idx = tree.kth(B);
            cout << idx << '\n';
            tree.update(idx, -1);
        }
        else // update
        {
            cin >> C;
            tree.update(B, C);
        }
    }
}