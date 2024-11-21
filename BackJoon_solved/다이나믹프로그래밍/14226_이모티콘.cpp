#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define _inf 987654321
using namespace std;

int dp[1001][1001]; //현재 화면 보이는 것, 클립보드에 복사된 개수 -> 저장값 : 시간
int answer = _inf;
void bfs(int N) { //각 명령 시행은 1초가 걸림 -> 가중치 같음 -> bfs + dp
    dp[1][1] = 1;
    queue<pair<int, int> > q;
    q.push({1,1});

    while(!q.empty()) { 
        int now_emoji = q.front().first;
        int clip = q.front().second;
        int time = dp[now_emoji][clip];
        q.pop();
        //맞는 개수 -> 답갱신
        if (now_emoji == N) {
            answer = min(answer, time);
        }
        //다름
        else {
            //클립보드 복사
            if (dp[now_emoji][now_emoji] == 0) {
                q.push({now_emoji, now_emoji});
                dp[now_emoji][now_emoji] = time+1;
            }
            //붙이기
            if (now_emoji + clip <= N && dp[now_emoji + clip][clip] == 0) {
                q.push({now_emoji+clip,clip});
                dp[now_emoji+clip][clip] = time+1;
            }
            //지우기
            if (now_emoji -1 >= 0 && dp[now_emoji -1][clip] == 0) {
                q.push({now_emoji -1,clip});
                dp[now_emoji -1 ][clip] = time+1;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    bfs(N);
    cout << answer; return 0;
}