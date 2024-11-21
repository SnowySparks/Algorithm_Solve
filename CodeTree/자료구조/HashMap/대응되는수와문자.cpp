#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int inf = 1e5+1;
string inp[inf];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    const int inf = 1e5+1;
    unordered_map<string, int> mp;
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> inp[i];
        mp[inp[i]] = i;
    }
    string cmd;

    while (m--)
    {
        cin >> cmd;
        if (cmd[0] >= '0' && cmd[0] <='9') {
            cout << inp[stoi(cmd)] << '\n';
        }
        else {
            cout << mp[cmd] << '\n';
        }
    }
    
    return 0;
}