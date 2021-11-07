#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("smallsort.in");
    ofstream fout("smallsort.out");
    long long n;
    fin >> n;
    long long mas[n];
    long long i, j;
    for (i = 0; i < n; i++) {
        fin >> mas[i];
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (mas[i] > mas[j]) swap(mas[i], mas[j]);
        }
    }
    for (i = 0; i < n; i++) fout << mas[i] << " ";
    fout << "\n";
    fin.close();
    fout.close();
    return 0;
}
