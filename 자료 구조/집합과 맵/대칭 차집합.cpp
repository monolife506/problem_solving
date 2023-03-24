#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t a_size, b_size;
    cin >> a_size >> b_size;

    unordered_set<int> a, b;
    for (size_t i = 0; i < a_size; ++i)
    {
        int num;
        cin >> num;
        a.insert(num);
    }
    for (size_t i = 0; i < b_size; ++i)
    {
        int num;
        cin >> num;
        b.insert(num);
    }

    unordered_set<int> symmetric_difference;
    for (const int num : a)
    {
        if (b.find(num) == b.end())
            symmetric_difference.insert(num);
    }
    for (const int num : b)
    {
        if (a.find(num) == a.end())
            symmetric_difference.insert(num);
    }

    cout << symmetric_difference.size() << '\n';
}