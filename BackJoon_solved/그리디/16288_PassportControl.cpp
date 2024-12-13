#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
int arr[100];
int cnt[100];
vector<int> q;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    reverse(arr, arr + n);

    for (int i = 0; i < n; ++i) {
        if (q.empty() || q.back() < arr[i]) {
            q.push_back(arr[i]);
            cnt[i] = (int) q.size();
        }
        else {
            auto it = lower_bound(q.begin(), q.end(), arr[i]);
            cnt[i] = it - q.begin() + 1;
            *it = arr[i];
        }
    }
    int minAscSubSequence = *max_element(cnt, cnt +n);
    cout << (minAscSubSequence > k ? "NO" : "YES"); 

    return 0;
}

// 원리
// 결국은 이 문제는 오름차순 그룹 갯수가 가장 적은 개수가 몇 개인가? (오름차순인 부분 수열의 개수의 최소값)
// -> 각 여권 심사 청구는 결국 오름차순 순서대로 번호를 받기 때문

// 여러가지 방법 존재
// 1. 최장 감소 수열 길이 계산 -> 오름차순인 부분 수열의 개수의 최소값 === 최장 감소 수열 길이
// 2. monotone stack -> https://justicehui.github.io/icpc/2019/01/12/BOJ16288/
// 3. 모든 여행창구에 Queue를 두고, Queue가 빈 자리 혹은 해당 Queue의 맨 뒤 수보다 더 큰 경우에만 뒤로 push,
//  -> 모든 창구 돌아도 안되는 경우 해당 배열은 안되는 것