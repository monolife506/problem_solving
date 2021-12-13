#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

constexpr int CHILD_CNT = 26;

struct Trie
{
    Trie *child[CHILD_CNT] = {};
    bool is_leaf = false; // 현재 글자에서 끝나는 문장 존재 여부

    ~Trie()
    {
        for (size_t i = 0; i < CHILD_CNT; i++)
        {
            if (child[i] != nullptr)
                delete child[i];
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

    int find(const string &str, int idx = 0)
    {
        if (is_leaf)
            return idx;
        if (idx == str.size())
            return -1;

        int next = str[idx] - 'a';
        if (child[next] == nullptr)
            return -1;

        return child[next]->find(str, idx + 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int C, N, Q;
    Trie color, nickname;
    cin >> C >> N;
    for (size_t i = 0; i < C; i++)
    {
        string str;
        cin >> str;
        color.insert(str);
    }
    for (size_t i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        reverse(str.begin(), str.end());
        nickname.insert(str);
    }

    cin >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        string name;
        cin >> name;

        int cnt1 = color.find(name);
        if (cnt1 == -1)
        {
            cout << "No" << '\n';
            continue;
        }

        reverse(name.begin(), name.end());
        int cnt2 = nickname.find(name);
        if (cnt2 == -1)
        {
            cout << "No" << '\n';
            continue;
        }

        if (cnt1 + cnt2 != name.size())
        {
            cout << "No" << '\n';
            continue;
        }
        cout << "Yes" << '\n';
    }
}