#include <iostream>
#include <string>
using namespace std;

int space;
int alphabet[26];

char toUpperCase(char chr) {
  if (chr >= 'a' && chr <= 'z')
    return chr - 32;
  else
    return chr;
}

string genTitle(string& str) {
  string title;
  bool spaceFlag = true;
  for (char& chr : str) {
    if (chr == ' ') {
      spaceFlag = true;
      continue;
    }
    if (spaceFlag && chr != ' ') {
      spaceFlag = false;
      title.push_back(toUpperCase(chr));
    }
  }

  return title;
}

bool checkCnt(string& str) {
  bool flag = true;
  char before = '\0';
  for (size_t i = 0; i < str.size(); i++) {
    char cur = toUpperCase(str[i]);
    if (cur == before) continue;

    if (cur == ' ') {
      if (space == 0)
        return false;
      else
        space--;
    } else {
      if (alphabet[cur - 'A'] == 0)
        return false;
      else
        alphabet[cur - 'A']--;
    }

    before = cur;
  }

  return flag;
}

int main() {
  string str;
  string title;

  getline(cin, str);
  cin >> space;
  for (size_t i = 0; i < 26; i++) cin >> alphabet[i];

  title = genTitle(str);
  if (checkCnt(str) && checkCnt(title))
    cout << title;
  else
    cout << -1;
}
