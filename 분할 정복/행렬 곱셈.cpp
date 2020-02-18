// 2740번: 행렬 곱셈

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    size_t N, M, K;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (vector<int> &row : A)
    {
        for (int &num : row)
            cin >> num;
    }

    cin >> M >> K;
    vector<vector<int>> B(M, vector<int>(K));
    for (vector<int> &row : B)
    {
        for (int &num : row)
            cin >> num;
    }

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < K; j++)
        {
            int sum = 0;
            for (size_t k = 0; k < M; k++)
                sum += (A[i][k] * B[k][j]);
            cout << sum << " ";
        }
        cout << '\n';
    }
}