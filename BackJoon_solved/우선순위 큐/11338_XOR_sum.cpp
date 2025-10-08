#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int T; cin >> T;
    int Q, K;
    priority_queue<int, vector<int>, greater<int> > pq;

    while (T--)
    {
        cin >> Q >> K;
        string cmd;

        int xorsum = 0;

        while (!pq.empty()) {
            pq.pop();
        }

        for (int query = 1; query <= Q; ++query) {

            cin >> cmd;

            if (cmd == "insert") {
                int val; cin >> val;

                pq.push(val);
                xorsum ^= val;
                while (pq.size() > K)
                {
                    xorsum ^= pq.top(); pq.pop();
                }
                
            }
            else {
                cout << xorsum << '\n';
            }
        }
    }
    

    return 0;
}