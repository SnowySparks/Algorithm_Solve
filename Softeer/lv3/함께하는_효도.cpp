#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define f(a, b, c) for(int a=b; a<c; ++a)

int n, m;
int arr[20][20];
bool v[20][20];
int mv[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int loc[3][2]; //좌표
int move[3];
int ans=0;

void dfs(int t, int idx, int total) {
    // cout << t <<' ' << idx <<' '<<total <<'\n';
    ans = max(ans, total);
    if (t == 3) {
        return;
    }

    for (auto &[dr, dc] : mv) {
        int r = loc[idx][0], c = loc[idx][1];
        int nr = r + dr, nc = c + dc;
        if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
        loc[idx][0] = nr; loc[idx][1] = nc;
        if (v[nr][nc]) {
            dfs( t + (idx+1 == m ? 1 : 0), (idx + 1)%m, total);
        }
        else {
            v[nr][nc] = true;
            dfs( t + (idx+1 == m ? 1 : 0), (idx + 1)%m, total + arr[nr][nc]);
            v[nr][nc] = false;
        }
        loc[idx][0] = r; loc[idx][1] = c;
    }
    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    f(i, 0, n) {
        f(j, 0, n) {
            cin >> arr[i][j];
        }
    }
    int tmp = 0;
    f(i, 0, m) {
        cin >> loc[i][0] >> loc[i][1];
        loc[i][0]--; loc[i][1]--;
        v[loc[i][0]][loc[i][1]] = true;
        tmp += arr[loc[i][0]][loc[i][1]];
    }

    dfs(0, 0, tmp);
    cout << ans;



    return 0;
}