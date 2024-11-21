#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
using pli = pair<long long, int>; // 소수곱 데이터, 가장 마지막에 곱한 소수의 인덱스 위치
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long arr[100];
    int n, k; cin >> k >> n;
    priority_queue<pli, vector<pli>, greater<pli> > pq;
    for (int i = 0 ; i < k ; ++i) {cin >> arr[i];}
    for (int i = 0 ; i < k ; ++i) pq.push({arr[i], i});
    int cnt = 0;//pop횟수
    long long ans = 0;
    while(true) {
        pli loc = pq.top(); pq.pop();
        ++cnt;
        if (cnt == n) {
            ans = loc.first;
            break;
        }
        //마지막에 뽑은 소수 인덱스 값이 idx 이면 해당 pop한 소수의 곱 값에 ~ idx범위까지 해당하는 소수를 곱하고 넣음
        //항상 마지막에 곱한 소수 인덱스 값을 갱신해야 함을 유의하기
        for (int idx = 0; idx <= loc.second; ++idx) {
            pq.push({loc.first * arr[idx],idx});
        }
    }
    cout << ans;
    return 0;
}