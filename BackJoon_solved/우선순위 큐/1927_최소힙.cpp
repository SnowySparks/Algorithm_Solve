#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int dp[100001];


int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N,n;
    cin >> N;
    priority_queue<int,vector<int>,greater<int> > q;

    while (N--) {
        cin >> n;
        if (n!=0) {
            q.push(n);
        }
        else {
            if (q.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
    }

    return 0;

    

}