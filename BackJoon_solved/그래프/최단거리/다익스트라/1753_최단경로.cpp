#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 2000000000

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    int v , e;
    cin >> v >> e;
    vector <vector < pair <int ,int>>> table (v+1);
    vector<int> dist(v+1);
    fill (dist.begin(), dist.end(), MAX);
    int start;
    cin >> start;

    int a,b,cost;
    while (e--) {
        cin >> a >> b >> cost;
        table[a].push_back(make_pair (cost,b));
    }

    priority_queue < pair <int ,int >> pq; //비용 (음수로) , 노드 

    pq.push(make_pair(0,start));
    dist[start]=0;
    int loc;

    while (!pq.empty()) {
        cost = -pq.top().first;
        loc = pq.top().second;
        pq.pop();

        if (dist[loc]<cost) {
            continue;
        }
        for (auto e : table[loc]) {
            int next_cost = cost + e.first;
            if (dist[e.second]>next_cost) {
                dist[e.second] = next_cost;
                pq.push(make_pair(-next_cost,e.second));
            }
        }
    }

    for (int i=1;i<=v;i++){
        cout <<(dist[i]==MAX ? "INF" : to_string(dist[i])) <<'\n';
    }
    return 0;
}