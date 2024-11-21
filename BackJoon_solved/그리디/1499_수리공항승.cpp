#include <iostream>
#include <vector>
#include <algorithm>
#define f(a,b,c) for (int a = b; a < c; a++)
using namespace std;
int dt[1000];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, L; cin >> N >> L;
    f(i,0,N) cin >> dt[i];
    sort(dt,dt+N);
    int loc = 0, ans = 1;
    f(i,1,N) {
        if (dt[i] - dt[loc] >=L) {loc = i; ans++;}
    }
    cout << ans;
}