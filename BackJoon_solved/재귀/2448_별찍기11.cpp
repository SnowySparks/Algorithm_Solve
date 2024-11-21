#include <iostream>
using namespace std;
char p[3072][6144];

void dfs(int r, int c, int n) {
    if (n == 3) {
        p[r][c] = '*';
        p[r+1][c+1] = '*';
        p[r+1][c-1] = '*';
        for (int i = c-2; i <= c+2; i++) {
            p[r+2][i]='*';
        }
        return;
    }

    dfs(r,c,n/2);
    dfs(r+n/2,c-n/2,n/2);
    dfs(r+n/2,c+n/2,n/2);
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n;i++) {
        for (int j = 0; j <2*n; j++) {
            p[i][j]=' ';
        }
    }
    dfs(0,n-1,n);
    for (int i = 0; i < n;i++) {
        for (int j = 0; j <2*n; j++) {
            cout << p[i][j];
        }
        cout <<'\n';
    }
    return 0;
}