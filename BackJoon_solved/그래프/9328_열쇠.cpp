#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define f(a, b, c) for (int a = b; a < c; ++a)
using namespace std;

int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int h, w; //행 크기, 열 크기
char inp[102][102];
bool v[102][102];
int cnt = 0;
char inp_key[26];

// 방문 전 문 위치
vector<pair<int, int> > door_list[26];
bool unlock[26];

int main(void) {
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--)
    {
        // input. 맵 크기 및 맵 정보 입력
        cin >> h >> w;
        f(i, 1, h + 1) {scanf("%s", inp[i]+1);}
        f(i, 0, w + 2) {inp[0][i] = '.'; inp[h+1][i] ='.';}
        f(i, 0, h + 2) {inp[i][0] = '.'; inp[i][w+1] = '.';}

        f(i, 0, 26) door_list[i].clear();
        memset(unlock, 0, sizeof(unlock));
        memset(v, 0, sizeof(v));

        // 이미 열쇠가 존재한다면 열쇠 소유 표시
        scanf("%s", inp_key);
        if (inp_key[0] != '0') {
            for (int i = 0; i < 30; ++i) {
                if (inp_key[i] == '\0') break;
                unlock[inp_key[i]-'a'] = true;
            }
        }

        // 시작점을 0, 0 으로 두기
        int ans = 0;
        queue<pair<int ,int> > q;
        q.push({0, 0});
        v[0][0] = true;

        // 방문 "할" 장소에 대한 처리 방식으로 함
        // 즉 pop하고 나서 그 자리에 대한 처리가 아닌, nr, nc 구할 때 처리하는 방식
        while (!q.empty())
        {   
            int r = q.front().first, c =q.front().second; q.pop();

            for (auto &[dr, dc] : mv) {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nc < 0 || nr >= h+2 || nc >= w+2 || v[nr][nc] || inp[nr][nc] == '*') continue;
                if (inp[nr][nc] >= 'A' && inp[nr][nc] <= 'Z') {
                    // 해당 문에 대한 열쇠가 있으면 그냥 통과
                    int idx = inp[nr][nc] - 'A';
                    if (unlock[idx]) {
                        q.push({nr, nc});
                        v[nr][nc] = true;
                    }
                    // 아니면 일단 해당 문에 방문 자체는 가능하다는 거니 대기열에 추가
                    else {
                        door_list[idx].push_back({nr, nc});
                    }
                }

                // 열쇠 획득
                else if (inp[nr][nc] >= 'a' && inp[nr][nc] <= 'z') {
                    int idx = inp[nr][nc] - 'a';
                    q.push({nr, nc});
                    v[nr][nc] = true;
                    // 사용하지 않았던 열쇠면, 이때까지 방문했던 모든 문에 접근이 가능하니 
                    // 해당 자리에 다시 방문했다고 치는 처리
                    if (!unlock[idx]) {
                        unlock[idx] = true;
                        for (auto &[mr, mc] : door_list[idx]) {
                            q.push({mr, mc}); v[mr][mc] = true;
                        }
                    }
                }
                // 문서
                else if (inp[nr][nc] =='$') {
                    v[nr][nc] = true;
                    ans += 1;
                    q.push({nr, nc});
                }
                // 빈 공간
                else {
                    v[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}