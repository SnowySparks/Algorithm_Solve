#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define FISH_DIR_CNT 8

int M, S;
int fish_mv[8][2] = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
int shark_mv[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
string mv[8]={"←", "↖", "↑", "↗", "→", "↘", "↓", "↙"};

int fish_map[4][4][8]; // fish (r, c)위치 + 방향에 따른 데이터 -> 실질적인 물고기 있는 데이터
int fish_temp_move[4][4][8]; //물고기 이동에 대해서 기록을 저장하는 곳
int fish_copy_map[4][4][8]; // 물고기 복제용
int fish_cnt[4][4]; // 물고기 수 카운팅
int fish_smell[4][4]; // 해당 위치에 마지막으로 뿌려진 물고기 냄새 시간(때), 단 -1 의미는 아에 냄새가 없다는 뜻이 됨
int shark_r, shark_c; //상어의 위치
int simulationTime = 0; // 시물레이션 시간

int shark_loc[3][2]; // 상어 이동방향에 따른 기록

// 물고기 출력
void output() {
    for (int r= 0; r <4; ++r) {
        for (int c = 0; c < 4; ++c) {
            for (int d = 0; d < 8; ++d) {
                if (!fish_map[r][c][d]) continue;
                cout << r+1 <<' ' << c+1 << ' ' << mv[d] << ':' << fish_map[r][c][d] <<'\n';
            }
            cout <<"--\n";
        }
    }

    for (int r= 0; r <4; ++r) {
        for (int c = 0; c < 4; ++c) {
            cout << fish_cnt[r][c] <<'\t';
        }
        cout << '\n';
    }
    for (int r= 0; r <4; ++r) {
        for (int c = 0; c < 4; ++c) {
            cout << fish_smell[r][c] <<'\t';
        }
        cout << '\n';
    }
}

// 해당 위치가 안에 있는가?
bool isIn(int r, int c) {
    if (r < 0 || c < 0 || r >= 4 || c >= 4) return false;
    return true;
}

// 해당 위치로 물고기가 이동할 수 있는가
bool isFishCanGo(int r, int c) {
    if (!isIn(r, c)) return false; // 영역밖인가
    else if (shark_r == r && shark_c == c) return false; //상어가 있음
    else if (fish_smell[r][c] != -1 && simulationTime - fish_smell[r][c] <= 2) return false; // 냄새가 안 사라졌는지
    else return true;
}

// 상어 이동 방향 시물레이션 -> 가장 최고의 상태인 방향을
void best_shark_move_simulation() { 
    int nr1, nc1, nr2, nc2, nr3, nc3; 
    int eatenFishCnt = -1; // 아무것도 못먹을때를 고려한 값.
    for (int d1 = 0; d1 < 4; ++d1) {
        // 첫번째 상어의 이동
        nr1 = shark_r + shark_mv[d1][0]; nc1 = shark_c + shark_mv[d1][1];
        if (!isIn(nr1, nc1)) continue;

        for (int d2 = 0; d2 < 4; ++d2) {
            // 두번째 상어의 이동
            nr2 = nr1 + shark_mv[d2][0]; nc2 = nc1 + shark_mv[d2][1];
            if (!isIn(nr2, nc2)) continue;

            for (int d3 = 0; d3 < 4; ++d3) {
                // 세번째 상어의 이동
                nr3 = nr2 + shark_mv[d3][0]; nc3 = nc2 + shark_mv[d3][1];
                if (!isIn(nr3, nc3)) continue;

                // 여기까지 이동이 가능 할 때 테스트, 단 중복계산주의 (상어가 되돌아갈 가능성도 있음)
                int cnt = fish_cnt[nr1][nc1];
                if ((nr1!=nr2 || nc1!=nc2)) {
                    cnt += fish_cnt[nr2][nc2];
                }
                if ((nr1!=nr3 || nc1!=nc3) && (nr2!=nr3 || nc2!=nc3) ) {
                    cnt += fish_cnt[nr3][nc3];
                }

                if (cnt > eatenFishCnt) {
                    eatenFishCnt = cnt;
                    shark_loc[0][0] = nr1;
                    shark_loc[0][1] = nc1;
                    shark_loc[1][0] = nr2;
                    shark_loc[1][1] = nc2;
                    shark_loc[2][0] = nr3;
                    shark_loc[2][1] = nc3;
                }
            }
        }
    }
}

// 상어 이동
void shark_move() {
    shark_r = shark_loc[2][0]; shark_c=shark_loc[2][1];
    for (auto [r, c] : shark_loc) {
        // 냄새 등록 밑 카운팅
        if (fish_cnt[r][c]) {
            memset(fish_map[r][c], 0, sizeof(fish_map[r][c]));
            fish_smell[r][c] = simulationTime;
            fish_cnt[r][c] = 0;
        }
    }
}

void fish_move() {
    // 2. 물고기 이동
    memset(fish_temp_move, 0, sizeof(fish_temp_move)); // 기록을 위한 공간 초기화
    memset(fish_cnt, 0, sizeof(fish_cnt)); // 해당 위치 물고기 수 초기화
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            for (int d = 0; d < 8; ++d) {
                if (!fish_map[r][c][d]) continue; // 물고기가 없는 경우 무시
                int move_dir = d; // 물고기 바라보는 방향. -> 갈 수 없으면 반시계회전기록용
                bool isMove = false; // 물고기가 이동했는가?
                for (int cntDir = 0; cntDir < 8; ++cntDir) {
                    // 반시계방향으로 회전하면서 이동
                    move_dir = (d - cntDir + FISH_DIR_CNT)%FISH_DIR_CNT;
                    int nr = r + fish_mv[move_dir][0], nc = c + fish_mv[move_dir][1];
                    if (isFishCanGo(nr, nc)) {
                        fish_temp_move[nr][nc][move_dir] += fish_map[r][c][d];
                        isMove = true;
                        fish_cnt[nr][nc] += fish_map[r][c][d];
                        break;
                    }
                }

                // 물고기가 안 움직였을 경우에 대한 처리
                if (!isMove) {
                    fish_temp_move[r][c][d] += fish_map[r][c][d];
                    fish_cnt[r][c] += fish_map[r][c][d];
                }
            }
        }
    }
    memcpy(fish_map, fish_temp_move, sizeof(fish_map)); //물고기 이동 반영
    // cout <<"move\n";
    // output();
    // cout<< "\n------\n";
}

// 물고기 복제
void fish_copy() {
    for (int r= 0; r <4; ++r) {
        for (int c = 0; c < 4; ++c) {
            for (int d = 0; d < 8; ++d) {
                fish_map[r][c][d] += fish_copy_map[r][c][d];
                fish_cnt[r][c] += fish_copy_map[r][c][d];
            }
        }
    }
    memset(fish_copy_map, 0, sizeof(fish_copy_map));
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> M >> S; // 물고기, 연습 시간
    memset(fish_smell, -1, sizeof(fish_smell)); // 냄새기록, 단 -1 : 기록없음 의미
    int fx, fy, d;
    
    // 물고기 위치 등록
    for (int i = 0; i < M; ++i) {
        // 방향 및 위치 전부 -1를 입력함. (0부터 시작하기 위함)
        cin >> fx >> fy >> d;
        fx--; fy--; d--;
        fish_map[fx][fy][d]++;
        fish_cnt[fx][fy]++;
    }
    cin >> shark_r >> shark_c;
    shark_r--; shark_c--;

    // 실제 시물레이션 시간. 시물레이션이 "완료 될 때" t가 올라가는 식
    for (; simulationTime < S; ++simulationTime) {
        // cout << shark_r + 1 << ' ' <<shark_c + 1 << '\n';
        // 1. 복사
        memcpy(fish_copy_map, fish_map, sizeof(fish_copy_map));

        // 2. 물고기 이동
        fish_move();

        // 3. 상어 이동 및 물고기 존재
        best_shark_move_simulation();
        shark_move();

        // 4. 물고기 마법 복제
        fish_copy();
    }
    int answer = 0;
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            answer +=fish_cnt[r][c];
        }
    }
    // output();
    // cout << shark_r + 1 << ' ' <<shark_c + 1 << '\n';
    cout << answer;
    return 0;
}