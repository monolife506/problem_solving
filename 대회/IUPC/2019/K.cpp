#include <iostream>
#include <vector>
using namespace std;

struct Card
{
    bool isFront = true;
    int front;
    int back;
    Card(int _front, int _back) : front(_front), back(_back) {}
};

int main()
{
    int N, M;
    cin >> N >> M;

    vector<Card> cards;
    for (size_t i = 0; i < N; i++)
    {
        int A, B;
        cin >> A >> B;
        cards.push_back(Card(A, B));
    }
    for (size_t i = 0; i < M; i++)
    {
        int K;
        cin >> K;
        for (size_t j = 0; j < N; j++)
        {
            Card &cur = cards[j];
            if ((cur.isFront && cur.front <= K) || (!cur.isFront && cur.back <= K))
                cur.isFront = !cur.isFront;
        }
    }

    int sum = 0;
    for (size_t j = 0; j < N; j++)
    {
        Card &cur = cards[j];
        sum += ((cur.isFront) ? cur.front : cur.back);
    }
    cout << sum;
}