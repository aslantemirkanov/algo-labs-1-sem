#include <bits/stdc++.h>

using namespace std;

void KthStatistic(vector<long> &numbers, long left, long right, long index) {
    long leftIndicator=left;
    long rightIndicator=right;
    long pivot=numbers[(left+right)/2];
    while(leftIndicator<=rightIndicator){
        while (numbers[leftIndicator]<pivot) leftIndicator++;
        while (numbers[rightIndicator]>pivot) rightIndicator--;
        if (leftIndicator<=rightIndicator){
            swap(numbers[rightIndicator],numbers[leftIndicator]);
            rightIndicator--;
            leftIndicator++;
        }
    }
    if (index>rightIndicator && right>leftIndicator) KthStatistic(numbers, leftIndicator, right, index);
    if (index<leftIndicator && left<rightIndicator) KthStatistic(numbers, left, rightIndicator, index);
}



int main() {
   // freopen("kth.in", "r", stdin);
   // freopen("kth.out", "w", stdout);
    long n, k, A, B, C;
    cin >> n >> k;
    vector <long> numbers(n);
    cin >> A >> B >> C >> numbers[0] >> numbers[1];
    for (long i = 2; i < n; i++) {
        numbers[i] = A * numbers[i - 2] + B * numbers[i - 1] + C;
    }
    KthStatistic(numbers,0,n-1, k-1);
    cout<<numbers[k-1];
}