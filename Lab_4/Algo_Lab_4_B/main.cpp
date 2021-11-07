#include <bits/stdc++.h>

using namespace std;

void push(int *queue, int &tail, int key, int m) {
    queue[tail] = key;
    if (tail == m) {
        tail = 0;
    } else {
        tail++;
    }
}

void pop(int *queue, int &head, int m) {
    cout << queue[head] << "\n";
    if (head == m) {
        head = 0;
    } else {
        head++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
    int m;
    cin >> m;
    char command;
    int number, tail = 0, head = 0;
    int queue[m + 1];
    for (int i = 0; i < m; i++) {
        cin >> command;
        if (command == '+') {
            cin >> number;
            push(queue, tail, number, m);
        } else if (command == '-') {
            pop(queue, head, m);
        }
    }
    return 0;
}