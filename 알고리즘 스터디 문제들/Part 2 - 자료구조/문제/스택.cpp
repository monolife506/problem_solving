#include <iostream>
#include <string>
using namespace std;

struct Stack
{
    int arr[10000];
    int top = -1;
};

void push(Stack &S, int X)
{
    S.arr[++S.top] = X;
}

int pop(Stack &S)
{
    if (S.top == -1)
        return -1;
    else
        return S.arr[S.top--];
}

bool empty(Stack &S)
{
    return S.top == -1;
}

int top(Stack &S)
{
    if (S.top == -1)
        return -1;
    else
        return S.arr[S.top];
}

int size(Stack &S)
{
    return S.top + 1;
}

// Class 구현도 가능하지만 일단은 struct만으로 구현해보자.
int main()
{
    size_t N;
    cin >> N;

    Stack S;
    string input;
    for (size_t i = 0; i < N; i++)
    {
        cin >> input;

        if (input == "push")
        {
            int tmp;
            cin >> tmp;
            push(S, tmp);
        }
        else if (input == "pop")
            cout << pop(S) << '\n';
        else if (input == "size")
            cout << size(S) << '\n';
        else if (input == "empty")
            cout << empty(S) << '\n';
        else if (input == "top")
            cout << top(S) << '\n';
    }
}