#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
const int inf = 1e8;
using namespace std;
int N, M, K;
int dist[101][101];
vector<int> friends;

// 데이터 초기화
void clean() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) dist[i][j] = inf;
        dist[i][i] = 0;
    }
    friends.clear();
}

// 플루이드 워셜 계산
void cal() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 1; k <= N; ++k) {
                dist[j][k] = min(dist[j][i] + dist[i][k], dist[j][k]);
            }
        }
    }
}

// void output() {
//     for (int i = 1; i <= N; ++i) {
//         for (int j = 1; j <= N; ++j) {
//             cout << dist[i][j] <<' ';
//         }
//         cout << '\n';
//     }
// }

// 메인
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int T; cin >> T;
    int a, b, c;
    int ans = 0, ans_dist = inf;
    while (T--)
    {
        cin >> N >> M;
        clean();
        for (int i = 1; i <= M; ++i) {
            cin >> a >> b >> c;
            dist[a][b] = c;
            dist[b][a] = c;
        }
        cin >> K;
        while (K--)
        {
            cin >> a;
            friends.push_back(a);
        }
        cal();
        ans_dist = inf;
        // output();

        // 각 포인터를 기준으로 친구들이 해당 포인터로 이동하는 거리의 총합 계산 후 답 갱신
        for (int pointer = 1; pointer <= N; ++pointer) {
            int cal_dist = 0;
            for (int p : friends) {
                cal_dist += dist[p][pointer];
            }
            if (ans_dist > cal_dist) {
                ans=pointer;
                ans_dist = cal_dist;
            }
        }
        cout << ans << '\n';

    }
    


    return 0;
}