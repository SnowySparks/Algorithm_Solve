#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define f(a,b,c) for (int a = b; a < c; a++)

int arr[100][100]; int n;
int dr[] {1,-1,0,0};
int dc[] {0,0,1,-1};
bool v[100][100];

int minv = 10000, maxv = -1, mid;
bool possible(int thr) { //thr --> max-min value, 
    //allow range : i ~ i + thr
    for (int i = minv ; i <= maxv ; i++) {
        if (arr[0][0] < i || arr[0][0] > (i+thr)) continue;
        f(k,0,n) f(j,0,n) {
            if (arr[k][j] >= i && arr[k][j] <= (i + thr)) v[k][j] = false;
            else v[k][j] = true;
        }
        queue<pair<int, int> > q; 
        q.push({0,0}); v[0][0] = true;
        while (!q.empty()) {
            int r = q.front().first, c = q.front().second; q.pop();
            if ( r == n-1 && c == n-1) return true;
            f(p,0,4) {
                int nr = r + dr[p], nc = c + dc[p];
                if (nr >= 0 && nc >= 0 && nr < n && nc < n && !v[nr][nc]) {
                    v[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
    }
    return false;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i,0,n) { 
        f(j,0,n) {
            cin >> arr[i][j];
            maxv = max(maxv,arr[i][j]);
            minv = min(minv,arr[i][j]);
        }
    }
    int ans = 100000;
    int min_ans = 0, max_ans = maxv-minv;

    while (min_ans <= max_ans) {
        int mid = (min_ans + max_ans)/2;
        bool res = possible(mid);
        if (res) {
            ans = mid;
            max_ans = mid-1;
        }
        else {
            min_ans = mid+1;
        }
    }
    cout << ans;
    return 0;
}