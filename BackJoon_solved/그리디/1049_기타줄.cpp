#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M; cin >> N >> M;
    int six = 2E7 , one = 2E7;
    for (int i = 0 ; i < M ; i++) {
        int a, b; cin >> a >> b;
        six = min (six, a); one = min(one,b);
    }
    int ans = 2E8;
    for (int i = 0;i<=N/6; i++)  ans = min(ans, i*six + (N - 6*i)*one);
    ans = min(ans, (N/6+1)*six);
    cout << ans; return 0;
}