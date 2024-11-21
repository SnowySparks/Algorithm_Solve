#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//우선순위 큐도 사용, 파일 합치기 3과 동일
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long ans = 0;
    int N; cin >> N;
    priority_queue<long long, vector<long long>, greater<> > q;
    for (int i = 0; i < N; i++) {
        long long inp; cin >> inp;
        q.push(inp);
    }

    while (q.size() > 1) {
        long long a = q.top();
        q.pop();
        long long b = q.top();
        q.pop();
        ans+= (a+b);
        q.push(a+b);
    }

    cout << ans;
    return 0;
}