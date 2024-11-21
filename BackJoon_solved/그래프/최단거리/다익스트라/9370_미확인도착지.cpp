#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 987654321

int low_cost (const vector <vector <pair<int, int> > > & table,int n,const int &start,const int & end) {
    priority_queue < pair <int ,int >> pq; //비용 (음수로) , 노드 
    vector<int> dist(n+1);
    fill (dist.begin(), dist.end(), MAX);
    int cost,loc;
    pq.push({0,start});
    dist[start]=0;
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
    return dist[end];
}



int main(void) {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    vector <vector <pair<int, int> > >table(2001);//비용 , 위치
    vector<int>dist(2001);
    fill (dist.begin(),dist.end(),MAX);
    vector<int> candidate;
    vector<int> ori_dist;
    vector<int> ans;
    int N;
    cin>>N;
    int n=2000,m=0,t,s,g,h;
    int a,b,d,temp;
    int intersect;

    while (N--) {
        //초기화
        if (m!=0) {
            for (int i=1; i<=n ; i++) {
                table[i].clear();
            }
            candidate.clear();
        }
        fill (dist.begin(),dist.begin() + n+1,MAX);
        ans.clear();
        ori_dist.clear();

        cin >> n >> m >> t >> s >> g >> h;
        while (m--) {
            cin >>a>>b>>d;
            table[a].push_back({d,b});
            table[b].push_back({d,a});
        }

        while (t--) {
            cin >> temp;
            candidate.push_back(temp);
        }
        intersect = low_cost(table,n,g,h);

        for (auto e : candidate) {
            ori_dist.push_back(low_cost(table,n,s,e));
        }
        for (int i = 0 ;i < candidate.size(); i++) {
            if (ori_dist[i] == min (low_cost(table,n,s,g) + intersect + low_cost(table,n,h,candidate[i]) , low_cost(table,n,s,h) + intersect + low_cost(table,n,g,candidate[i]) ) )
                ans.push_back(candidate[i]);
        }

        sort(ans.begin(), ans.end());
        for (auto e : ans) {
            cout << e << " ";
        }
        cout<<'\n';
    }  
    return 0;
}