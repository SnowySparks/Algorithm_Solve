#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int n, m;
long long a[100000];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    for (int i = 0 ; i < N ; i++) {
        cin >> a[i];
    }
    sort(a,a+N);
    int l = 0 , r= N-1;
    long long var, al = a[l], ar= a[r], res= al+ar;
    while (l < r) {
        var = a[l] + a[r];
        if (abs(var) < abs(res)) {
            res = var;
            al = a[l]; ar = a[r];
        }
        if (var <= 0) l++;
        else r--;
    }
    cout <<al << ' ' << ar; return 0;
}