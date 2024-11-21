#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector < set <int> > table(100001);
bool visited[100001];
int re[100001];
int cnt=0;

void dfs (int current) {
    if (visited[current]) return;

    visited[current] = true;
    cnt++;
    re[current] = cnt;
    for (auto &next : table[current]) {
        if (visited[next]) {
            continue;
        }
        dfs(next);
    }
}


int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    int v,e,r;
    cin >> v >> e >> r;
    int a,b;

    while (e--) {
        cin >> a >> b;
        table[a].insert(b);
        table[b].insert(a);
    }

    dfs(r);

    for (int i=1;i<=v;i++) {
        cout << re[i] <<'\n';
    }
    
    return 0;

}