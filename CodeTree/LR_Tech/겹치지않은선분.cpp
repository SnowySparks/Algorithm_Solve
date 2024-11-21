// https://www.codetree.ai/missions/8/problems/line-segments-that-do-not-overlap/description
#include <iostream>
#include <cstring>
#include <algorithm>
#define f(a, b, c) for(int a = b; a < c; ++a)
#define pii pair<int ,int>
using namespace std;
const int MAXN = 1e5;
int n;
pii pts[MAXN]; //정렬 : 시작점 오름차순
int l[MAXN], r[MAXN]; 
// l[i] : 0 ~ i 까지 포인트값중 끝점이 최대인 점
// r[i] : n-1 ~ i 까지 포인트값중 끝점이 최소인 점



int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 0, n) cin >> pts[i].first >> pts[i].second;
    sort(pts, pts+n);
    l[0] = pts[0].second;
    r[n-1] = pts[n-1].second;

    for (int i = 1; i < n; ++i) l[i] = max(l[i-1], pts[i].second);
    for (int i = n-2; i >= 0; --i) r[i] = min(r[i+1], pts[i].second);
    int ans = 0;
    f(i, 0, n) {
        // 해당 시작점 기준 포인트에서 l[i] == r[i] 인 경우, 즉 "자기자신" 포인트 값인 경우에만 카운트
        ans += (l[i] == r[i]); 
    }
    cout << ans;
    return 0;
}