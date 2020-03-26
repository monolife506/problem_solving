// 11066번: 파일 합치기

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    size_t T;
    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        size_t K;
        cin >> K;

        vector<int> S(K);
        for (int &item : S)
            cin >> item;
    }
}