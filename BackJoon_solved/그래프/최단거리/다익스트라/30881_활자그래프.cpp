#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#define f(a, b, c) for(int a=b; a<c; ++a)
#define START 1
#define END 2
using namespace std;
typedef long long ll;
typedef pair<ll ,int> pli;
const int N = 2e5 + 1;
const ll inf = 1'000'000'000'000'000'001LL;
int T = 0, n = 0, m = 0, before_n = 0;

struct edge {
    int nxt_node; ll weight;
};

ll dist[N];
vector<edge> gh[N];
vector<ll> cal_dist_1_to_2;
vector<ll> cal_dist_2_to_1;

void init() {
    f(i, 1, max(n, before_n)+1) {
        gh[i].clear();
    }
}

void input_gh() {
    int v, w, x;
    f(i, 1, m+1) {
        cin >> v >> w >> x;
        if (x >= 0) gh[v].push_back({w, x});
        else {
            gh[v].push_back({w, cal_dist_1_to_2[-x]});
            gh[w].push_back({v, cal_dist_2_to_1[-x]});
        }
    }
}

ll simulation(int start_node, int end_node) {

    f(i, 1, n + 1) dist[i] = inf;
    dist[start_node] = 0;

    priority_queue<pli, vector<pli>, greater<> > pq;
    pq.push({0LL, start_node});

    while (!pq.empty())
    {
        ll now_weight = pq.top().first;
        int now_node = pq.top().second;
        pq.pop();
        
        if (dist[now_node] < now_weight) continue;

        for (edge &e : gh[now_node]) {
            if (e.weight >= inf) continue;
            int nxt_node = e.nxt_node;
            ll nxt_weight = e.weight + now_weight;

            if (dist[nxt_node] > nxt_weight) {
                dist[nxt_node] = nxt_weight;
                pq.push({nxt_weight, nxt_node});
            }
        }
    }
    return dist[end_node];
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> T;
    cal_dist_1_to_2.assign(T+1, LLONG_MAX);
    cal_dist_2_to_1.assign(T+1, LLONG_MAX);

    for (int c = 1; c <= T; ++c) {
        before_n = n;
        cin >> n >> m;

        init();
        input_gh();
        cal_dist_1_to_2[c] = simulation(START, END);
        cal_dist_2_to_1[c] = simulation(END, START);

    }
    cout << (cal_dist_1_to_2[T] >= inf ? -1 : cal_dist_1_to_2[T]);

    return 0;
}