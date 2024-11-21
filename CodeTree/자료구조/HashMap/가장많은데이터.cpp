#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    unordered_map<string, int> mp;
    int n; cin >> n;
    string cmd;
    while (n--)
    {
        cin >> cmd;
        mp[cmd]++;
    }

    int ans = 0;
    for (pair<string, int> it : mp) {
        ans = max(ans, it.second);
    }
    cout << ans;
    return 0;
}