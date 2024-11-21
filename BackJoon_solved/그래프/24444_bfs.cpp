#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;

vector <vector<int>> table(100001);
bool visited[100001];
int re[100001];
int cnt=0;



int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    int v,e,r;
    cin >> v >> e >> r;
    int a,b;

    while (e--) {
        cin >> a >> b;
        table[a].push_back(b);
        table[b].push_back(a);
    }

    for (int i=1;i<=v;i++) {
        sort(table[i].begin(),table[i].end());
    }

    queue<int> q;

    q.push(r);
    while (!q.empty()) {
        if (!visited[q.front()]) {
            visited[q.front()] = true;
            cnt++;
            re[q.front()]=cnt;

            for (int e : table[q.front()]) {
                q.push(e);
            }
        }
        q.pop();
    }

    for (int i=1;i<=v;i++) {
        cout << re[i] <<'\n';
    }
    
    return 0;

}