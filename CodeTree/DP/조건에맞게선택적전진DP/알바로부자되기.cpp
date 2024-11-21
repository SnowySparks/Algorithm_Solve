//https://www.codetree.ai/missions/2/problems/being-rich-by-working-part-time/description
#include <iostream>
#include <algorithm>
#include <cstring>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
struct info {
    int fr, to, cost;
};
int n;
int dp[1000];
info arr[1000];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 0, n) {
        cin >> arr[i].fr >> arr[i].to >> arr[i].cost;
    }

    sort(arr, arr+n, [](const info &a, const info &b) {
        return a.fr < b.fr;
    });
    f(i, 0, n) dp[i] = arr[i].cost;
    f(i, 1, n) {
        for(int j = 0; j < i; ++j) {
            if (arr[j].to < arr[i].fr) {
                dp[i] = max(dp[i], dp[j] + arr[i].cost);
            }
        }
    }
    cout << *max_element(dp, dp+n);
    // f(i, 0, n) cout << dp[i] <<' ';
    return 0;
}