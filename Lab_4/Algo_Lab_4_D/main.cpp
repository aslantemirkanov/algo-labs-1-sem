#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    string command;
    vector <int> stack(100);
    for (int i = 0; i < 100; i++)stack[i] = 0;
    int right_edge = 0;
    getline(cin, command);
    for (int i = 0; i < command.length(); i++) {
        if (command[i] == '+') {
            right_edge--;
            stack[right_edge - 1] = stack[right_edge] + stack[right_edge - 1];
        } else if (command[i] == '-') {
            right_edge--;
            stack[right_edge - 1] = stack[right_edge - 1] - stack[right_edge];
        } else if (command[i] == '*') {
            right_edge--;
            stack[right_edge - 1] = stack[right_edge] * stack[right_edge - 1];
        } else if (command[i] != ' ') {
            stack[right_edge++] = command[i] - '0';
        }
    }
    cout << stack[0];
    return 0;
}