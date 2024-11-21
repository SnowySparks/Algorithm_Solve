#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    int T; cin >> T;
    priority_queue<long long, vector<long long> , greater<> > q;
    long long ans = 0;
    while(T--) {
        int n; cin >> n;
        ans = 0;
        long long inp;
        for (int i = 0; i < n; i++) {cin >> inp;
        q.push(inp);}

        while(q.size() > 1) {
            long long a = q.top();
            q.pop();
            long long b = q.top();
            q.pop();
            ans+=(a+b);
            q.push(a+b);
        }
        cout << ans << '\n';
        q.pop();
    }
    return 0;
}