#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("sortland.in", "r", stdin);
    freopen("sortland.out", "w", stdout);
    int n;
    cin >> n;
    double mas[n], ind[n];
    long long i, j, k;
    for (i = 0; i < n; i++) {
        cin >> mas[i];
        ind[i] = i;
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (mas[i] > mas[j]) {
                swap(mas[i], mas[j]);
                swap(ind[i], ind[j]);
            }
        }
    }
    cout << ind[0] + 1 << " " << ind[(n - 1) / 2] + 1 << " " << ind[n - 1] + 1;
}
