#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    size_t N;
    cin >> N;

    while (N != 0)
    {
        vector<int> nums(N);
        for (size_t i = 0; i < N; i++)
            cin >> nums[i];

        vector<bool> choice(N);
        for (size_t i = 0; i < 6; i++)
            choice[i] = true;

        do
        {
            for (size_t i = 0; i < N; i++)
            {
                if (choice[i] == true)
                    cout << nums[i] << " ";
            }
            cout << '\n';
        } while (prev_permutation(choice.begin(), choice.end()));

        cout << '\n';
        cin >> N;
    }
}