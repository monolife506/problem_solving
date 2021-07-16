#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Trie {
private:
    map<string, Trie*> child;

public:
    ~Trie()
    {
        for (auto it = child.begin(); it != child.end(); ++it)
            delete it->second;
    }

    void insert(const vector<string>& v, int idx = 0)
    {
        if (idx == v.size())
            return;

        const string& cur = v[idx];
        if (child.find(cur) == child.end())
            child[cur] = new Trie();
        child[cur]->insert(v, idx + 1);
    }

    void traverse(int level = 0)
    {
        if (child.empty())
            return;

        for (auto it = child.begin(); it != child.end(); ++it) {
            for (size_t i = 0; i < level; i++)
                cout << "--";
            cout << it->first << '\n';
            it->second->traverse(level + 1);
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    string str;
    Trie trie;
    vector<string> v;

    cin >> N;
    for (size_t i = 0; i < N; i++) {
        v.clear();
        cin >> K;
        for (size_t j = 0; j < K; j++) {
            cin >> str;
            v.push_back(str);
        }
        trie.insert(v);
    }

    trie.traverse();
}