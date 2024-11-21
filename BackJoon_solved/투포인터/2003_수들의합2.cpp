#include <iostream>
#include <vector>
using namespace std;
 
int n, m;
int a[10000];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    cin >> n >> m;
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    int res = 0, sum = 0, s = 0, e = 0;
 
    while (true) {
        if (sum == m) res++;
        if (sum >= m) sum -= a[s++];
        else if (e == n) break;
        else sum += a[e++];
    }
    cout << res;
 
 
 
    return 0;
}
