#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define f(a ,b, c) for(int a=b; a<c; ++a)
int n, m;
int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int arr[100][100];
bool v[100][100];
vector<pair<int ,int> > ptsList; // 색칠된 곳 포인트

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    queue<pair<int ,int > > q;
    int tmp;
    f(i, 0, n) f(j, 0, m) cin >>arr[i][j];
    f(i, 0, n) f(j, 0, m) {
        cin >> tmp;
        if (tmp) ptsList.push_back({i, j});
    }

    int L = 0, R = 1e9;
    int ans = 0;
    while (L <= R)
    {
        int mid = (L + R) >> 1;
        memset(v, 0, sizeof(v));
        v[ptsList[0].first][ptsList[0].second] = true; //시작지점
        q.push(ptsList[0]);
        while (!q.empty())
        {
            auto [cr, cc] = q.front(); 
            q.pop();
            for (auto &[dr, dc] : mv) {
                int nr = cr + dr, nc = cc + dc;
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (v[nr][nc] || abs(arr[cr][cc] - arr[nr][nc]) > mid) continue;
                q.push({nr, nc});
                v[nr][nc] = true;
            }
        }
        bool isPossible = true;
        for (auto[r, c] : ptsList) {
            if (!v[r][c]) {
                isPossible = false;
                break;
            }
        }

        if (!isPossible) {
            L = mid + 1;
        }
        else {
            ans = mid;
            R = mid - 1;
        }
        
    }
    cout << ans;
    return 0;
}