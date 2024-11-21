#include <iostream>
using namespace std;
int arr[50];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,a=0,b; cin >> n;
    for (int i = 0 ; i < n ; i++) cin >> arr[i];
    if (n == 1) {
        cout <<"A"; return 0;
    }
    if (n == 2) {
        if (arr[0] == arr[1]) cout << arr[0];
        else cout << "A"; 
        return 0;
    }
    if (arr[1]-arr[0]) a = (arr[2]-arr[1])/(arr[1]-arr[0]);
    b = arr[1] - arr[0]*a;
    for (int i = 1 ; i < n ; i++) {
        if (arr[i] != (arr[i-1]*a+b)) {
            cout <<"B"; return 0;
        }
    }
    cout << arr[n-1]*a+b; return 0;
}