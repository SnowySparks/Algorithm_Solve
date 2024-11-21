#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool visited[100001];

int main(void) {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    int ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int,int>>> q;

    q.push({0,n});
    int nx; 
    visited[n] = true;

    while (!q.empty()) {
        auto c = q.top();
        q.pop();

        if (c.second == k) {
            ans = c.first;
            break;
        }

        for (int d = 0; d < 3; d++) {
            nx =0;
            if (d==0) {
                nx = c.second*2;
            }
            else if (d==1) {
                nx = c.second +1;
            }
            else {
                nx = c.second-1;
            }

        if (nx <0 || nx > 100000) continue;
        if (visited[nx]) continue;
        if (d == 0) {
            q.push({c.first+1,nx});
            visited[nx] = true;
        }
        else {
            q.push({c.first+1,nx});
            visited[nx] = true;
        }
        }
    }

    cout << ans;
    return 0;
}