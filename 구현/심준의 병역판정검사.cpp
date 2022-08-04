#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        double height, weight;
        cin >> height >> weight;

        double bmi = weight / ((height / 100) * (height / 100));
        if (height < 140.1)
        {
            cout << 6 << '\n';
        }
        else if (height < 146)
        {
            cout << 5 << '\n';
        }
        else if (height < 159)
        {
            cout << 4 << '\n';
        }
        else if (height < 161)
        {
            if (bmi >= 16 && bmi < 35)
                cout << 3 << '\n';
            else
                cout << 4 << '\n';
        }
        else if (height < 204)
        {
            if (bmi >= 20 && bmi < 25)
                cout << 1 << '\n';
            else if ((bmi >= 18.5 && bmi < 20) || (bmi >= 25 && bmi < 30))
                cout << 2 << '\n';
            else if ((bmi >= 16 && bmi < 18.5) || (bmi >= 30 && bmi < 35))
                cout << 3 << '\n';
            else
                cout << 4 << '\n';
        }
        else
        {
            cout << 4 << '\n';
        }
    }
}