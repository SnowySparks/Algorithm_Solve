#include <iostream>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;

int loc[100001];

bool vd(int x) {
    if (x >= 0 && x <= 100000) return true;
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int start, end; cin >> start >> end;
    queue<int> q;
    q.push(start);

    int tp[3];
    memset(loc, -1 , sizeof(loc));
    loc[start] = 0;

    while(!q.empty()) {
        int n = q.front(); q.pop();
        tp[0] = n+1; tp[1] = n-1; tp[2] = n*2;
        for (int i = 0; i < 3; i++) {
            if ( vd(tp[i]) && loc[ tp[i]] == -1) {
                loc[tp[i]] = loc[n] +1;
                q.push(tp[i]);
            }
        }
    }
    cout << loc[end] << '\n';


    stack<int> dst;
    int f = end;
    int next;
    dst.push(end);
    while(f != start) {
        if ( f+1 <= 100000 && loc[f+1] == loc[f] -1) {
            dst.push(f+1);
            f = f+1;
        }
        else if ( f-1>= 0 && loc[f-1] == loc[f] -1) {
            dst.push(f-1);
            f = f-1;
        }
        else if ( f%2 == 0 && loc[f/2] == loc[f] -1) {
            dst.push(f/2);
            f/=2;
        }
    }
    while( !dst.empty()) {
        cout << dst.top() << ' ';
        dst.pop();
    }
    return 0;
}