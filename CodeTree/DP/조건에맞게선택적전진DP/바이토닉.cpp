//https://www.codetree.ai/missions/2/problems/increasing-and-descreasing-subsequence/description
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;

int arr[1002];
int l[1002];
int r[1002];
int n;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 0, n) cin >> arr[i];
    vector<int> tmp;
    f(i, 0, n) {
        if (tmp.empty() || tmp.back() < arr[i] ) {
            tmp.push_back(arr[i]);
            l[i] = (int) tmp.size();
        }
        else {
            auto it = lower_bound(tmp.begin(), tmp.end(), arr[i]);
            l[i] = it - tmp.begin() + 1;
            *it = arr[i];
        }
    }
    tmp.clear();

    for(int i = n-1; i>=0; --i) {
        if (tmp.empty() || tmp.back() < arr[i] ) {
            tmp.push_back(arr[i]);
            r[i] = (int) tmp.size();
        }
        else {
            auto it = lower_bound(tmp.begin(), tmp.end(), arr[i]);
            r[i] = it - tmp.begin() + 1;
            *it = arr[i];
        }
    }
    int ans = 0;
    f(i, 0, n) ans = max(ans, l[i] + r[i] - 1);
    cout << ans;


}