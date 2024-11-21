#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int> &b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int dp[3000001]; // 1 ~ n개 까지 뒀을 때 가장 쌉 이득되는 값
int hdt[3000001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, S; cin >> N >> S;
    int answer = 0;
    vector<pair<int ,int> > dt(N+1);
    int high, cost;
    for (int i = 1; i <=N ; i++) {
        cin >> dt[i].first >> dt[i].second;
    }
    //높이 낮은 순으로 배치하는게 쌉 이득, 같은 높이 = 더 비싼게 앞으로
    sort(dt.begin(), dt.end(),comp);
    for (int i = 1 ; i <= N ; i++) {
        //다음게 S차이높이난다 -> 그냥 바로 두는게 쌉 이득
        if (hdt[i-1] + S<= dt[i].first) {
            hdt[i] = dt[i].first;
            dp[i] = dp[i-1] + dt[i].second;
        }
        //아닌경우, 차이가 S이상 나는 것들 다음 뒤에 둘 것으로 생각되는 것 or 배치안하거나)
        //hdt는 해당 위치까지는 항상 오름차순 유지 -> 바로 S차이 나는 그 부분만 찾으면 됨
        //일일이 찾긴 그러니 그냥 lower_bound 갓 이분탐색 사용
        else {
            dp[i] = dp[i-1]; hdt[i] = hdt[i-1]; //배치 안했다고 가정
            int loc = lower_bound(hdt,hdt+i,dt[i].first-S) - hdt;
            if (hdt[loc]>dt[i].first-S) loc--;// 만약 차이가 S 미만 높이면 인덱스 감소
            if (dp[loc] + dt[i].second > dp[i]) { //두는게 이득이면 업데이트
                dp[i] = dp[loc] + dt[i].second;
                hdt[i] = dt[i].first;
            }
        }
    }
    cout << dp[N];
    return 0;
}