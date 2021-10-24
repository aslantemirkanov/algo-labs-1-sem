#include <iostream>

using namespace std;

long long inversionCount=0;

void mergeSort(long long *arr, long long left, long long right) {
    if (left == right) return;
    long long pivot = (left + right) / 2;
    mergeSort(arr, left, pivot);
    mergeSort(arr, pivot + 1, right);
    long long i = left;
    long long j = pivot + 1;
    long long index = 0;
    long long tmp[right - left + 1];
    for (long long index = 0; index < right - left + 1; index++) {
        if ((i <= pivot) && (j <= right)) {
            if (arr[i] <= arr[j]) {
                tmp[index] = arr[i];
                i++;
            } else {
                tmp[index] = arr[j];
                j++;
                inversionCount+=pivot-i+1;
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
    freopen("inversions.in", "r", stdin);
    freopen("inversions.out", "w", stdout);
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    cout<<inversionCount;
    return 0;
}
