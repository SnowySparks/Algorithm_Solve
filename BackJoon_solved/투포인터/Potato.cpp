#include <iostream>
#include <algorithm>
using namespace std;

int arr[200000];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr,arr+n);

    int m = 0, mx = 0;
    int half = n/2;
    for (int i = 0 ; i < n/2 ; i++) m += arr[i];
    for (int i = n ; i >= (n/2);i--) mx += arr[i];
    cout << m << ' ' << mx;
    return 0;
}