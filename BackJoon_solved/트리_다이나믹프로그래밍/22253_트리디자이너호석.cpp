#include <iostream>
#include <vector>
#define f(a, b, c) for(int a=b; a<c; ++a)
using namespace std;
int n;
const int MAXN = 1e5+1;
vector<int> adj[MAXN];
int num[MAXN];
const long long MOD = 1e9 + 7;
long long dp[MAXN][10]; //현재 i노드고, 가지의 가장 작은번호가 j일떄 가지의 모든 경우의 수

void dfs(int node, int pnode) {
    dp[node][num[node]] = 1; //단 1개 자기자신에 대한 카운팅
    for (int child : adj[node]) {
        if (child == pnode) continue;
        dfs(child, node);
        // 자기 자신 번호가 쓰이는 가지에 대한 경우
        f(i, num[node], 10) {
            dp[node][num[node]] += dp[child][i];
        }
        // 자기자신 번호가 쓰이지 않을 때
        f(i, 0, 10) {
            dp[node][i]+= dp[child][i];
            dp[node][i]%=MOD;
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b;

    cin >> n; // 노드크기
    f(i, 1, n+1) cin >> num[i]; // 0 ~ 9 자연수 입력
    f(i, 0, n-1) { //트리간선
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    long long ans = 0;
    f(i, 0, 10) {
        ans += dp[1][i];
        ans %= MOD;
    }
    cout << ans;
    return 0;
}