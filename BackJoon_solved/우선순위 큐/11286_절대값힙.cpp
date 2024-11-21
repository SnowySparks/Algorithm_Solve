#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct comp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};


int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N;
    pair<int, int> a;
    cin >> N;
    priority_queue<pair<int,int>,vector<pair<int,int> >,comp> q;

    while (N--) {
        cin >> a.first;
        a.second = abs(a.first);
        if (a.first!=0) {
            q.push(a);
        }
        else {
            if (q.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << q.top().first << '\n';
                q.pop();
            }
        }
    }

    return 0;

    

}