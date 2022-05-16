#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct Album
{
    string name;
    Album *parent;

    set<string> photos;
    map<string, Album *> sub_album;

    Album(const string &name, Album *parent) : name(name), parent(parent) {}

    void make_album(const string &S)
    {
        if (sub_album.find(S) != sub_album.end())
        {
            cout << "duplicated album name" << '\n';
            return;
        }

        sub_album[S] = new Album(S, this);
    }

    pair<int, int> remove_albrm(const string &S)
    {
        if (sub_album.find(S) == sub_album.end())
            return {0, 0};

        pair<int, int> ret = sub_album[S]->remove_all_album();

        ++ret.first;
        ret.second += sub_album[S]->delete_all_photo();

        delete sub_album[S];
        sub_album.erase(S);

        return ret;
    }

    pair<int, int> remove_first_album()
    {
        if (sub_album.empty())
            return {0, 0};

        return remove_albrm(sub_album.begin()->first);
    }

    pair<int, int> remove_last_album()
    {
        if (sub_album.empty())
            return {0, 0};

        return remove_albrm(sub_album.rbegin()->first);
    }

    pair<int, int> remove_all_album()
    {
        pair<int, int> ret = {0, 0};

        vector<string> S;
        for (pair<const string, Album *> &p : sub_album)
            S.push_back(p.first);

        while (!S.empty())
        {
            pair<int, int> cnt = remove_albrm(S.back());
            ret.first += cnt.first;
            ret.second += cnt.second;
            S.pop_back();
        }

        return ret;
    }

    void insert_photo(const string &S)
    {
        if (photos.find(S) != photos.end())
        {
            cout << "duplicated photo name" << '\n';
            return;
        }

        photos.insert(S);
    }

    int delete_photo(string &S)
    {
        if (photos.find(S) == photos.end())
            return 0;

        photos.erase(S);
        return 1;
    }

    int delete_first_photo()
    {
        if (photos.empty())
            return 0;

        photos.erase(*photos.begin());
        return 1;
    }

    int delete_last_photo()
    {
        if (photos.empty())
            return 0;

        photos.erase(*photos.rbegin());
        return 1;
    }

    int delete_all_photo()
    {
        int photo_cnt = photos.size();
        photos.clear();

        return photo_cnt;
    }

    Album *change_album(const string &S)
    {
        if (sub_album.find(S) == sub_album.end())
            return this;

        return sub_album[S];
    }

    Album *change_album_parent()
    {
        return (parent != nullptr) ? parent : this;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    Album *root = new Album("album", nullptr);
    Album *cur = root;
    for (int i = 0; i < N; ++i)
    {
        string cmd, arg;
        cin >> cmd >> arg;

        if (cmd == "mkalb")
        {
            cur->make_album(arg);
        }
        else if (cmd == "rmalb")
        {
            pair<int, int> cnt;

            if (arg == "-1")
                cnt = cur->remove_first_album();
            else if (arg == "0")
                cnt = cur->remove_all_album();
            else if (arg == "1")
                cnt = cur->remove_last_album();
            else
                cnt = cur->remove_albrm(arg);

            cout << cnt.first << " " << cnt.second << '\n';
        }
        else if (cmd == "insert")
        {
            cur->insert_photo(arg);
        }
        else if (cmd == "delete")
        {
            if (arg == "-1")
                cout << cur->delete_first_photo() << '\n';
            else if (arg == "0")
                cout << cur->delete_all_photo() << '\n';
            else if (arg == "1")
                cout << cur->delete_last_photo() << '\n';
            else
                cout << cur->delete_photo(arg) << '\n';
        }
        else if (cmd == "ca")
        {
            if (arg == "/")
                cur = root;
            else if (arg == "..")
                cur = cur->change_album_parent();
            else
                cur = cur->change_album(arg);

            cout << cur->name << '\n';
        }
    }
}