#include <iostream>

using namespace std;

void quicksort(int *numbers, int leftEdge, int rightEdge) {
    int pivot = numbers[leftEdge + rand() % (rightEdge - leftEdge)];
    int leftIndicator = leftEdge;
    int rightIndicator = rightEdge;
    while (leftIndicator <= rightIndicator) {
        while (numbers[leftIndicator] < pivot) {
            leftIndicator++;
        }
        while (numbers[rightIndicator] > pivot) {
            rightIndicator--;
        }
        if (leftIndicator <= rightIndicator) {
            swap(numbers[leftIndicator], numbers[rightIndicator]);
            leftIndicator++;
            rightIndicator--;
        }
    }
    if (leftEdge < rightIndicator) quicksort(numbers, leftEdge, rightIndicator);
    if (rightEdge > leftIndicator) quicksort(numbers, leftIndicator, rightEdge);
}


int main() {
    //freopen("sort.in", "r", stdin);
    //freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    quicksort(numbers, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
}