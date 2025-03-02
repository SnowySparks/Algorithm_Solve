#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5;
const ll inf = 1e13;
int n, t;

ll c[N+2];
ll d[N+2];
ll tmp[N+2];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n >> t;
    ll l, r, mid, ans;
    while (t--)
    {
        // 환경 셋팅
        l = inf, r = 0;
        for (int i = 1; i <= n-1; ++i) cin >> c[i] >> d[i], l = min(l, c[i]);
        cin >> c[n];
        l = min(l, c[n]);
        for (int i = 1; i <= n; ++i) r = max(r, c[i] + d[i-1] + d[i]);
        while (l <= r) {
            // cout << "----->" << l << ' ' << r << "<-------\n";
            // mid : 세트 수 제한
            mid = (l + r)>>1;
            if (c[1] + d[1] < mid || c[n] + d[n-1] < mid) {
                r = mid - 1;
                continue;
            }
            bool leftCase = false, rightCase = false;
            // 최대한 왼쪽껄 써먹기
            if (c[1] + d[1] >= mid) {
                leftCase = true;
                memcpy(tmp, d, sizeof(ll)*(n+2));
                tmp[1] -= max(0LL, mid - c[1]);
                for (int i = 2; i <= n-1; ++i) {
                    ll needProblem = mid - c[i];
                    if (needProblem <= 0) continue; //이미 충분 -> 스킵
                    needProblem -= tmp[i-1];
                    if (needProblem <= 0) continue; //왼쪽꺼 다씀
                    tmp[i] -= needProblem;
                    if (tmp[i] < 0) {
                        leftCase = false;
                        break;
                    }
                }
                if (c[n] < mid && mid - c[n] > tmp[n-1]) {
                    leftCase = false;
                }
            }
            if (leftCase) {
                ans = mid;
                l = mid + 1;
                continue;
            }
            // 최대한 오른쪽꺼 써먹기
            if (c[n] + d[n-1] >= mid) {
                rightCase = true;
                memcpy(tmp, d, sizeof(ll)*(n+2));
                tmp[n-1] -= max(0LL, mid - c[n]);
                for (int i = n-1; i >= 2; --i) {
                    ll needProblem = mid - c[i];
                    if (needProblem <= 0) continue; //이미 충분 -> 스킵
                    needProblem -= tmp[i];
                    if (needProblem <= 0) continue; //오른쪽꺼 다씀
                    tmp[i-1] -= needProblem;
                    if (tmp[i-1] < 0) {
                        rightCase = false;
                        break;
                    }
                }
                if (c[1] < mid && mid - c[1] > tmp[1]) {
                    rightCase = false;
                }
            }

            if (rightCase) {
                ans = mid;
                l = mid + 1;
                continue;
            }

            r = mid - 1;
        }
        cout << ans << '\n';
    }
    

    return 0;
}