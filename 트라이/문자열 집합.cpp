#include <iostream>
#include <map>
#include <string>
using namespace std;

struct Trie
{
    map<int, Trie *> child;
    bool is_leaf = false;

    ~Trie()
    {
        for (pair<const int, Trie *> &p : child)
        {
            if (p.second != nullptr)
                delete p.second;
        }
    }

    void insert(const string &str, int idx = 0)
    {
        if (idx == str.size())
        {
            is_leaf = true;
            return;
        }

        int next = str[idx] - 'a';
        if (child[next] == nullptr)
            child[next] = new Trie();

        child[next]->insert(str, idx + 1);
    }

    bool find(const string &str, int idx = 0)
    {
        if (idx == str.size())
            return is_leaf;

        int next = str[idx] - 'a';
        if (child[next] == nullptr)
            return false;

        return child[next]->find(str, idx + 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Trie trie;
    size_t N, M;
    cin >> N >> M;
    for (size_t i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        trie.insert(str);
    }

    int ans = 0;
    for (size_t i = 0; i < M; ++i)
    {
        string str;
        cin >> str;
        if (trie.find(str))
            ++ans;
    }

    cout << ans << '\n';
}