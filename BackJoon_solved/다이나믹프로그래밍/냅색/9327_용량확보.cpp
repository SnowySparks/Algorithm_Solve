#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;
#define f(a, b, c) for(int a=b; a<c; ++a)
typedef long long ll;
const int N = 1e2 + 1;
bitset<200'001> dp;
int n, e, total;
int s[N];

void init() {
    total = 0;
    cin >> n >> e;
    e = (e + 1) >> 1;
    f(i, 1, n+1) {
        cin >> s[i];
        total += s[i];
    }
    dp.reset();
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int T; cin >> T;
    while (T--)
    {
        init();

        if (total < e) {
            //전부 다 바꿔도 안됨
            cout << "FULL\n";
            continue;
        }

        dp[0] = 1;

        for (int idx = 1; idx <= n; ++idx) {
            dp |= ( dp << s[idx]);
        }
        int ans = 0;
        for (int loc = e; loc <= total; ++loc) {
            if (dp[loc] == 1) {
                ans = loc;
                break;
            }
        }
        cout << ans << '\n';
    }
    

    return 0;
}