#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define f(a,b,c) for(int a=b; a<c;a++)
using pdi = pair<double, int> ;
using pii = pair<int, int>;

const double inf = 1E9;
int n,w,x,y; double m;

vector<pdi> gh[1001];
double dist[1001];
pii coor[1001];


double cdst(pii a, pii b) {
    return sqrt(pow(a.first-b.first,2) + pow(a.second - b.second,2));
}

int direk(int st=1) {
    f(i,1,n+1) dist[i] = inf;
    dist[st] = 0;
    priority_queue<pdi> pq; pq.push({0,st});

    while (!pq.empty()) {
        double cost = -pq.top().first;
        int loc = pq.top().second;
        pq.pop();

        if (dist[loc] < cost ) continue;

        for (pdi cp : gh[loc]) {
            double ncost = cost + cp.first;
            if (ncost < dist[cp.second]) {
                pq.push({-ncost, cp.second});
                dist[cp.second] = ncost;
            }
        }
    }

    return int(dist[n]*1000);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> w;
    cin >> m;

    f(i,1,n+1) cin >> coor[i].first >> coor[i].second;

    f(i,1,n+1) f(k,i+1,n+1) {
        double d = cdst(coor[i],coor[k]);
        if (d <= m) {
            gh[i].push_back({d,k});
            gh[k].push_back({d,i});
        }
    }
    f(i,0,w) {
        cin >> x >> y;
        gh[x].push_back({0,y});
        gh[y].push_back({0,x});
    }

    cout << direk();
    return 0;
}