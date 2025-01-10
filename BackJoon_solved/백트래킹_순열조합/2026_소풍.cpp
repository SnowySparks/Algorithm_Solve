#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define f(a, b, c) for(int a = b; a < c; ++a)
using namespace std;
int k, n, F;
const int MAXN = 901;
vector<int> track; //백트용
bool isFriend[MAXN][MAXN];

void back_track(int cur) {
    if (track.size() == k) {
        for (int &fr : track) cout << fr << '\n';
        exit(0);
        return;
    }
    f(i, cur+1, n+1) {
        bool canFriend =true;
        if (isFriend[cur][i]) {
            for (int &fr: track) {
                if (!isFriend[i][fr]) {
                    canFriend = false;
                    break;
                }
            }
            if (canFriend) {
                track.push_back(i);
                back_track(i);
                track.pop_back();
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> k >> n >> F;
    int a, b;
    f(i, 0, F) {
        cin >> a >> b;
        isFriend[a][b] = true;
        isFriend[b][a] = true;
    }

    f(i, 1, n) {
        track.push_back(i);
        back_track(i);
        track.pop_back();
    }
    cout << -1;
    return 0;
}