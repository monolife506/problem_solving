// 7662번: 이중 우선순위 큐
// 실제로 우선순위 큐를 사용하지는 않음

#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    multiset<int> Q;
    for (size_t i = 0; i < T; i++)
    {
        int k;
        cin >> k;
        for (size_t j = 0; j < k; j++)
        {
            char chr;
            int num;
            cin >> chr >> num;

            if (chr == 'D' && !Q.empty())
                (num == 1) ? Q.erase(prev(Q.end())) : Q.erase(Q.begin());
            else if (chr == 'I')
                Q.insert(num);
        }

        if (Q.empty())
            cout << "EMPTY" << '\n';
        else
            cout << *Q.rbegin() << " " << *Q.begin() << '\n';
        Q.clear();
    }
}