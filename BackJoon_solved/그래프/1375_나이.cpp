#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
unordered_map<string, int> mp;
vector<vector<int> > gh;
vector<bool> v;


bool check(const string &st, const string &en) {
    fill(v.begin(),v.end(),false);
    v[mp[st]]=true;
    queue<int> q; q.push(mp[st]);
    while(!q.empty()) {
        int loc = q.front(); q.pop();
        if (loc == mp[en]) return true;
        for (int k : gh[loc]) {
            if (!v[k]) {
            q.push(k);
            v[k]=true;
            }}
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    cin >> n >> m;
    gh.assign(n+1,vector<int>());
    v.assign(n+1,false);
    for (int i = 0 ; i < m ; i++) {
        string a, b; cin >> a >> b;
        if (mp.find(a)==mp.end()) mp[a] = ((int)mp.size())+1;
        if (mp.find(b)==mp.end()) mp[b] = ((int)mp.size())+1;
        gh[mp[a]].push_back(mp[b]);
    }
    int q; cin >> q;
    while (q--) {
        string a, b; cin >> a >> b;
        if (a == b) cout <<"gg ";
        else cout << (check(a,b) ? a : (check(b,a) ? b : "gg")) <<' ';
    }
    return 0;
}