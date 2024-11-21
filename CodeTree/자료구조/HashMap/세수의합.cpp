// 백준 3151과 동일한 문제
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int arr[1000], n, k;
int ans = 0;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    unordered_map<int, int> cnt;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    sort(arr, arr+n);

    for (int i = 0; i < n -2; ++i) {
        int l = i+1, r = n-1;
        while (l < r)
        {
            int res = arr[i] + arr[l] + arr[r];
            if (res == k) {
                if (arr[l] == arr[r]) ans += (r - l);
                else ans += cnt[arr[r]];
            }
            if (res <= k) l++;
            else r--;
        }
    }
    cout<<ans;

    return 0;
}