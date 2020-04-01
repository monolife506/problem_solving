#include <iostream>
#include <vector>
using namespace std;

// vector를 함수에 넘길땐 다음과 같은 형식으로 옮김
// vector의 값을 수정하고 싶다면 const를 제외할 것
void vector_display(const vector<int> &v)
{
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << '\n';
}

int main()
{
    // 배열과 같은 방식으로 초기화 가능. 크기는 가변적으로 조정됨
    vector<int> vec1 = {1, 2, 4, 7, 10};

    // 크기가 5인 string vector. "item"으로 초기화되어 있음.
    vector<string> vec2(5, "item");

    cout << "vec1의 첫 원소: " << vec1.front() << '\n';
    cout << "vec1의 마지막 원소: " << vec1.back() << '\n';

    cout << "vec1의 내용\n";
    vector_display(vec1);

    int tmp = 100;
    vec1.push_back(100);
    vec1.push_back(15);
    vec1.push_back(24);

    cout << "\n\npush_back 이후 vec1의 내용\n";
    vector_display(vec1);

    for (size_t i = 0; i < 6; i++)
        vec1.pop_back();

    cout << "\n\npop_back 이후 vec1의 내용\n";
    vector_display(vec1);

    vec2.resize(7, "new item");
    cout << "\n\nresize 이후 vec2의 내용\n";
    vector_display(vec2);

    vec1.clear();
    if (vec1.empty())
        cout << "clear 이후 vec1은 비어있는 상태임";

    // +. string도 위 멤버 함수들을 모두 사용할 수 있다.
}