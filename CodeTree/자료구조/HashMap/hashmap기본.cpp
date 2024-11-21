#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    unordered_map<int, int> mp;
    int n; cin >> n;
    string cmd; int k, v;
    while (n--)
    {
        cin >> cmd;
        if (cmd =="add") {
            cin >> k >> v;
            mp[k] = v;
        }
        else if (cmd == "find") {
            cin >> k;
            if (mp.find(k)==mp.end()) cout << "None\n";
            else cout << mp[k] << '\n';
        }
        else {
            cin >> k;
            mp.erase(k);
        }
    }
    

    return 0;
}