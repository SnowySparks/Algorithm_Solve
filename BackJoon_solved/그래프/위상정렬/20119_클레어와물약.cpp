#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define f(a, b, c) for(int a=b; a<c; ++a)
using namespace std;
const int N = 2e5 + 1;
int n, m, l; // n개물약, m개의 간선정보, l개의 이미 존재하는 물약
int input[N]; // 입력 전용 (x_1 ... x_k) -> r
int edgeGropCnt[N]; // input->i에 대한 indegree개수 (간선에 대한 한 줄 입력이 간선그룹 한 개)
bool exist[N]; // 물약존재 혹은 만들 수 있음 
vector<pair<int ,int> > adj[N]; // 그래프 <간선 그룹 인덱스, 다음 노드>

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r", stdin);
    cin >> n >> m;
    int k, r;
    queue<int> q;
    f(eIdx, 1, m+1) { // 
        cin >> k; // 개수
        f(t, 0, k) cin >> input[t];
        cin >> r;

        f(t, 0, k) adj[input[t]].push_back({eIdx, r});
        edgeGropCnt[eIdx] = k;
    }
    cin >> l;
    f(i, 0, l) {
        int tmp; cin >> tmp;
        exist[tmp] = true;
        q.push(tmp);
    }

    while (!q.empty())
    {
        int node = q.front(); q.pop();
        for (auto [eIdx, child] : adj[node]) {
            if (exist[child]) continue;
            edgeGropCnt[eIdx]--;
            if (edgeGropCnt[eIdx] == 0) {
                q.push(child);
                exist[child] = true;
            }
        }
    }
    int cnt = 0;
    f(i, 1, n+1) cnt += exist[i];
    cout << cnt << '\n';
    f(i, 1, n+1) if (exist[i]) cout << i << ' '; 

    return 0;
}