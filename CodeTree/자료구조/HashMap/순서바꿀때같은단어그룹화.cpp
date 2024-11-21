#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
int arr[1000], n, k;
int ans = 0;



int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    unordered_map<string, int> dt;
    int n;

    cin >> n;
    string s;
    f(i, 0, n) {
        cin >> s;
        sort(s.begin(), s.end());
        dt[s]++;
    }
    int ans = 0;
    for (pair<string, int> item : dt) ans = max(ans, item.second);
    cout << ans;
    return 0;
}