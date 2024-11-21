#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    int n;
    vector<int> ans;
    int temp;
    while (t--) {
        priority_queue<int> under;
        priority_queue<int, vector<int>, greater<int> > up;
        cin >> n;
        for (int i = 1 ; i <= n ; i++) {
            cin >> temp;
            if (under.size() > up.size()) up.push(temp);
            else under.push(temp);

            if (!under.empty() && !up.empty()) {
                if (under.top() > up.top()) {
                    int a = under.top();
                    int b = up.top();
                    under.pop();
                    up.pop();
                    under.push(b);  up.push(a);
                }
            }
            if (i%2) ans.push_back(under.top());
        }
        int cnt = ans.size();
        cout << cnt <<'\n';
        for (int k = 0 ; k < cnt ; k++) {
            cout << ans[k] <<' ';
            if ( (k+1)%10 == 0) cout <<'\n';
            }
        if (cnt%10) cout << '\n';
        ans.clear();
    }
    return 0;
}