#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Word
{
    string str;
    size_t wordsize;
};

bool cmp(const Word &a, const Word &b)
{
    if (a.wordsize < b.wordsize)
        return true;
    else if (a.wordsize == b.wordsize)
        return a.str < b.str;
    else
        return false;
}

int main()
{
    size_t N;
    cin >> N;

    vector<Word> wordlist;
    string temp_str;
    Word temp_word;
    for (size_t i = 0; i < N; i++)
    {
        cin >> temp_str;
        temp_word.str = temp_str;
        temp_word.wordsize = temp_str.size();
        wordlist.push_back(temp_word);
    }

    stable_sort(wordlist.begin(), wordlist.end(), cmp);
    temp_str = "";
    for (const auto& item : wordlist)
    {
        if (temp_str != item.str)
        {
            cout << item.str << '\n';
            temp_str = item.str;
        }
        else
            continue;
    }
}