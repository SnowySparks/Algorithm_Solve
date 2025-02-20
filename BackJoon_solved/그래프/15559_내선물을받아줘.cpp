#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define f(a, b, c) for(int a=b; a<c; ++a)
int n, m;
char ch[1000][1001];
int v[1000][1000];
int charToInt(char ch) {
    switch (ch)
    {
    case 'N':
        return 0;
    case 'W':
        return 1;
    case 'E':
        return 2;
    case 'S':
        return 3;
    }
    return -1;
}
const int mv[4][2] = {{-1, 0},{0, -1},{0, 1},{1, 0}};

int ans = 0;

void dfs(int cr, int cc, int idx) {
    int r = cr, c = cc;
    while (!v[r][c]) {
        v[r][c] = idx;
        auto [dr, dc] = mv[charToInt(ch[r][c])];
        r += dr; c += dc;
    }
    if (v[r][c] == idx) ++ans;
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int idx = 0;
    f(i, 0, n) cin >> ch[i];
    f(i, 0, n) f(j, 0, m) if (!v[i][j]) dfs(i,j,++idx);
    cout << ans;
    return 0;
}