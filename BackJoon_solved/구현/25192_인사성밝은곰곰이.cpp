#include <iostream>
#include <set>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    set<string> dt;
    int ans = 0;
    while(N--) {
        string cmd;
        cin >> cmd;
        if (cmd == "ENTER") dt.clear();
        else if (dt.find(cmd)!=dt.end()) continue;
        else {
            ans++;
            dt.insert(cmd);
        }
    }
    cout << ans;
}