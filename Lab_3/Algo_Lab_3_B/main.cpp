#include <bits/stdc++.h>

using namespace std;

void heapify(vector <long long> &numbers, int n, int err) {
    int left_child = 2 * err + 1;
    int right_child = 2 * (err + 1);
    int largest = err;
    if (left_child < n && numbers[left_child] > numbers[largest])
        largest = left_child;
    if (right_child < n && numbers[right_child] > numbers[largest])
        largest = right_child;
    if (largest != err) {
        swap(numbers[largest], numbers[err]);
        heapify(numbers, n, largest);
    }
}

void heap_sort(vector <long long> &numbers, int n) {
    for (int err = n / 2 - 1; err >= 0; err--) {
        heapify(numbers, n, err);
    }
    for (int err = n - 1; err >= 0; err--) {
        swap(numbers[0], numbers[err]);
        heapify(numbers, err, 0);
    }
}

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    vector<long long> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    heap_sort(numbers, n);
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
}