#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool cp1(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    vector<pair<int, int> > dt(N);
    for (int i = 0; i < N; i++) {
        cin >> dt[i].first  >> dt[i].second;
    }
    priority_queue<int, vector<int> , greater<> > q;
    sort(dt.begin(), dt.end(), cp1);
    int loc = 0;
    while( loc < N ) {
        if ( q.empty() || q.top() > dt[loc].first) {
            q.push(dt[loc++].second);
        }
        else {
            q.pop();
            q.push(dt[loc++].second);
        }
    }
    cout << q.size() << '\n'; return 0;

}