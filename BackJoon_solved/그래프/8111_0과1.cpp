#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
using pis = pair<int, string>;
int n;
int md;
bool v[20001];

string bfs(int st) {
    memset(v,false,sizeof(v));
    v[st%md] = true;
    queue<pis> q; q.push({st%md,to_string(st)});

    while (!q.empty()) {
        pis lc = q.front(); q.pop();
        if (lc.first == 0) return lc.second;

        pis n1 = {(lc.first * 10 + 1)%md,lc.second+"1"};
        pis n2 = {(lc.first * 10)%md, lc.second+"0"};

        if (!v[n1.first]) {q.push(n1); v[n1.first]=true;}
        if (!v[n2.first]) {q.push(n2); v[n2.first]=true;}
    }
    return "BRAK\n";
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--) {
        cin >> md;
        if (md == 1) cout << "1\n";
        else cout << bfs(1) <<'\n';
    }
    return 0;
}