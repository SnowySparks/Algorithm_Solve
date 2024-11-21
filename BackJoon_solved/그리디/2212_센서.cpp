#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10001];
int btw[10001];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;

    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr+n);
    for (int i = 0; i < n-1; ++i) btw[i] = arr[i+1]-arr[i];
    sort( btw, btw+(n-1));

    int ans = 0;
    for (int i = 0; i < n-k; ++i) {
        ans += btw[i];
    }
    cout << ans;
    return 0;
}

// 원리
// 1. k 개 집중국을 설치하면 k-1 사이 공간이 생김. 가능한 이 k-1 공간을 크게 만드는 것이 중요.
// 따라서 각 N개의 좌표를 먼저 정렬하고, 해당 좌표 사이의 공간을 계산 (N-1)개의 공간이 생김
// 그 공간을 또 오름차순으로 배열. k-1공간을 최대로 두기 위해서. 작은것부터 총 (N-1) - (K-1) 개의 사이공간을 더하면 답이됨

// 2, 1번이 통하는 이유
// k개 집중국을 설치하는데 ,각 집중국은 최소 1개 이상을 무조건 포함하도록 둘 것임.
// 또 이 문제에선 집중국의 개수와 상관없이 집중국이 처리해야하는 거리의 총합을 최소로 하는 것이 중요.
// 따라서 가능한 집중국을 최대한 많이 설치해야 집중국이 처리해야 하는 거리가 작아지므로 많이 설치해야 하는 게 자명함.
// 만약 N <= K 이면 각 센서 좌표마다 설치하면 되니 무조건 0이 답이 됨
// N > K이 되는 경우가 문제 : -> 그럼 가능한 어느 집중국이 2개 이상센서를 포함하도록 해야 하는데, 
// 가능한 이 거리가 작아야 유리함. 해당 거리는 각 센서마다의 거리이며, 바로 주변의 거리만 살피면 됨 (N-1개인 이유)
