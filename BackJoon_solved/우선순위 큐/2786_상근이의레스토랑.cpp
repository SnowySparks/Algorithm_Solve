#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using ll = long long;
using namespace std;
using pll = pair<ll, ll>;
int n;
const int N = 500001;
pll arr[N];
int minAIdx[N]; // [i : N+1) 구간 내, 가장 작은 A값을 가지는 것
ll diff[N]; // a_i - b_i
const int inf = 1e9 + 7;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i].first >> arr[i].second;
    // B기준 오름차순
    sort(arr+1, arr+1+n, [](const pll &a, const pll &b) {
        return (a.second < b.second);
    });
    minAIdx[n] = n;
    for(int i = n-1; i >= 1; --i) {
        if (arr[i].first < arr[minAIdx[i+1]].first) {
           minAIdx[i] = i;
        }
        else {
            minAIdx[i] = minAIdx[i+1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        diff[i] = arr[i].first - arr[i].second;
    }

    ll preFixB = 0;
    ll minDiff = inf;
    for (int i = 1; i <= n; ++i) {
        preFixB += arr[i].second; //B누적
        minDiff = min(minDiff, diff[i]); // a_i - b_i 중 최소값
        int minALoc = minAIdx[i];
        cout << min((preFixB + minDiff), (preFixB-arr[i].second + arr[minALoc].first)) << '\n';
    }
    return 0;
}