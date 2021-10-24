#include <bits/stdc++.h>


using namespace std;

int main() {
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);
    long long n, i;
    bool flag = 1;
    cin >> n;
    long long arr[n];
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (i = 0; i <= (n / 2 - 1); i++) {
        if (arr[i] > arr[2 * i + 1] && (2 * i + 1) < n) {
            flag = 0;
        }
        if (arr[i] > arr[2 * (i + 1)] && 2 * (i + 1) < n) {
            flag = 0;
        }
    }
    if (flag) cout << "YES";
    else cout << "NO";
}