#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define GREATER 0
#define LOWER 1
int n, m;
bool v[1'001];
int p[1'001];

int findp(int x) {
    if (x == p[x]) return x;
    return p[x] = findp(p[x]);
}

bool unite(int a, int b) {
    a = findp(a);
    b = findp(b);
    if (a == b) return false;
    p[max(a, b)] = min(a, b);
    return true;
}

struct edge
{
    int a, b, c;
    bool operator<(const edge &other) const {
        return c < other.c;
    }
    bool operator>(const edge &other) const {
        return c > other.c;
    }
};

vector<edge> edges;

void init() {
    cin >> n >> m;
    edges.resize(m+1);
    for (edge &e : edges) {
        cin >> e.a >> e.b >> e.c;
    }
}

int calTireness(int orderType) {
    memset(v, 0, sizeof(v));
    for (int i = 1; i <= n; ++i) p[i] = i;
    switch (orderType)
    {
    case GREATER:
        sort(edges.begin(), edges.end());
        break;
    
    case LOWER:
        sort(edges.begin(), edges.end(), greater<edge>() ) ;
        break;
    }

    int connectedEdge = 0;
    int cal = 0;

    for (edge &e : edges) {
        int a = e.a, b = e.b, c = e.c;
        if (unite(a, b)) {
            cal += 1-c;
        }
        if (connectedEdge == n) break;
    }
    
    return cal*cal;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    init();
    cout << calTireness(GREATER) - calTireness(LOWER);
    return 0;
}