// 10882번: International meeting

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
typedef pair<int, int> P;

P curTime;
int curTimezone;
int timezones[50];

int UTCtoint(const string &str)
{
    return (int)(10 * stod(str.substr(3)));
}

P stoTime(const string &str)
{
    P time;
    time.first = stod(str.substr(0, 3));
    time.second = stod(str.substr(3));
    return time;
}

P getTime(P time, int UTCdiff)
{
    int hourDiff = UTCdiff / 10;
    int minuteDiff = (UTCdiff % 10) * 6;

    time.second -= minuteDiff;
    if (time.second < 0)
    {
        time.first--;
        time.second += 60;
    }
    else if (time.second >= 60)
    {
        time.first++;
        time.second -= 60;
    }

    time.first -= hourDiff;
    if (time.first < 0)
        time.first += 24;
    else if (time.first >= 24)
        time.first -= 24;

    return time;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.fill('0');

    size_t N;
    string input;
    cin >> N;

    // 현재 시간
    cin >> input;
    curTime = stoTime(input);
    // 현재 UTC
    cin >> input;
    curTimezone = UTCtoint(input);

    for (size_t i = 0; i < N; i++)
    {
        cin >> input;
        timezones[i] = UTCtoint(input);

        P timehere = getTime(curTime, curTimezone - timezones[i]);
        cout << right << setw(2) << timehere.first << ":" << setw(2) << timehere.second << '\n';
    }
}