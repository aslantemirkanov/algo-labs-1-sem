#include <iostream>

using namespace std;

void mergeSort(int *arr, int left, int right) {
    if (left == right) return;
    int pivot = (left + right) / 2;
    mergeSort(arr, left, pivot);
    mergeSort(arr, pivot + 1, right);
    int i = left;
    int j = pivot + 1;
    int index = 0;
    int tmp[right - left + 1];
    for (int index = 0; index < right - left + 1; index++) {
        if ((i <= pivot) && (j <= right)) {
            if (arr[i] <= arr[j]) {
                tmp[index] = arr[i];
                i++;
            } else {
                tmp[index] = arr[j];
                j++;
            }
        } else if (i <= pivot) {
            tmp[index] = arr[i];
            i++;
        } else if (j <= right) {
            tmp[index] = arr[j];
            j++;
        }
    }

    for (index = 0; index < (right - left + 1); index++) {
        arr[left + index] = tmp[index];
    }
}

int main() {
    //freopen("sort.in", "r", stdin);
    //freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
