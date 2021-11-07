#include <bits/stdc++.h>

using namespace std;

bool ground_touch(double h1, double middle, int n) {
    double previous = h1;
    double current = middle;
    bool touched = 0;
    for (int i = 3; i <= n; i++) {
        double next = 2 * current - previous + 2;
        if (next <= 0) touched = 1;
        previous = current;
        current = next;
    }
    if (touched) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("garland.in", "r", stdin);
    freopen("garland.out", "w", stdout);
    int n;
    double h1;
    cin >> n >> h1;
    double left = 0, right = h1;
    double middle;
    while (true) {
        middle = (left + right) / 2;
        if (middle == right || middle == left) {
            break;
        }
        if (!ground_touch(h1, middle, n)) {
            right = middle;
        } else {
            left = middle;
        }
    }
    double h2 = middle;
    double next;
    for (int i = 3; i <= n; i++) {
        next = 2 * h2 - h1 + 2;
        h1 = h2;
        h2 = next;
    }
    cout << setprecision(2) << fixed << next;
}