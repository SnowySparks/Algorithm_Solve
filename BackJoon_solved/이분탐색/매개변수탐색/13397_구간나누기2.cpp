#include <iostream>
#include <algorithm>
using namespace std;
int inp[5000];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //매개변수 -> 이번엔 최대 - 최소크기를 기준으로 나눔
    int n, m; cin >> n >> m;
    for (int i = 0 ; i < n ; ++i) cin >> inp[i];
    int minval, maxval, idx;
    int l = 0, r = *max_element(inp,inp+n);
    int ans = r;
    while (l < r) {
        int mid = (l+r) >> 1;
        int cnt = 1; //무조건 1개이상 구간틀
        minval = inp[0]; maxval=inp[0];

        for (int i = 1 ; i < n; ++i) {
            minval = min(minval, inp[i]);
            maxval = max(maxval, inp[i]);
            //넘어선 경우 이건 그룹화 불가능하니 나누고 해당 값을 기준으로 다시 탐색
            if (maxval - minval > mid) {
                ++cnt;
                minval = inp[i];
                maxval = inp[i];
            }
        }
        //m개이하면 답 갱신
        if (cnt <= m) {
            ans = min(ans, mid);
            r = mid;
        }
        //아니면 무조건 최대 최소값 크기 늘려야 함
        else l = mid+1;
    }
    cout << ans;
    return 0;
}

// l : mid+1, r - mid 인 경우 l <= r 
// l : mid+1, r = mid 인 경우 l < r 
// 경우 주의 하기