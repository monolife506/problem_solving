#include <iostream>
#include <string>
using namespace std;

int main() {
    int cnt = 0;
    string str;
    
    getline(cin, str);
    while (str != "고무오리 디버깅 끝") {
        getline(cin, str);

        if (str == "문제")
            cnt++;
        else if (str == "고무오리") 
            (cnt > 0) ? cnt -= 1 : cnt += 2;
    }
    
    cout << (cnt == 0 ? "고무오리야 사랑해" : "힝구");
}