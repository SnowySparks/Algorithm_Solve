#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1e5+1;
int order[inf], n;
bool v[inf];
vector<int> lst[inf];
vector<int> ans;

bool comp(int a, int b) {
    return order[a] < order[b];
}

void dfs(int x) {
    if (v[x]) return;
    v[x] = true;
    ans.push_back(x);
    for (int &a : lst[x]) {
        if (!v[a]) dfs(a);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0 ; i < n-1; i++) {
        int a, b; cin >> a >> b;
        lst[a].push_back(b);
        lst[b].push_back(a);
    }
    for (int i = 1 ; i <= n ; i++) {
        int a; cin >> a;
        order[a] = i;
    }
    for (int i = 1 ; i <= n; i++) sort(lst[i].begin(), lst[i].end(), comp);
    dfs(1);
    for (int i = 0 ; i < n ; i++) {
        if (i+1 != order[ans[i]]) {
            cout << 0; return 0;
        }
    }
    cout << 1; return 0;
}