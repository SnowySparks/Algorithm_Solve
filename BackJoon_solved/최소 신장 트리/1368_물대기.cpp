#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define f(a, b, c) for(int a=b; a<c; ++a)
struct edge {
    int a, b, w;
};
int n;
int well[301];
int edgeCnt[301][301];
int p[301];

// union-find
int fp(int x) {
    if (p[x] == x) return x;
    return p[x] = fp(p[x]);
}
bool unite(int a, int b) {
    a = fp(a);
    b = fp(b);
    if (a == b) return false;
    p[max(a,b)]=min(a,b);
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // Input
    cin >> n;
    f(i, 1, n+1) p[i] = i;
    f(i, 1, n+1) cin >> well[i];
    f(i, 1, n+1) f(j, 1, n+1) cin >> edgeCnt[i][j];
    // MST
    vector<edge> edges;
    f(i, 1, n) {
        f(j, i+1, n+1) {
            edges.push_back({i, j, edgeCnt[i][j]});
        }
    }
    // 가상의 우물 연결 
    f(i, 1, n+1) {
        edges.push_back({0, i, well[i]});
    }
    sort(edges.begin(), edges.end(), [](const edge &a, const edge &b) {
        return a.w < b.w;
    });
    int cnt = 0;
    int answer = 0;
    for (auto &[a, b, w] : edges) {
        if (cnt == n) break;
        if (unite(a, b)) {
            answer += w;
            ++cnt;
        }
    }
    cout << answer;
    return 0;
}