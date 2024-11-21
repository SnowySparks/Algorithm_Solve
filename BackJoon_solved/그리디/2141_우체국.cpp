#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int ,int> arr[100001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    long long total_people = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
        total_people += arr[i].second;
    }
    sort(arr, arr+n);
    long long prefix_people = 0;
    int ans = 0;
    for (; ans < n; ++ans) {
        prefix_people += arr[ans].second;
        if (prefix_people >= (total_people/2 + (total_people&1 ? 1 : 0 ))) break;
    }
    cout << arr[ans].first;
    return 0;
}

//sigma ( ai * |x - bi |) ( 1 <= i <= n ) 의 값이 최소가 되는 지점이, 좌표 정렬해서 사람 누적값이 절반 이상되는 그 지점이 우체국 위치
//f(x)= 시그마 p(k) * | x - t(k) | 를 최소로하는 x값 찾기 , 일차함수 or 상수함수이므로 음수에서 양수로 기울기변화하는점 찾기 

//증명 : https://math.stackexchange.com/questions/4410205/minimum-value-of-sum-of-absolute-diferences