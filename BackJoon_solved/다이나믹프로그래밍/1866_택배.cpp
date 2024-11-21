#include <iostream>
#include <algorithm>
using namespace std;

int dp[3001]; // 1 ~ i 까지 배달 최소 비용
int presum[3001]; // 1 ~ i 까지 누적합
int arr[3001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, t, h; cin >> n; // n : 배송갯수, t : 단위길이당 트럭비용, h : 헬기비용
    for (int i = 1; i <= n; ++i) cin >> arr[i];//입력
    cin >> t >> h;
    sort(arr+1, arr+1+n); //정렬
    for (int i = 1; i <= n; ++i) presum[i] = presum[i-1] + arr[i]; //누적합

    //헬기는 가능하면 연속된 구간 안 중 "가능한 중앙" 위치에 가는 것이 제일 베스트
    // 헬기 중심 주변으로 가야하는 거리들 총 합 일일이 계산하면 시간오버
    // 담당구간과 누적합을 이용해서 한번만에 계산하기

    for (int idx = 1; idx <= n; ++ idx) {
        //일단 idx에 위치에 트럭으로 바로 보내기
        dp[idx] = dp[idx -1] + arr[idx] * t;

        //그다음 어디 부분에 헬기를 둘 지 판단, j-1 까지는 처리 되었다고 생각하기!
        for (int j = idx; j >= 1; --j) {
            int mid = (idx + j) >> 1; //헬기 가장 두기 좋은 곳 

            //왼쪽 단 누적가중치. mid쪽에 가까울수록 증가 -> 누적합을 이용
            int left = arr[mid] * (mid - j + 1) - ( presum[mid] - presum[j-1]);

            //오른쪽 단 누적가중치. mid쪽에 가까울수록 증가 -> 누적합을 이용
            int right = presum[idx] - presum[mid-1] - arr[mid]*(idx - mid + 1);
            dp[idx] = min(dp[idx], (left +right)*t + h + dp[j-1]);
        }
    }
    cout << dp[n];
    return 0;
}