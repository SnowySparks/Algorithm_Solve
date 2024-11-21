#include <iostream>
#include <algorithm>
#include <queue>
#define f(a,b,c) for (int a = b; a < c; a++)
using namespace std;

pair<int, int> dt[100000];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    int a, b, c;
    f(i,0,N) { cin >> a >> b >>c; dt[i].first = b; dt[i].second = c;}
    sort(dt,dt+N);
    priority_queue<int, vector<int>, greater<> > q;
    f(i,0,N) {
        if (q.empty() || q.top() > dt[i].first) q.push(dt[i].second);
        else {q.pop(); q.push(dt[i].second);}
    }
    cout << q.size();
}