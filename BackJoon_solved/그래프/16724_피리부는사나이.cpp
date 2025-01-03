#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>
#define CYCLE -1
using namespace std;
unordered_map<char,int> charToInt;
#define f(a, b, c) for(int a = b; a <c; ++a)
int mv[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

int N, M;
int graph[1000][1000];
char inp[1010];
int v[1000][1000];
// int p[1000000];
int ans = 0;

void dfs(int r, int c, int idx) {
    while(true) {
        if (v[r][c]) {
            if (v[r][c] == idx) {
                ++ans;
            }
            return;
        }
        else {
            v[r][c] = idx;
            int nr = mv[graph[r][c]][0] + r;
            int nc = mv[graph[r][c]][1] + c;
            r = nr;
            c = nc;
        }
    }
}



int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    charToInt['D'] = 0;
    charToInt['L'] = 1;
    charToInt['R'] = 2;
    charToInt['U'] = 3;

    cin >> N >> M;
    f(i, 0, N) {
        cin >> inp;
        f(j, 0, M) graph[i][j] = charToInt[inp[j]];
    }
    int idx = 0;
    
    f(i, 0, N) {
        f(j, 0, M) if (!v[i][j]) {
            dfs(i, j, ++idx);
        }
    }

    cout << ans;
    return 0;
}