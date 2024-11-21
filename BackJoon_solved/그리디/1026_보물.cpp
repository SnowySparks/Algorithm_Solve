#include <iostream>
#include <vector>
#include <algorithm>
#define F(a,b,c) for(int a = b; a <= c ; a++)
using namespace std;

int a[51];
int b[51];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int ans = 0;
    int N; cin >> N;
    F(i,1,N) cin >> a[i];
    F(i,1,N) cin >> b[i];
    sort(a+1,a+1+N);
    sort(b+1,b+1+N,greater<>());
    F(i,1,N) ans+= (a[i]*b[i]);
    cout << ans; return 0;
}
