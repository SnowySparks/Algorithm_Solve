#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

#define MAX 2000000000
int path[1001];

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    int v , e;
    cin >> v >> e;
    vector <vector < pair <int ,int>>> table (v+1);
    vector<int> dist(v+1);
    fill (dist.begin(), dist.end(), MAX);
    int a,b,cost;
    while (e--) {
        cin >> a >> b >> cost;
        table[a].push_back(make_pair (cost,b));
    }

    int start,end,count =0;
    cin >> start >> end;


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
                path[e.second] = loc;
                pq.push(make_pair(-next_cost,e.second));
            }
        }

    }

    deque<int> p;

    cout << dist[end]<<endl;
    loc = end;

    while (loc != 0) {
        p.push_back(loc);
        loc = path[loc];
    }

    cout << p.size() <<'\n';

    for (auto it = p.rbegin() ; it != p.rend() ; it++ ) {
        cout << *it <<' ';
    }
    

    return 0;
}