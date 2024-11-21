#include <iostream>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;

int cnt[100001];
int n, k, b;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k >> b;
    int tmp;
    f(i, 0, b) {
        cin >> tmp;
        cnt[tmp]++;
    }
    f(i, 1, n+1){
         cnt[i] += cnt[i-1];
    }
    int ans = 1e9;
    f(i, k, n+1) ans = min(ans, cnt[i] - cnt[i-k]);
    cout << ans;
    return 0;
}