#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
const int inf = 
int dr[] {0,0,1,-1}, dc[] {1, -1, 0, 0};
int p[3000][3000];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int k; cin >> k;
    while(k--) {
        int ri, ci, d; cin >> ri >> ci >> d;
        ri--; ci--;
        for (int r = ri - d ; r <= ri + d ; r++) {
            int c1 = ci - ( d - abs(ri - r)), c2 = ci + ( d - abs(ri - r));
            if (r >= 0 && r < n) {
                if (0 <= c1 && c1 < m) p[r][c1] = inf;
                if (0 <= c2 && c2 < m) p[r][c2] = inf;
            }
        }
    }
    queue< pair<int ,int> > q;
    q.push({0,0}); p[0][0] = 1;
    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >=0 && nc < m && p[nr][nc]==0) {
                p[nr][nc] = p[r][c]+1;
                q.push({nr,nc});
            }
        }
        
    }

    if (p[n-1][m-1] >0) cout << "YES\n" << p[n-1][m-1]-1;
    else cout << "NO";

    
    return 0;
}