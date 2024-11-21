#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define f(a, b, c) for(int a=b;a<c;++a)
#define fr(a, b, c) for(int a=b;a>=c;--a)
using namespace std;
const int MAXN = 1e5;
using ll = long long;
int n;
ll arr[MAXN + 2];
ll l[MAXN + 2];
ll r[MAXN + 2];
ll lcnt[MAXN+2], rcnt[MAXN+2]; // 왼쪽은 1 ~ i, 오른쪽은 i ~ n 까지 합이 total/4 되는 개수 누적합
ll total = 0, total_h = 0 , total_q = 0; //배열 총합, 1/2, 1/4

vector<int> right_index_q;
vector<int> left_index_q;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    // input & total 경우의 수 
    f(i, 1, n+1) cin >> arr[i];
    f(i, 1, n+1) {
         total += arr[i];
         l[i] = l[i-1] + arr[i];
         r[n+1 - i] = arr[n+1 - i] + r[n+2 - i];
    }

    if (total % 4) {
        // 4개구간 나누고 각각 구간 총합이 서로 같다 == 배열 총 합은 무조건 4배수여야 한다
        cout << 0;
        return 0;
    }
    total_h = total >> 1;
    total_q = total >> 2;

    f(i, 1, n+1) {
        lcnt[i] = lcnt[i-1] + (l[i] == total_q ? 1  : 0);
        
    }

    for (int i = n; i >= 1; --i) {
        rcnt[i] = rcnt[i+1] + (r[i] == total_q ? 1  : 0);
    }

    ll ans = 0;
    f(i, 1, n+1) {
        if (l[i] == total_h) ans += (lcnt[i-1] * rcnt[i+1]);
    }
    cout << ans;
    return 0;
}