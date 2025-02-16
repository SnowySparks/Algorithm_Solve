#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#define f(a, b, c) for(int a=b; a<c; ++a)
using namespace std;
int n, m;
const int inf = 1e9;
int p[101];
int d[101][101];

map<int, vector<int> > group;

int findp(int node) {
    if (p[node] == node) return node;
    return p[node] = findp(p[node]);
}

bool unite(int a, int b) {
    a = findp(a);
    b = findp(b);
    if (a == b) return false;
    p[max(a, b)]=min(a, b);
    return true;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n; cin >> m;
    f(i, 1, n+1) p[i] = i;
    f(i, 1, n+1) f(j, 1, n+1) if (i!=j) d[i][j] = inf;
    int a, b;
    f(i, 0, m) {
        cin >> a >> b;
        unite(a, b);
        d[a][b] = 1;
        d[b][a] = 1;
    }

    f(mid, 1, n+1) {
        f(i, 1, n+1) {
            f(j, 1, n+1) {
                d[i][j] = min(d[i][mid] + d[mid][j], d[i][j]);
            }
        }
    }
    f(i, 1, n+1) {
        int t = findp(i);
        group[t].push_back(i);
    }
    vector<int> ans;
    cout << group.size() <<'\n'; // 위원장 크기
    for (pair<int, vector<int> > it : group) {
        int minVal = inf;
        int target = -1;
        int dist = 0;
        for (int &center : it.second ) {
            dist = 0;
            for (int &other : it.second ) {
                dist = max(dist, d[center][other]);
            }
            if (minVal > dist) {
                minVal = dist;
                target = center;
            }
        }
        ans.push_back(target);
    }
    sort(ans.begin(), ans.end());
    for (int a : ans) cout << a << '\n';

    return 0;
}