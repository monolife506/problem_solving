#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

constexpr int CNT = 26;

class Trie {
private:
    bool is_leaf = false;
    Trie* child[CNT] = {};

public:
    ~Trie()
    {
        for (size_t i = 0; i < CNT; i++) {
            if (child[i] != nullptr)
                delete child[i];
        }
    }

    bool insert(const string& str, int idx = 0)
    {
        if (idx == str.size())
            return is_leaf = true;

        if (is_leaf)
            return false;

        int next = str[idx] - '0';
        if (child[next] == nullptr)
            child[next] = new Trie();
        return child[next]->insert(str, idx + 1);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (size_t tc = 0; tc < t; tc++) {
        bool flag = true;
        int n;
        vector<string> v;
        Trie trie;

        cin >> n;
        for (size_t i = 0; i < n; i++) {
            string str;
            cin >> str;
            v.push_back(str);
        }

        sort(v.begin(), v.end());
        for (string& str : v) {
            if (!trie.insert(str))
                flag = false;
        }

        cout << ((flag) ? "YES" : "NO") << '\n';
    }
}