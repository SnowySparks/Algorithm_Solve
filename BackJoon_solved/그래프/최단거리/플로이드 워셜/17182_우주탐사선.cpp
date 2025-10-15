#include <iostream>
#include <cstring>
#include <algorithm>
#define f(a, b, c) for(int a = b; a < c; ++a)
using namespace std;
const int inf = 1e9 + 7;
int N, K;
int arr[10][10];
int dp[10][1 << 10];

int dfs(int loc, int state) {
    if (state == ( (1 << N) - 1)) return 0;
    int &res = dp[loc][state];
    if (res != -1) return res;

    res = inf;

    f(idx, 0, N) {
        if ((1 << idx) & state) continue;
        res = min(res, dfs(idx, state | (1 << idx)) + arr[loc][idx]);
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    f(i, 0, N) f(j, 0, N) {
        cin >> arr[i][j];
    }

    // 플로이드 워셜
    f(mid, 0, N) {
        f(st, 0, N) {
            f(en, 0, N) {
                arr[st][en] = min(arr[st][en], arr[st][mid] + arr[mid][en]);
            }
        }
    }
    cout << dfs(K, (1 << K));
    return 0;
}