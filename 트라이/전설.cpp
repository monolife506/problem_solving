#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;

bool color_len[2001]; // 특정 길이의 색깔의 존재 여부

struct Trie
{
    map<int, Trie *> child; // 메모리 초과 방지
    bool is_leaf = false;   // 현재 글자에서 끝나는 문장 존재 여부

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

    void findColor(const string &str, int idx = 0)
    {
        color_len[idx] = is_leaf;
        if (idx == str.size())
            return;

        int next = str[idx] - 'a';
        if (child[next] == nullptr)
            return;

        return child[next]->findColor(str, idx + 1);
    }

    bool findName(const string &str, int idx = 0)
    {
        if (idx == str.size())
            return is_leaf ? color_len[str.size() - idx] : false;
        if (is_leaf && color_len[str.size() - idx])
            return true;

        int next = str[idx] - 'a';
        if (child[next] == nullptr)
            return false;

        return child[next]->findName(str, idx + 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Trie color, nickname;

    int C, N, Q;
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

        memset(color_len, false, sizeof(color_len));
        color.findColor(name);
        reverse(name.begin(), name.end());
        cout << (nickname.findName(name) ? "Yes" : "No") << '\n';
    }
}