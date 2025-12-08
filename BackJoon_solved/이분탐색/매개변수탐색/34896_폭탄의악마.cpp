#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
const int inf = 1e9 + 7;
using namespace std;

int n, b;

struct Bomb {
    int x, c;
};
vector<Bomb> bombs;

void init(vector<Bomb> &bombs) {
    cin >> n;
    bombs.resize(n);
    for (Bomb &bomb : bombs) cin >> bomb.x;
    for (Bomb &bomb : bombs) cin >> bomb.c;
    sort(bombs.begin(), bombs.end(),[](const Bomb &a, const Bomb &b){
        return a.x < b.x;
    });
    cin >> b;
}

bool cal(int r, int maxCost) {
    int leftCost = maxCost; // 남은비용
    int ans = inf;

    vector<Bomb>::iterator it = bombs.begin();
    ++it;
    int lowCost = bombs.front().c; //
    int maxReach = bombs.front().x + r;
    for (;it != bombs.end(); ++it) {
        if (next(it) == bombs.end()) {
            if (it->x > maxReach) {
                leftCost -= lowCost;
                leftCost -= it->c;
            }
            else {
                leftCost -= min(lowCost, it->c);
            }
            break;
        }
        if (it->x > maxReach) {
            leftCost -= lowCost;
            if (leftCost < 0) break;

            lowCost = it->c;
            maxReach = it->x + r;
        }
        else {
            maxReach = it->x + r;
            lowCost = min(lowCost, it->c);
        }
    }

    return leftCost >= 0; // 음수 -> 불가능
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);

    init(bombs);
    int l = 1, r = bombs.back().x - bombs.front().x;

    int ans = r;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        bool res = cal(mid, b);
        if (res) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;

        }
    }
    cout << ans;

    return 0;
}