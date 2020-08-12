// 17219번: 비밀번호 찾기

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    size_t N, M;
    map<string, string> list;
    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
    {
        string site, pwd;
        cin >> site >> pwd;
        list[site] = pwd;
    }
    for (size_t i = 0; i < M; i++)
    {
        string site;
        cin >> site;
        cout << list[site] << '\n';
    }
}