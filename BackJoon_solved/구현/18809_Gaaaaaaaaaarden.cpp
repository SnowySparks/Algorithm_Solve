#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define f(a, b, c) for(int a=b; a<c; ++a)
#define LAKE 0
#define NOT_ABLE 1 // Not AVailable
#define ABLE 2 // Available
#define GREEN 3
#define RED 4
#define FLOWER 5
using namespace std;
typedef pair<int, int> pii;
const int mv[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};
int N, M, G, R;
int arr[50][50];
int state[50][50];
int t[50][50];
int ans = 0;
vector<pii> ableLoc; // 배양액을 놓을 수 있는 공간
vector<pii> green; // 첫 그린이 둘 곳
vector<pii> red; // 첫 레드가 둘 곳

struct info
{
    int r, c, type;
};

bool isIn(int r, int c) {
    if (r < 0 || c < 0 || r >= N || c >= M) return false;
    return true;
}


void simulation() {
    memset(state, -1, sizeof(state));
    memset(t, -1, sizeof(t));
    queue<info> q;
    for (auto &[r, c] : green) {
        q.push({r, c, GREEN});
        state[r][c] = GREEN;
        t[r][c] = 0;
    }
    for (auto &[r, c] : red) {
        q.push({r, c, RED});
        state[r][c] = RED;
        t[r][c] = 0;
    }
    int nowTime = 1;
    int flowerCnt = 0;
    while (!q.empty())
    {
        int cnt = q.size();
        f(query, 0, cnt) {
            int r = q.front().r;
            int c = q.front().c;
            int type = q.front().type;
            q.pop();

            if (state[r][c] == FLOWER) continue; //해당 지역이 FLOWER이다 -> 바로 스킵

            for (auto [dr, dc] : mv) {
                int nr = r + dr, nc = c + dc;
                // 영역밖
                if (!isIn(nr,nc)) continue;

                // 주변에 퍼질때, 꽃이나 호수 -> 가로막힌 것이나 다름없다.
                if (arr[nr][nc] == LAKE) continue;
                if (state[nr][nc] == FLOWER) continue;

                // 아직 방문 안한 상태임 ->퍼트리자
                if (t[nr][nc] == -1) {
                    t[nr][nc] = nowTime;
                    state[nr][nc] = type;
                    q.push({nr, nc, type});
                }

                // 만약 동일한 시간대에 만난 경우 -> 이때 교차 검증을 해야 한다
                else if (t[nr][nc] == nowTime) {
                    if ((type == GREEN && state[nr][nc] == RED) || type == RED && state[nr][nc] == GREEN) {
                        state[nr][nc] = FLOWER;
                        ++flowerCnt;
                    }
                }
            }
        }
        ++nowTime;
    }
    // f(r, 0, N) {
    //     f(c, 0, M) {
    //         cout << state[r][c] <<' ';
    //     }
    //     cout << '\n';
    // }
    ans = max(ans, flowerCnt);
}

void back_track(int idx) {
    // 남아있는 위치에 대해서 그 개수가 부족하면 그 즉시 종료
    if (ableLoc.size() - idx < (G+R) - green.size() - red.size()) return;
    if (ableLoc.size() - idx < G - green.size()) return;
    if (ableLoc.size() - idx < R - red.size()) return;

    // 다 놔둠
    if (green.size() == G && red.size() == R) {
        simulation();
        return;
    }
    for (int i = idx; i < ableLoc.size(); ++i) {
        if (green.size() < G) {
            green.push_back(ableLoc[i]);
            back_track(i+1);
            green.pop_back();
        }
        if (red.size() < R) {
            red.push_back(ableLoc[i]);
            back_track(i+1);
            red.pop_back();
        }
    }
    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    
    // input
    cin >> N >> M >> G >> R;
    f(r, 0, N) {
        f(c, 0, M) {
            cin >> arr[r][c];
            if (arr[r][c] == ABLE) ableLoc.push_back({r,c});
        }
    }
    back_track(0);
    cout << ans;
}