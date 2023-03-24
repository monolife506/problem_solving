#include <iostream>
#include <string>
using namespace std;

struct Item
{
    int data;
    Item *link;
};

Item *front = NULL;
Item *rear = NULL;
int count = 0;

void push(int X)
{
    Item *new_item = new Item;
    new_item->data = X;
    new_item->link = NULL;
    if (count != 0)
    {
        rear->link = new_item;
        rear = new_item;
    }
    else
    {
        front = new_item;
        rear = new_item;
    }
    count++;
}

void pop()
{
    if (count == 0)
        cout << -1 << '\n';
    else
    {
        cout << front->data << '\n';
        front = front->link;
        count--;
    }
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    size_t N;
    string input;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> input;
        if (input == "push")
        {
            int X;
            cin >> X;
            push(X);
        }
        else if (input == "pop")
            pop();
        else if (input == "size")
            cout << count << '\n';
        else if (input == "empty")
        {
            cout << (count == 0) ? 1 : 0;
            cout << '\n';
        }
        else if (input == "front")
        {
            if (count == 0)
                cout << -1 << '\n';
            else
                cout << front->data << '\n';
        }
        else if (input == "back")
        {
            if (count == 0)
                cout << -1 << '\n';
            else
                cout << rear->data << '\n';
        }
    }
}