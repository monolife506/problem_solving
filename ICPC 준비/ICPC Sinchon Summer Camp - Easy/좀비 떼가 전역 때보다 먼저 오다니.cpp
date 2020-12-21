#include <iostream>
using namespace std;

int Z[19];
int L, B1p, B2p, B2a, B3p, B3l, B3a;
bool survive = false;

void fire(int cur, int front)
{
    if (Z[cur] > 0) // DEAD
        return;

    while (front <= L && Z[front] <= 0) // NO ZOMBIE ON FRONT
        front++;

    if (front > L) // SURVIVE
    {
        survive = true;
        return;
    }

    // 소총
    if (B2a > 0 && Z[front] > B1p)
    {
    }

    // 샷건
    if (B2a > 0 && Z[front] > B1p)
    {
        Z[front] -= B2p;
        B2a--;
        fire(cur + 1, front);

        Z[front] += B2p;
        B2a++;
    }

    // 저격총
    if (B3a > 0)
    {
        for (size_t i = front; i < L + 1 && i < front + B3l; i++)
            Z[i] -= B3p;
        B3a--;
        fire(cur + 1, front);

        for (size_t i = front; i < L + 1 && i < front + B3l; i++)
            Z[i] += B3p;
        B3a++;
    }
}

int main()
{
    cin >> L >> B1p >> B2p >> B2a >> B3p >> B3l >> B3a;
    for (size_t i = 1; i <= L; i++)
        cin >> Z[i];

    fire(0, 1);
    cout << (survive ? "YES" : "NO");
}