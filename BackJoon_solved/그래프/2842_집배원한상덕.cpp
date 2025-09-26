#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; ++a)
typedef pair<int ,int> pii;

const int mv[8][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
    {1, 1},
    {-1, -1},
    {1, -1},
    {-1, 1}
};

int n = 0;
char village[50][51];
int height[50][50];
pii startLoc;
bool isEnd[50][50];
bool visited[50][50];
int totalKCnt = 0;
vector<int> heightList;
vector<int> uniqueHeightList;
int ans = 0;

void input();
bool isVisitAllK(int l, int r);
void simulation();

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    input();
    simulation();
    cout << ans;
}

bool isVisitAllK(int low, int high) {
    int visitKCnt = 0;
    int startHeight = height[startLoc.first][startLoc.second];
    memset(visited, 0, sizeof(visited));

    if (startHeight < low || startHeight > high) {
        return false;
    }

    queue<pii> q; q.push(startLoc);
    while (!q.empty())
    {
        int r = q.front().first, c = q.front().second;
        q.pop();
        for (auto [dr, dc] : mv) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
            if (visited[nr][nc]) continue;
            if (height[nr][nc] < low || height[nr][nc] > high) continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    f(i, 0, n) {
        f(j, 0, n) {
            if (isEnd[i][j] && visited[i][j]) ++visitKCnt;
        }
    }
    return visitKCnt == totalKCnt;
}

void input() {
    cin >> n;

    f(i, 0, n) {
        cin >> village[i];
        f(j, 0, n) {
            if (village[i][j] == 'P') startLoc = make_pair(i, j);
            else if (village[i][j] == 'K') {
                isEnd[i][j] = true;
                totalKCnt++;
            }
        }
    }

    f(i, 0, n) {
        f(j, 0, n) {
            cin >> height[i][j];
            heightList.push_back(height[i][j]);
        }
    }
    sort(heightList.begin(), heightList.end());
    for (int val : heightList) {
        if (uniqueHeightList.empty() || uniqueHeightList.back() != val) uniqueHeightList.push_back(val);
    }

    //가장 큰 피로도 셋팅
    ans = heightList.back() - heightList.front();
}


void simulation() {
    int startHeight = height[startLoc.first][startLoc.second];

    int lidx = 0, ridx = 0;
    while (ridx < uniqueHeightList.size())
    {
            bool result = isVisitAllK(uniqueHeightList[lidx], uniqueHeightList[ridx]); 

            if (result) ans = min(ans, uniqueHeightList[ridx] - uniqueHeightList[lidx]);
            
            if (lidx == ridx || !result) ridx++;
            else lidx++;
    }
    
}