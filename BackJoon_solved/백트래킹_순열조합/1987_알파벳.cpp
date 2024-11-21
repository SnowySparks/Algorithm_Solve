#include <iostream>
#include <string>
#include <vector>
#include <set>
#define f(a,b,c) for(int a=b; a<c; a++)
using namespace std;
using pii = pair<int, int>;
pii operator+(const pii &a, const pii &b) { return {a.first + b.first, a.second + b.second}; }

pii mv[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int r,c;
string inp[20];
bool v[26];

int ans = -1;


void dfs(pii loc, int cnt) { //location , path _ alphabets
    ans = max(ans, cnt);
    f(i, 0, 4) {
        pii newloc = loc + mv[i];
        if (newloc.first < 0 || newloc.first >= r || newloc.second < 0 || newloc.second >= c) continue;
        if (!v[inp[newloc.first][newloc.second] - 'A']) {
            v[inp[newloc.first][newloc.second] - 'A'] = true;
            dfs(newloc, cnt + 1);
            v[inp[newloc.first][newloc.second] - 'A'] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> r >> c;
    f(i, 0, r) cin >> inp[i];
    v[inp[0][0] - 'A'] = true;
    dfs({0,0},1);
    cout << ans ;
    return 0;
}