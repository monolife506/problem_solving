// 10816번: 숫자 카드 2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    size_t N, M;
    cin >> N;
    vector<int> card_N(N);
    for (int &item : card_N)
        cin >> item;
    cin >> M;
    vector<int> card_M(M);
    for (int &item : card_M)
        cin >> item;

    sort(card_N.begin(), card_N.end());
    for (const int target : card_M)
        cout << upper_bound(card_N.begin(), card_N.end(), target) -
                    lower_bound(card_N.begin(), card_N.end(), target)
             << " ";
}