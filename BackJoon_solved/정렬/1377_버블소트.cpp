#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int,int>;
int n;
pii lst[500000];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        cin >> lst[i].first;
        lst[i].second = i;
    }
    sort(lst,lst+n);
    int ans = 0;
    for (int i = 0 ; i < n; i ++) {
        ans = max(ans, lst[i].second - i + 1);
    }
    cout<<ans; return 0;
}