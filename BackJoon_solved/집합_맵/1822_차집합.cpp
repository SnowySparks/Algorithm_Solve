#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a,b; cin >> a >> b;
    int inp;
    map<int ,int> dt;
    while (a--) {
        cin >> inp;
        dt[inp] = 1;
    }
    while (b--) {
        cin >> inp;
        if (dt.find(inp) != dt.end()) {
            dt.erase(inp);
        }
    }
    cout << dt.size() << '\n';
    for (auto e : dt) {
        cout << e.first <<' ';
    }
    return 0;
}