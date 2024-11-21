#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[200001];
bool visited[200001];

//그래프가 서로 떨어져 있을 경우를 대비한 dfs 형태의 함수
int dfs(int a) {
    //방문처리
    visited[a] = true;
    //사이즈가 0인 경우 = 노드 없음 = -1 리턴
    if (graph[a].size() == 0) return -1;
    int cnt = 0;
    //degree가 홀수 인 경우 cnt= 1
    if (graph[a].size() %2 == 1) {
        cnt ++;
    }

    for (int i = 0 ; i < graph[a].size() ; i++) {
        //방문하지 않은 곳이 있으면 dfs 형식으로 cnt값 갱신
        //첫 지정한 곳을 제외한 "말단 Node의 홀수 개의 degree가진 것들의 개수만 추가"
        //가장 말단 부분만 cnt가 갱신되고, 되돌아 오면서 전부 방문 처리가 되었기에 영향 x 
        if (!visited[graph[a][i]]) cnt+=dfs(graph[a][i]);
    }
    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    //그래프 입력
    int N, M; cin >> N >> M;
    int t1,t2;
    for (int i = 1; i<= M ; i++) {
        cin >> t1 >> t2;
        graph[t1].push_back(t2);
        graph[t2].push_back(t1);
    }

    int ans = 0, odd;
    for (int i = 1 ; i<= N ; i++) {
        if (!visited[i]) { //방문하지 않은 곳에 한에서만 dfs 및 개수 업데이트
        odd = dfs(i);
        if (odd == 0) {
            ans ++;
        }
        else if (odd == -1) continue;

        else ans+= (odd/2); }
    }
    cout << ans;
}