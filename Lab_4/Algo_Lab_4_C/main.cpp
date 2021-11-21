#include <iostream>
#include <vector>

using namespace std;

int main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);*/
    string brackets;
    while (cin >> brackets) {
        int flag = 1;
        vector <char> stack(1);
        int right_edge = 0;
        for (int i = 0; i < brackets.length(); i++) {
            if (brackets[i] == '(' || brackets[i] == '[') {
                stack[right_edge++] = brackets[i];
            } else if (brackets[i] == ')') {
                if (right_edge < 1) {
                    flag = 0;
                    break;
                } else {
                    if (stack[right_edge - 1] != '(') {
                        flag = 0;
                        break;
                    } else {
                        right_edge--;
                    }
                }
            } else if (brackets[i] == ']') {
                if (right_edge < 1) {
                    flag = 0;
                    break;
                } else {
                    if (stack[right_edge - 1] != '[') {
                        flag = 0;
                        break;
                    } else {
                        right_edge--;
                    }
                }
            }
        }
        if (flag && right_edge == 0)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}