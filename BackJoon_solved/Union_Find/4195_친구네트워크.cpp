#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string, int> dt;
int parent[200001];
int cnt[200001];

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a]=find(parent[a]);
 }
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    int n;
    string a,b;
    while(T--) {
        cin >> n;
        int loc = 0;
        int la, lb;
        dt.clear();
        for (int i = 0; i <200001; i++) {
            parent[i] = i;
            cnt[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            if (dt.find(a) == dt.end()) {
                dt[a] = ++loc;
                la = loc;
            }
            else la = dt[a];

            if (dt.find(b) == dt.end()) {
                dt[b] = ++loc;
                lb = loc;
            }
            else lb = dt[b];

            int pa = find(la);
            int pb = find(lb);

            if (pa == pb) cout << cnt[pa] <<'\n';
            else {
            cnt[min(pa,pb)] += cnt[max(pa,pb)];
            parent[max(pa,pb)] = min(pa,pb);
            cout << cnt[min(pa,pb)] <<'\n'; }
        }
    }
    return 0;
}