#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int N, Q;
const int MAXN = 1e5+1;
vector<set<int> > color;
vector<pii> queries;
int connectParent[MAXN];
int parent[MAXN];

int findp(int node) {
    if (node == parent[node]) return node;
    return parent[node] = findp(parent[node]);
}

void init() {
    color.resize(N+1);
    queries.resize(N+Q-1);
    for (int i = 1; i <= N; ++i) parent[i] = i;
}

void parentInput() {
    for (int i = 2; i <= N; ++i) cin >> connectParent[i];
}

void colorInput() {
    for (int i = 1; i <= N; ++i) {
        int tmp; cin >> tmp;
        color[i].insert(tmp);
    }
}

void queryInput() {
    for (pii &query : queries) {
        cin >> query.first >> query.second;
    }
}

void smallToLarge(int a, int b) {
    if (color[a].size() > color[b].size()) swap(color[a], color[b]);
    for (int clr : color[a]) color[b].insert(clr);
    color[a].clear();
}

void connectNode(int node) {
    int a = findp(node);
    int b = findp(connectParent[node]);
    if (a == b) return;
    smallToLarge(a, b);
    parent[a] = b;
}

int getColorCount(int node) {
    return color[node].size();
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> N >> Q;
    init();
    parentInput();
    colorInput();
    queryInput();
    vector<int> ans;

    for (int q = N+Q-1; q >= 0; --q) {
        int cmd = queries[q].first;
        int a = queries[q].second;
        switch (cmd)
        {
        case 1:
            connectNode(a);
            break;
        
        case 2:
            ans.push_back(getColorCount(findp(a)));
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int &a : ans) cout << a << '\n';

    return 0;
}