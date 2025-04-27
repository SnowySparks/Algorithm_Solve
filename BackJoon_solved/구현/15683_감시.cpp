#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int ,int> pii;
#define f(a, b, c) for(int a=b; a<c; ++a)
#define WALL 6
const int mv[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};

const int maxSpin[6] = {
    0, 4, 2, 4, 4, 1
};

int ans = 1000000;

const int cctvLoc[6][4] {
    {0, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 1, 0},
    {1, 0, 0, 1},
    {1, 0, 1, 1},
    {1, 1, 1, 1},
};

int cctvSpinState[8] = {0, };

int n, m;
vector<pii> cctvs;
int arr[8][8];
bool isWatched[8][8];

void calc() {
    int res = 0;
    f(i, 0, n) {
        f(j, 0, m) {
            if (!isWatched[i][j] && arr[i][j] != WALL) ++res;
        }
    }
    ans = min(ans, res);
}

void toggle(int sr, int sc, int dir) {
    int nr = sr, nc = sc;
    while (true)
    {
        if (nr < 0 || nc < 0 || nr >= n || nc >= m) break;
        if (arr[nr][nc] == WALL) break;
        isWatched[nr][nc] = true;
        nr += mv[dir][0];
        nc += mv[dir][1];
        // cout << nr << ' ' << nc << '\n';
    }
    
}

void simulation() {
    f(i, 0, cctvs.size()) {
        int cctv = arr[cctvs[i].first][cctvs[i].second]; //ccty type
        int spin = cctvSpinState[i]; //cctv spin state
        f(j, 0, 4) { // 4방향 
            int dir = (spin + j)%4; //스핀반영
            if (cctvLoc[cctv][dir]) {
                toggle(cctvs[i].first,cctvs[i].second,j);
            }
        }
    }
}

void back_track(int loc) {
    if (loc == cctvs.size()) {
        memset(isWatched, 0, sizeof(isWatched));
        simulation();
        calc();
        return;
    }

    int cctv = arr[cctvs[loc].first][cctvs[loc].second]; //ccty type
    for (int j = 0; j < maxSpin[cctv]; ++j) {
        cctvSpinState[loc] = j;
        back_track(loc+1);
    }
    
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n >> m;
    f(i, 0, n) {
        f(j, 0, m) {
            cin >> arr[i][j];
            if (arr[i][j] >= 1 && arr[i][j] <= 5) {
                cctvs.push_back({i, j});
            }
        }
    }
    back_track(0);
    cout << ans;

    return 0;
}