#include <bits/stdc++.h>

int max_size = 1000000;

using namespace std;

void decrease_key(vector <pair <long long, long long> > &numbers, long long n, long long key) {
    numbers[n].first = key;
    while (n > 1 && numbers[n / 2].first > numbers[n].first) {
        swap(numbers[n], numbers[n / 2]);
        n = n / 2;
    }
}

void push(vector <pair <long long, long long> > &numbers, long long &n, long long key) {
    decrease_key(numbers, n, key);
}

void heapify(vector <pair <long long, long long> > &numbers, int n, int err) {
    int left_child = 2 * err;
    int right_child = 2 * err + 1;
    int smallest = err;
    if (left_child <= n && numbers[left_child].first < numbers[smallest].first)
        smallest = left_child;
    if (right_child <= n && numbers[right_child].first < numbers[smallest].first)
        smallest = right_child;
    if (smallest != err) {
        swap(numbers[smallest], numbers[err]);
        heapify(numbers, n, smallest);
    }
}


void extract_min(vector <pair <long long, long long > > &numbers, long long &n) {
    if (n < 1) {
        cout << "*" << "\n";
        return;
    } else {
        cout << numbers[1].first << "\n";
        numbers[1] = numbers[n];
        n--;
        heapify(numbers, n, 1);
    }
}


int main() {
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);
    vector < pair <long long, long long> > numbers(max_size);
    numbers[0] = make_pair(LONG_LONG_MIN, 0);
    long long n = 0, x, y, counter = 1;
    string command;
    while (cin >> command) {
        if (command == "push") {
            n++;
            cin >> x;
            numbers[n].second = counter;
            push(numbers, n, x);
        } else if (command == "extract-min") {
            extract_min(numbers, n);
        } else if (command == "decrease-key") {
            cin >> x >> y;
            int index = 0;
            while (numbers[index].second != x && index <= n)
                index++;
            if (numbers[index].second == x) {
                decrease_key(numbers, index, y);
            }
        }
        counter++;
    }
}