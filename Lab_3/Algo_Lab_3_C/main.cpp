#include <bits/stdc++.h>

using namespace std;

void radix_sort(string *words, int n, int m, int k) {
    int count_arr[26];
    for (int i = 1; i <= k; i++) {
        string tmp_rez[n];
        for (int j = 0; j < 26; j++) {
            count_arr[j] = 0;
        }
        for (int j = 0; j < n; j++) {
            count_arr[(int) (words[j][m - i]) - 97]++;
        }
        for (int j = 1; j < 26; j++) {
            count_arr[j] += count_arr[j - 1];
        }
        for (int x = n - 1; x >= 0; x--) {
            tmp_rez[count_arr[(int) (words[x][m - i]) - 97] - 1] = words[x];
            count_arr[(int) (words[x][m - i]) - 97]--;
        }
        for (int x = 0; x < n; x++) {
            words[x] = tmp_rez[x];
        }
    }
}

int main() {
    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    string words[n];
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    radix_sort(words, n, m, k);
    for (int i = 0; i < n; i++) {
        cout << words[i] << "\n";
    }
}