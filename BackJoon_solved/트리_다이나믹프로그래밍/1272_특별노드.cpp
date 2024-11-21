#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int m = 1001;

int w[m]; //원 가중치
int dp[m][m]; // 현재 노드 - 가장 가까운 특별한 부모 노드 : 값 - 가잘 최소값
int N, R;
vector<int> gh[m];

int dfs(int cur, int p) {
        if(dp[cur][p] != -1)
            return dp[cur][p];
        int rn = w[cur] - w[p]; //p가 스페셜인 경우
        int resSp = w[cur]; //자기자신이 스페셜
        for(auto e: gh[cur]) {
            resSp += dfs(e, cur);
            if(cur != R) rn += dfs(e, p);
        }
        return dp[cur][p] = (cur == R ? resSp : min(rn, resSp));
    }

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> R;
    for (int i = 1 ; i <= N ; i++) {
        cin >> w[i];
    }
    int a, b;
    for (int i = 1 ; i < N ; i++) {
        cin >> a >> b;
        if (w[a] < w[b]) gh[a].push_back(b);
        else gh[b].push_back(a);
    }
    memset(dp, -1 , sizeof(dp));
    cout << dfs(R,R);
    return 0;
} 