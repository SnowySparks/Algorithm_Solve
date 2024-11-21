#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int toint(char ch) {
    if (ch == '0') return 0;
    else if ('a' <= ch && ch <= 'z') return ch - 'a'+1;
    else return ch - 'A' + 27;
}

int total_lan = 0;

int p[51];
int parent(int a) {
    if (a == p[a]) return a;
    else return p[a] = parent(p[a]);
}
bool unite(int a, int b) {
    a = parent(a); b = parent(b);
    if (a == b) return false;
    p[max(a,b)] = min(a,b);
    return true;
}

typedef struct io {
    int i, j, cost;
    io(int i=0, int j=0, int cost=0) : i(i),j(j),cost(cost) {}
    bool operator<(const struct io &a) const {
        return cost < a.cost;
    }
} io;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<io> lst;
    for (int i = 1 ; i <= n ; i++) {
        p[i] = i;
        for (int j = 1 ; j <=n; j++) {
            char inp; cin >> inp;
            total_lan+=toint(inp);
            if (i!=j && toint(inp)>0) {
                lst.push_back(io(i,j,toint(inp)));
            }
        }
    }
    sort(lst.begin(),lst.end());
    int cnt = 0;
    for (io e : lst) {
        if (unite(e.i,e.j)) {
            cnt++;
            total_lan -= e.cost;
        }
    }
    cout << (cnt == n-1 ? total_lan : -1 );
    return 0;
}
