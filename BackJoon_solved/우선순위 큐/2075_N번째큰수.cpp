#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    /*int inp, loc;
    priority_queue<int> q1, q2;
    for (int i = 0; i < N; i++) {
        cin >> loc; q1.push(loc);
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> loc; q1.push(loc);
        }
        for (int j = 0; j < N; j++) {
            q2.push(q1.top());
            q1.pop();
        }
        while (!q1.empty()) {
            q1.pop();
        }
         while (!q2.empty()) {
            q1.push(q2.top());
            q2.pop();
        }   
    }
    while (q1.size() > 1) {
        q1.pop();
    }
    cout << q1.top() ; return 0;*/

    vector<int> lst(N*N);
    for (int i = 0; i < N*N; i++) {
        cin >> lst[i];
    }
    sort(lst.begin(), lst.end());
    cout << lst[N*N-N]; return 0;


}