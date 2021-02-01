#include <iostream>
using namespace std;

int arr[14];

int main()
{
    int start;
    cin >> start;
    for (size_t i = 0; i < 14; i++)
        cin >> arr[i];

    int A = 0, moneyA = start;
    int B = 0, moneyB = start;
    for (size_t i = 0; i < 13; i++) {
        A += (moneyA / arr[i]);
        moneyA -= arr[i] * (moneyA / arr[i]);

        if (i >= 3) {
            if (arr[i - 3] < arr[i - 2] && arr[i - 2] < arr[i - 1] && arr[i - 1] < arr[i]) {
                moneyB += B * arr[i];
                B = 0;
            } else if (arr[i - 3] > arr[i - 2] && arr[i - 2] > arr[i - 1] && arr[i - 1] > arr[i]) {
                B += (moneyB / arr[i]);
                moneyB -= arr[i] * (moneyB / arr[i]);
            }
        }
    }

    A *= arr[13];
    A += moneyA;
    B *= arr[13];
    B += moneyB;

    if (A > B)
        cout << "BNP";
    else if (A < B)
        cout << "TIMING";
    else
        cout << "SAMESAME";
}
