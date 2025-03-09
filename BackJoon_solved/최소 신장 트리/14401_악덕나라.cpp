#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define f(a, b, c) for(int a=b; a<c; ++a)
using namespace std;
typedef long long ll;

int n, m;
struct point {
    ll x, y;
};
struct edge {
    int n1, n2;
    ll dist;
};
point pt[501];

ll calDist(point &a, point &b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

// 두 포인트 내 사이에 한 점이 있는가
bool isCanConnect(point &fr, point &to, point &mid) {
    // 두 포인트 x축 평행 && mid 그사이안에?
    if (fr.x == to.x) {
        if (mid.x != fr.x) return false;
        return (min(fr.y, to.y) <= mid.y && mid.y <= max(fr.y, to.y));
    }
    // 두 포인트 y축 평행 && mid 그사이안에?
    if (fr.y == to.y) {
        if (mid.y != fr.y) return false;
        return (min(fr.x, to.x) <= mid.x && mid.x <= max(fr.x, to.x));
    }
    // 함수식에 부합하고, mid.x, y 좌표 위치가 범위 안에 있는가?
    bool c1 = (to.y - fr.y)*(mid.x - fr.x) + fr.y*(to.x - fr.x) == mid.y*(to.x - fr.x);
    bool c2 = min(fr.x, to.x) <= mid.x && mid.x <= max(fr.x, to.x);
    bool c3 = min(fr.y, to.y) <= mid.y && mid.y <= max(fr.y, to.y);
    return c1 && c2 && c3;
}

bool canConnect(int a, int b) {
    for (int i = 1; i <= n; ++i) {
        if (i == a || i == b) continue;
        if (isCanConnect(pt[a], pt[b], pt[i])) return false;
    }
    return true;
}

int p[501];
int findp(int x) {
    if (p[x] == x) return x;
    return p[x] = findp(p[x]);
}
// 도시 연결
bool unite(int a, int b) {
    int pa = findp(a);
    int pb = findp(b);
    if (pa == pb) return false;
    p[max(pa, pb)] = min(pa, pb);
    return true;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int edgeCnt = 0;
    cin >> n >> m;
    f(i, 1, n+1) {
        cin >> pt[i].x >> pt[i].y;
        p[i] = i;
    }
    f(i, 0, m) {
        int a, b;
        cin >> a >> b;
        if (unite(a, b)) {
            edgeCnt++;
        }
    }
    vector<edge> edges;
    f(i, 1, n) {
        f(j, i+1, n+1) {
            if (findp(i) != findp(j) && canConnect(i, j)) {
                edges.push_back({i, j, calDist(pt[i], pt[j])});
            }
        }
    }
    sort(edges.begin(), edges.end(), [](const edge &a, const edge &b){
        return a.dist > b.dist;
    });

    ll ans = 0;
    for (edge &e : edges) {
        if (edgeCnt == n-1) break;
        if (unite(e.n1, e.n2)) {
            ans += e.dist;
            ++edgeCnt;
        }
    }
    cout << ans;
    return 0;
}