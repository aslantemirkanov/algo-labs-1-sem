#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("stack.in", "r", stdin);
    freopen("stack.out", "w", stdout);
    int m;
    cin >> m;
    vector <int> stack(m);
    int right_edge = 0;
    char command;
    for (int i = 0; i < m; i++) {
        cin >> command;
        if (command == '+') {
            cin >> stack[right_edge];
            right_edge++;
        }
        else if (command == '-') {
            right_edge--;
            cout << stack[right_edge] << "\n";
        }
    }
    return 0;
}