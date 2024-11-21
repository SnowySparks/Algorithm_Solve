#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using pii = pair<int,int>;
int n;
const int inf = 1e9+1;
priority_queue<int,vector<int>, greater<> > q;
int ans = 0, node;
typedef struct _io {
    int fr, to, idx;
    bool operator<(const struct _io &a) const {
        if (fr == a.fr ) return to < a.to;
        return fr < a.fr;
    }
    bool operator>(const struct _io &a) const {
        if (fr == a.fr ) return to > a.to;
        return fr > a.fr;
    }
} io;

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    cin >> n;
    vector<io> arr(n+1);
    for (int i = 0 ; i < n ; i ++) {cin >> arr[i].fr >> arr[i].to; arr[i].idx = i+1;}
    arr[n] = {inf,inf};
    sort(arr.begin(),arr.end());
    for (int i = 0 ; i <= n ; i++) {
        q.push(arr[i].to);
        while (!q.empty() && q.top() < arr[i].fr) q.pop();
        if (ans < (int)q.size()) {
            ans = (int)q.size();
            node =arr[i].fr;
        }
    }
    cout << ans <<'\n';
    for (int i = 0 ; i < n ; i ++) {
        if (arr[i].fr <= node && arr[i].to >=node) cout << arr[i].idx <<' ';
    }
    return 0;

}