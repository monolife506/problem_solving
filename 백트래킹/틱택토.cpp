#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

unordered_set<string> terminal_state;

bool isMatched(string &state)
{
    for (size_t i = 0; i < 3; i++)
    {
        if (state[i] == state[i + 3] && state[i + 3] == state[i + 6] && state[i] != '.')
            return true;
        if (state[3 * i] == state[3 * i + 1] && state[3 * i + 1] == state[3 * i + 2] && state[3 * i] != '.')
            return true;
    }

    if (state[0] == state[4] && state[4] == state[8] && state[0] != '.')
        return true;
    if (state[2] == state[4] && state[4] == state[6] && state[2] != '.')
        return true;

    return false;
}

void backtracking(string &state, bool turn)
{
    if (isMatched(state))
    {
        terminal_state.insert(state);
        return;
    }

    bool is_terminal_state = true;
    for (size_t i = 0; i < 9; i++)
    {
        if (state[i] == '.')
        {
            is_terminal_state = false;
            state[i] = turn ? 'X' : 'O';
            backtracking(state, !turn);
            state[i] = '.';
        }
    }

    if (is_terminal_state)
        terminal_state.insert(state);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string state = ".........";
    backtracking(state, true);

    cin >> state;
    while (state != "end")
    {
        if (terminal_state.find(state) != terminal_state.end())
            cout << "valid\n";
        else
            cout << "invalid\n";

        cin >> state;
    }
}