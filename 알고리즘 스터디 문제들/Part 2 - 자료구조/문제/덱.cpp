#include <iostream>
#include <string>
using namespace std;

struct deque
{
    int arr[20'000 + 1];
    int head = 10'000;
    int tail = 10'000;
};

void push_front(deque &D, int X)
{
    D.arr[--D.head] = X;
}

void push_back(deque &D, int X)
{
    D.arr[D.tail++] = X;
}

bool empty(deque &D)
{
    return (D.tail - D.head) == 0;
}

int pop_front(deque &D)
{
    if (empty(D))
        return -1;
    else
        return D.arr[D.head++];
}

int pop_back(deque &D)
{
    if (empty(D))
        return -1;
    else
        return D.arr[--D.tail];
}

int size(deque &D)
{
    return (D.tail - D.head);
}

int front(deque &D)
{
    if (empty(D))
        return -1;
    else
        return D.arr[D.head];
}

int back(deque &D)
{
    if (empty(D))
        return -1;
    else
        return D.arr[D.tail - 1];
}

// Class 구현도 가능하지만 일단은 struct만으로 구현해보자.
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    size_t N;
    cin >> N;

    deque D;
    string input;
    for (size_t i = 0; i < N; i++)
    {
        cin >> input;

        if (input == "push_front")
        {
            int tmp;
            cin >> tmp;
            push_front(D, tmp);
        }
        else if (input == "push_back")
        {
            int tmp;
            cin >> tmp;
            push_back(D, tmp);
        }
        else if (input == "pop_front")
            cout << pop_front(D) << '\n';
        else if (input == "pop_back")
            cout << pop_back(D) << '\n';
        else if (input == "size")
            cout << size(D) << '\n';
        else if (input == "empty")
            cout << empty(D) << '\n';
        else if (input == "front")
            cout << front(D) << '\n';
        else if (input == "back")
            cout << back(D) << '\n';
    }
}
