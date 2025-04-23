#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define f(a, b, c) for(int a=b; a<c; ++a)
using namespace std;
const int MAXN = 2e5+1;
int N;
long long A[MAXN];
long long P[MAXN];
int x[MAXN];
long long y[MAXN];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> N;
    f(i, 0, N+1) {
        cin >> A[i] >> P[i];
        if (i > 0) P[i] += P[i-1];
    }

    int notAllowLoc = 0; //더이상 도달 불가능한 공간 (이 이후로) 
    for (;notAllowLoc <= N; ++notAllowLoc) {
        if (notAllowLoc == 0) continue;
        if (P[notAllowLoc - 1] - A[notAllowLoc] < 0) {
            break;
        }
    }
    // 더이상 도달 불가능한 영역
    f(i, notAllowLoc, N+1) x[i] = y[i] = -1;

    // 가장 멀리 도달 가능한 곳 기준으로 가장 효율적인 위치를 담은 pq넣기
    priority_queue<pair<long long, int> > pq;
    f(i, 0, notAllowLoc) {
        pq.push({P[notAllowLoc-1] - (i == 0 ? 0 : P[i-1]) - (A[notAllowLoc-1] - A[i]), i});
    }

    // 역으로 탐색
    for (int idx = notAllowLoc - 1; idx > 0; --idx) {
        while (!pq.empty() && pq.top().second >= idx) pq.pop(); //범위 밖 제거
        x[idx] = pq.top().second;
        y[idx] = P[idx-1] - (pq.top().second == 0 ? 0 : P[pq.top().second-1]) - (A[idx] - A[pq.top().second]);
    }

    f(i, 1, N+1) {
        cout << x[i] << ' ' <<y[i] <<'\n';
    }
    return 0;
}