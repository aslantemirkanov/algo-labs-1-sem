#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("turtle.in", "r", stdin);
    freopen("turtle.out", "w", stdout);
    long long w, h;
    cin >> h >> w;
    long long mas[h][w], mas_sum[h][w];
    for (long long i = 0; i < h; i++) {
        for (long long j = 0; j < w; j++) {
            cin >> mas[i][j];
        }
    }
    mas_sum[h - 1][0] = mas[h - 1][0];
    for (long long i = h - 2; i >= 0; i--) {
        mas_sum[i][0] = mas_sum[i + 1][0] + mas[i][0];
    }
    for (long long i = 1; i < w; i++) {
        mas_sum[h - 1][i] = mas_sum[h - 1][i - 1] + mas[h - 1][i];
    }
    for (long long i = h - 2; i >= 0; i--) {
        for (long long j = 1; j < w; j++) {
            mas_sum[i][j] = mas[i][j] + max(mas_sum[i + 1][j], mas_sum[i][j - 1]);
        }
    }
    cout << mas_sum[0][w - 1];
    return 0;
}
