#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

constexpr int CHILD_CNT = 26;

struct Trie
{
    Trie *child[CHILD_CNT] = {};
    int child_cnt = 0;    // 자식 노드의 개수
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
        {
            child[next] = new Trie();
            child_cnt++;
        }

        child[next]->insert(str, idx + 1);
    }

    int getCnt(const string &str, int idx = 0)
    {
        if (idx == str.size())
            return 0;

        int next = str[idx] - 'a';
        if (idx == 0 || child_cnt != 1 || (child_cnt == 1 && is_leaf))
            return child[next]->getCnt(str, idx + 1) + 1;
        else
            return child[next]->getCnt(str, idx + 1);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    while (cin >> n)
    {
        // 트라이 만들기
        Trie trie;
        vector<string> words(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> words[i];
            trie.insert(words[i]);
        }

        // 평균 입력 횟수 계산하기
        int total = 0;
        for (size_t i = 0; i < n; i++)
            total += trie.getCnt(words[i]);

        cout << fixed << setprecision(2) << (double)total / n << '\n';
    }
}