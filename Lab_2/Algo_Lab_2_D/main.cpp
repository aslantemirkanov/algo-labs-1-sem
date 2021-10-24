#include <iostream>
using namespace std;

int main()
{
    freopen("antiqs.in", "r", stdin);
    freopen("antiqs.out", "w", stdout);
    long long n;
    cin >> n;
    long long arr[n];
    for(long long i = 0; i < n; i++)
        arr[i] = i + 1;
    for(long long i = 0; i < n; i++)
    swap(arr[i],arr[i/2]);
    for(long long i = 0; i < n; i++)
            cout << arr[i] << " ";
}