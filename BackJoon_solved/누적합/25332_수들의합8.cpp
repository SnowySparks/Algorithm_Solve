#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
using ll = long long;
int N;
const int MAX_N = 2e5 + 1;
int arr[MAX_N];
unordered_map<ll, ll> prefix_cnt;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N; // N 입력
    int tmp;
    //배열 A의 등록
    for (int i = 1; i <= N; ++i) cin >> arr[i];

    // 배열 B의 값을 읽어 A배열에 빼기
    for (int i = 1; i <= N; ++i) {
        cin >> tmp;
        arr[i]-=tmp;
    }

    ll sum = 0; // prefix 전용
    ll ans = 0; // 카운팅
    for (int i = 1; i <= N; ++i) {
        sum += arr[i];
        if (sum == 0) ++ans; // S_i ( = A_i - B_i) 값 자체가 0인 경우
        if (prefix_cnt.find(sum) != prefix_cnt.end()) ans += prefix_cnt[sum]; // S_j ( = A_j - B_j) == sum이 있는지
        prefix_cnt[sum]++;
    }
    cout << ans;
    return 0;
}