#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define f(a, b, c) for(int a=b; a<c; ++a)

int n, m;
int ans = 0;
char str[5004];
vector<pair<int, char> > gh[5001];
int lcs[5001][5001];

int fd = 0;

void dfs(int node, int pnode, int level) {
    // ++fd;
    for (pair<int, char> dt : gh[node]) {
        if (dt.first == pnode) continue;

        for (int i = 1; i <= m; ++i ) {
            if (str[i] == dt.second) {
                lcs[i][level] = lcs[i-1][level-1] + 1;
            }
            else {
                lcs[i][level] = max(lcs[i-1][level], lcs[i][level-1]);
            }
            
        }
        ans = max(ans, lcs[m][level]);
        dfs(dt.first, node, level + 1);
    }
    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> (str + 1);
    int n1, n2; char ch;
    f(i, 0, n-1) {
        cin >> n1 >> n2 >> ch;
        gh[n1].push_back({n2, ch});
        gh[n2].push_back({n1, ch});
    }
    dfs(1, -1, 1);
    // cout << fd << '\n';
    cout << ans;
    return 0;
}