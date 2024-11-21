#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    int c;
    while (b!=0) {
        c=a%b;
        a=b;
        b=c;
    } return a;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin>> arr[i];
    if ( N == 1) {cout << arr[0]; return 0;}
    sort(arr.begin(), arr.end());
    vector<int> lst;
    for (int i = 0; i < N-1; i++) {
        lst.push_back(arr[i+1] - arr[i]);
    }
    sort(lst.begin(), lst.end());
    int temp = lst[0];
    for (int i = 1 ; i < lst.size() ; i++) {
        temp = gcd(temp, lst[i]);
    }
    cout <<temp; return 0;
}