#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;
#define f(a, b, c) for(int a=b; a<c; ++a)

int mv[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int N, M; // 정사각형 크기, 연결 크기
vector<int> adj[10000]; // 해당 좌표에서 불을 킬 수 있는 곳 

// 번호 단순화 (좌표 -> 노드번호)
int pts_to_num(int a, int b) {
    return (a)*N + b;
}
// 번호 돌려주기 (노드번호 -> 좌표)
pair<int, int> num_to_pts(int num) {
    int a = num / N, b= num % N;
    return {a, b};
}

// 해당 좌표는 유효한 좌표인가?
bool isIn(int a, int b) {
    if (a < 0 || b < 0 || a >= N || b >= N) return false;
    return true;
}

bool isLight[100][100]; // 켜져있는가?
bool visited[100][100]; // 방문했는가?
bool isVisitable[100][100]; // 해당 위치는 방문이 가능한가?

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int x, y, a, b;
    f(i, 0, M) {
        cin >> x >> y >> a >> b;
        // 일부러 각 좌포마다 -1 처리함 (함수에 내장)
        adj[pts_to_num(x-1, y-1)].push_back(pts_to_num(a-1, b-1));
    }

    // (1, 1) -> (0, 0) 은 이미 켜저 있고 이에 대한 처리
    isLight[0][0] = true;
    visited[0][0] = true;
    isVisitable[0][0] = true;

    queue<pair<int ,int> > q;
    q.push({0, 0});

    // BFS 시작
    while(!q.empty()) {
        // 현재 위치
        x = q.front().first; y = q.front().second; q.pop();

        // 먼저 해당 위치 주변으로 이동 자체는 가능하다는 것을 표시
        for (auto [dx, dy] : mv) {
            int nx = x + dx, ny = dy + y;
            if (!isIn(nx, ny)) continue;
            isVisitable[nx][ny] = true;
        }

        int node = pts_to_num(x, y); // 노드로 변환
        for (int connected_node : adj[node]) {
            // 해당 위치에서 연결된 모든 방 불 켜기
            tie(a, b) = num_to_pts(connected_node); //
            isLight[a][b] = true;
        }

        // 연결된 스위치 공간과 관련해서, 방문이 안된 상태인데 방문이 가능하다? 에 대한 처리
        for (int connected_node : adj[node]) {
            tie(a, b) = num_to_pts(connected_node);
            if (isLight[a][b] && isVisitable[a][b] && !visited[a][b]) {
                q.push({a, b});
                visited[a][b] = true;
            } 
        }

        // 해당 위치 주변에서도 불 켜저 있고, 이동 가능한 상태고, 아직 방문 안했을 경우에 대한 처리
        for (auto [dx, dy] : mv) {
            int nx = x + dx, ny = dy + y;
            if (!isIn(nx, ny)) continue;
            if (isLight[nx][ny] && isVisitable[nx][ny] && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            } 
        }
    }

    int ans = 0;
    f(i, 0, N) f(j, 0, N) if (isLight[i][j]) ++ans;
    cout << ans;

    return 0;
}

// 원리
// 이 문제의 핵심은 BFS로 얼마나 많은 곳을 갈 수 있느냐가 아니라, 얼마나 많이 불을 킬 수 있느냐에 달려 있음
// 즉 BFS 로 구석진 곳으로 가다가 불이 만약 다른 곳으로 키게 되는 경우, 그 켜진 곳으로도 이동 할 수 있음
// 즉 불빛이 켜진 곳은 "몇번이든 이동가능" 하다는 점을 잘 공략해야 함

// 함정 예시 ---
// 3 5
// 1 1 1 2
// 1 2 1 3
// 1 3 2 3
// 2 3 2 1
// 2 1 3 1
// ans : 6