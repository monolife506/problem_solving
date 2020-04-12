#include <iostream>
#include <string>
using namespace std;

struct queue
{
    int arr[2'000'000 + 1];
    int head = 0;
    int tail = 0;
};

void push(queue &Q, int X)
{
    Q.arr[Q.tail++] = X;
}

int pop(queue &Q)
{
    if (Q.tail - Q.head == 0)
        return -1;
    else
        return Q.arr[Q.head++];
}

int size(queue &Q)
{
    return Q.tail - Q.head;
}

bool empty(queue &Q)
{
    return Q.tail - Q.head == 0;
}

int front(queue &Q)
{
    if (Q.tail - Q.head == 0)
        return -1;
    else
        return Q.arr[Q.head];
}

int back(queue &Q)
{
    if (Q.tail - Q.head == 0)
        return -1;
    else
        return Q.arr[Q.tail - 1];
}

// 전역 영역에서 선언된 변수는 할당 가능한 메모리 양이 더 크다.
queue Q;

// Class 구현도 가능하지만 일단은 struct만으로 구현해보자.
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    size_t N;
    cin >> N;

    string input;
    for (size_t i = 0; i < N; i++)
    {
        cin >> input;

        if (input == "push")
        {
            int tmp;
            cin >> tmp;
            push(Q, tmp);
        }
        else if (input == "pop")
            cout << pop(Q) << '\n';
        else if (input == "size")
            cout << size(Q) << '\n';
        else if (input == "empty")
            cout << empty(Q) << '\n';
        else if (input == "front")
            cout << front(Q) << '\n';
        else if (input == "back")
            cout << back(Q) << '\n';
    }
}
