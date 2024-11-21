#include <iostream>
#include <string>
#define f(a,b,c) for(int a = b; a < c; a++)
using namespace std;
string dt[50];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    f(i,0,N) cin >> dt[i];
    int len = dt[0].size();
    if (N == 1) {cout << dt[0]; return 0;}
    string same = dt[0];
    f(i,1,N) f(k,0,len) if (same[k] != dt[i][k]) same[k] = '?';
    cout << same; return 0;
}