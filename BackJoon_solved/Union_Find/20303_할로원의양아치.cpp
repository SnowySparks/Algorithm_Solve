#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define f(a, b, c) for(int a=b;a<c;++a)
int n, m, k;
const int MAXN = 3e4 + 1;
const int MAXK = 3001;
int candy[MAXN]; //그룹 i가 갖는 캔디 수
int peopleCnt[MAXN]; // 그룹 i가 갖는 인원 수
int p[MAXN];
bool v[MAXN]; // 처리완료 확인용
int ans = 0;
int dp[MAXK];

struct dt {
    int candyCnt; int people;
};

vector<dt> lst;

// 부모찾기 - find
int parent(int node) {
    if (p[node] == node) return node;
    return p[node] = parent(p[node]);
}

// union
bool unite(int a, int b) {
    int pa = parent(a), pb = parent(b);
    if (pa == pb) return false;
    p[max(pa, pb)] = min(pa, pb);
    peopleCnt[min(pa, pb)] += peopleCnt[max(pa, pb)];
    candy[min(pa, pb)] += candy[max(pa, pb)];
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
// ----- input ----
    cin >> n >> m >> k;
    f(i, 1, n+1) cin >> candy[i];
    f(i, 1, n+1) {
        p[i] = i;
        peopleCnt[i] = 1;
    }

    f(i, 0, m) {
        // 인풋과 동시에 union-find처리
        int a, b; cin >> a >> b;
        unite(a, b);
    }
    lst.push_back({-1,-1}); // dummy
    f(i, 1, n+1) {
        // 각 노드의 부모 노드 기준으로 그룹핑 결과를 리스트에 저장
        int pi = parent(i);
        if (v[pi]) continue;
        v[pi] = true;
        lst.push_back({candy[pi], peopleCnt[pi]});
    }
    int sz = lst.size(); //lst Size

    // 저장한 리스트들로 냅색
    // 냅색
    f(idx, 1, sz) { // idx : lst 인덱스
        int candyCnt = lst[idx].candyCnt; int pCnt = lst[idx].people;

        for(int kidx = k-1; kidx >= pCnt; --kidx) {
            dp[kidx] = max(dp[kidx], dp[kidx-pCnt] + candyCnt);
        }
    }
    cout << dp[k-1];
    return 0;
}