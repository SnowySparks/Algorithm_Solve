#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define f(a ,b, c) for(int a=b; a<c; ++a)
int n;
int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int arr[100][100];
bool v[100][100];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int minArea = (n*n + 1) >> 1; // 탐색 결과 최소 이것보단 커야 함
    f(i, 0, n) f(j, 0, n) cin >> arr[i][j];
    queue<pair<int ,int> > q;
    // paramete-search : 차이값
    int l = 0, r = 1e6;
    
    int ans_Value = 0;
    while (l <= r) {
        int mid = (l + r) >> 1; //주변 위치와 차이값의 최대 한계값
        memset(v, 0, sizeof(v));
        int current_Area = 0;
        bool isPossible = false; // 해당 결과 - 
        f(i, 0, n) f(j, 0, n) {
            current_Area = 1;
            if (!v[i][j]) {
                v[i][j] = true;
                q.push({i, j});

                while (!q.empty())
                {
                    auto [cr, cc] = q.front(); 
                    q.pop();
                    for (auto &[dr, dc] : mv) {
                        int nr = cr + dr, nc = cc + dc;
                        if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                        if (v[nr][nc] || abs(arr[cr][cc] - arr[nr][nc]) > mid) continue;
                        q.push({nr, nc});
                        v[nr][nc] = true;
                        ++current_Area;
                    }
                }
                // cout << mid <<' ' << current_Area << '\n';
                if (current_Area >= minArea) {
                    isPossible = true;
                    break;
                }
            }
        }
        if (isPossible) {
            // cout << "possible : " << mid << '\n';
            ans_Value = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans_Value;
    return 0;
}