#include <iostream>
#include <array>
#include <string>
#include <algorithm>
using namespace std;

struct Student
{
    int age;
    string name;
};

// 먼저 나이순으로 오름차순, 나이가 같다면 이름 순으로
// 오름차순 정렬한다.
bool cmp(const Student &A, const Student &B)
{
    if (A.age != B.age)
        return A.age < B.age;
    else
        return A.name < B.name;
}

void print_struct(const array<Student, 6> &arr)
{
    cout << "Print array\n";
    for (size_t i = 0; i < arr.size(); i++)
        cout << arr[i].age << " " << arr[i].name << '\n';

    cout << '\n';
}

int main()
{
    array<Student, 6> arr;

    arr[0] = {18, "Niceguy"};
    arr[1] = {18, "Man"};
    arr[2] = {19, "John"};
    arr[3] = {17, "Proman"};
    arr[4] = {18, "Mom"};
    arr[5] = {17, "Bboy"};
    arr[6] = {19, "Ann"};

    print_struct(arr);
    sort(arr.begin(), arr.end(), cmp);
    print_struct(arr);
}