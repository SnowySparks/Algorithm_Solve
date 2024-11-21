#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<int, int> t;
int N, S;
int dt[21];
int ans =0;
void ls(int loc, int sum) {
    if (loc == N/2) {
        t[sum]++; return;}
    ls(loc+1, sum+dt[loc]);
    ls(loc+1, sum);
}

void rs(int loc, int sum) {
    if (loc == N) {
        ans += t[S - sum]; return;
    }
    rs(loc+1, sum+dt[loc]);
    rs(loc+1, sum);
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> S;
    for (int i = 0 ; i < N; i++) cin >> dt[i];
    ls(0,0); rs(N/2, 0);
    if (S == 0) cout << ans-1;
    else cout << ans;
    return 0;
}