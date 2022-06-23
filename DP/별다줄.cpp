#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

int cnt[301][200000];
ll cache[200000];

struct Trie
{
    map<char, Trie *> child;
    int word_cnt = 0;

    ~Trie()
    {
        for (pair<const char, Trie *> &p : child)
        {
            if (p.second != nullptr)
                delete p.second;
        }
    }

    void insert(const string &str, int idx = 0)
    {
        ++word_cnt;

        if (idx == str.size())
            return;

        int nxt = str[idx];
        if (child[nxt] == nullptr)
            child[nxt] = new Trie();

        child[nxt]->insert(str, idx + 1);
    }

    int get_cnt(const string &str, int idx = 0)
    {
        if (idx == str.size())
            return word_cnt;

        int nxt = str[idx];
        if (child[nxt] == nullptr)
            return 0;

        return child[nxt]->get_cnt(str, idx + 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    Trie *trie = new Trie();
    for (int i = 0; i < N; ++i)
    {
        string word;
        cin >> word;
        trie->insert(word);
    }

    string str;
    cin >> str;
    for (int i = 0; i < str.length(); ++i)
    {
        Trie *cur = trie;
        for (int j = 0; i + j < str.length(); ++j)
        {
            cur = cur->child[str[i + j]];
            if (cur == nullptr)
                break;

            cnt[j + 1][i] = cur->word_cnt;
        }
    }
    for (int i = 0; i < str.length(); ++i)
    {
        for (int j = 0; i - j >= 0 && j < 300; ++j)
        {
            if (i - j == 0)
                cache[i] += cnt[j + 1][i - j];
            else
                cache[i] += cnt[j + 1][i - j] * cache[i - j - 1];

            cache[i] %= MOD;
        }
    }

    cout << cache[str.length() - 1] << '\n';
}

/*

2
2 * 2 + 3 = 7
7 *

*/