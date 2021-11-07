#include <iostream>

using namespace std;

int bin_search_min_index(int key, int numbers[], int n) {
    int left = -1;
    int right = n;
    while ((right - 1) > left) {
        int middle = (right + left) / 2;
        if (numbers[middle] < key)
            left = middle;
        else right = middle;
    }
    if (numbers[right] == key)
        return right + 1;
    else return -1;
}

int bin_search_max_index(int key, int numbers[], int n) {
    int left = -1;
    int right = n;
    while ((right - 1) > left) {
        int middle = (right + left) / 2;
        if (numbers[middle] <= key)
            left = middle;
        else right = middle;
    }
    if (numbers[left] == key)
        return left + 1;
    else return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
    int n, m;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    cin >> m;
    int key;
    for (int i = 0; i < m; i++) {
        cin >> key;
        cout << bin_search_min_index(key, numbers, n) << " ";
        cout << bin_search_max_index(key, numbers, n) << "\n";
    }
    return 0;
}