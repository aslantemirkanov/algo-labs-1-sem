#include <bits/stdc++.h>

using namespace std;

void mergeSort(vector<string> &countries, vector<string> &sportsmen, int leftEdge, int rightEdge) {
    if (leftEdge >= rightEdge) return;
    int pivot = (leftEdge + rightEdge) / 2;
    mergeSort(countries, sportsmen, leftEdge, pivot);
    mergeSort(countries, sportsmen, pivot + 1, rightEdge);
    int firstIndex = leftEdge;
    int secondIndex = pivot + 1;
    vector<string> tmpCountries(rightEdge - leftEdge + 1);
    vector<string> tmpSportsmen(rightEdge - leftEdge + 1);
    for (int index = 0; index < rightEdge - leftEdge + 1; index++) {
        if ((firstIndex <= pivot) && (secondIndex <= rightEdge)) {
            if (countries[firstIndex] <= countries[secondIndex]) {
                tmpCountries[index] = countries[firstIndex];
                tmpSportsmen[index] = sportsmen[firstIndex];
                firstIndex++;
            } else {
                tmpCountries[index] = countries[secondIndex];
                tmpSportsmen[index] = sportsmen[secondIndex];
                secondIndex++;
            }
        } else if (firstIndex <= pivot) {
            tmpCountries[index] = countries[firstIndex];
            tmpSportsmen[index] = sportsmen[firstIndex];
            firstIndex++;
        } else if (secondIndex <= rightEdge) {
            tmpCountries[index] = countries[secondIndex];
            tmpSportsmen[index] = sportsmen[secondIndex];
            secondIndex++;
        }
    }
    for (int index = 0; index < (rightEdge - leftEdge + 1); index++) {
        countries[leftEdge + index] = tmpCountries[index];
        sportsmen[leftEdge + index] = tmpSportsmen[index];
    }
}

int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    int n;
    cin >> n;
    vector<string> countries(n);
    vector<string> sportsmen(n);
    for (int i = 0; i < n; i++) {
        cin >> countries[i] >> sportsmen[i];
    }
    mergeSort(countries, sportsmen, 0, n - 1);
    if (n == 1) {
        cout << "=== " << countries[0] << " ===\n";
        cout << sportsmen[0]<<"\n";
    } else {
        cout << "=== " << countries[0] << " ===\n";
        cout << sportsmen[0]<<"\n";
        for (int i = 1; i < n; i++) {
            if (countries[i - 1] != countries[i]) cout << "=== " << countries[i] << " ===\n";
            cout << sportsmen[i] << "\n";
        }
    }
    return 0;
}
