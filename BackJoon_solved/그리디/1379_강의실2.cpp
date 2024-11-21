#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define f(a,b,c) for (int a = b; a < c; a++)
using namespace std;
int n;
typedef struct _info {
    int loc, s, e;
    bool operator>(const _info &a) const {
        if (e ==a.e) return s > a.s;
        return e > a.e;
    }
} info;
bool comp(const _info &a, const _info &b) {
    return a.s < b.s;
}

info dt[100000];
int room[100001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    f(i,0,n) cin >> dt[i].loc >> dt[i].s >> dt[i].e;
    sort(dt,dt+n,comp);
    int ans = 0;
    priority_queue<info, vector<info>, greater<info> > q;
    f(i,0,n) {
        if ( !q.empty() && q.top().e <= dt[i].s) {
            room[dt[i].loc] = room[q.top().loc];
            q.pop();
        }
        else {
            ans++;
            room[dt[i].loc] = ans;
        }
        q.push(dt[i]);
    }
    cout << ans <<'\n';
    for (int i = 1 ; i<= n; i++) cout << room[i] << ' ';
}