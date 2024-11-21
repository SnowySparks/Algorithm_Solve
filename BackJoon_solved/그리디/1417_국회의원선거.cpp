#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    priority_queue<int, vector<int> , less<int> > pq;
    int inp;
    int one_number;
    for (int i = 1 ; i <= N ; i++) {
        cin >> inp;
        if (i == 1 ) one_number = inp;
        else {
            if (inp >= one_number) pq.push(inp);
        }
    }
    int answer = 0;
    int t;
    while (!pq.empty()) {
        t = pq.top(); pq.pop();
        if (t < one_number) break;
        else {
            t--; answer++; one_number++;
            if (t >= one_number) pq.push(t);
        }
    }
    cout << answer;
    return 0;
}