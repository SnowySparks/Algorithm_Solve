#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair< long long, pair<int ,int > > > dt;
int parent[200001];
int find(int a) { 
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}
void _union(int a ,int b) {
    int pa = find(a); int pb = find(b);
    if (pa == pb) return;
    parent[max(pa,pb)] = min(pa,pb);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    int start, end; long long cost;
    long long total_cost = 0;
    long long mst_cost = 0;
    while (true) {
        total_cost = 0; mst_cost = 0;
        cin >> m >> n;
        if (n== 0 && m == 0) break;
        for (int i = 0 ; i < n ; i++) {
            cin >> start >> end >> cost;
            total_cost += cost;
            dt.push_back({cost, {start, end}});
        }
        sort(dt.begin(), dt.end());
        for (int i = 0 ; i <= m ; i ++) parent[i] = i;
        for (auto e : dt) {
        if (find(e.second.first)!=find(e.second.second)) {
            _union(e.second.first, e.second.second);
            mst_cost+=e.first;
            }
        }
        cout << total_cost - mst_cost << '\n';
        dt.clear();
    }
    return 0;
}