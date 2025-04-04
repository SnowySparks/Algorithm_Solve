#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int arr[200000];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    
    // 홀수
    int midIdx = n / 2;
    if (n & 1) {
        arr[midIdx] = n;
        for (int i = 1, tmp = n-1; i <= midIdx; ++i) {
            arr[midIdx-i] = tmp--;
            arr[midIdx+i] = tmp--;
        }
    }
    else {
        arr[midIdx] = n;
        arr[midIdx-1] = n-1;
        for (int i = 1, tmp = n - 2; i <= midIdx - 1; ++i) {
            arr[midIdx-1-i] = tmp--;
            arr[midIdx+i] = tmp--;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << arr[i] <<' ';
    }
    return 0;
}