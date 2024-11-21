#include <iostream>
#include <unordered_map>
using namespace std;

int inv[20];
int _2n[20];
int cnt = 0;
bool flag = false; // 불가능함 판별 여부

void dfs(int l, int w, int h) { //현재 l, w, h 영역에서 가능한 최대한 박스 채우기
    if (l <= 0 || w <= 0 || h <= 0) return;
    if (flag) return;
    flag = false;
    int len = 0;
    for (int i = 19 ; i >= 0 ; i--) {
        if (inv[i]==0) continue;
        len = _2n[i];
        if ( l >= len && w >= len && h >= len) {
            cnt++;
            inv[i]--;
            flag = true;
            break;
        }
    }

    if (!flag) {
        cout << "-1";
        exit(1);
    }

    dfs(l,w,h-len);
    dfs(l-len,w,len);
    dfs(l-len,w-len,len);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    _2n[0] = 1;
    int l, w, h, n;
    cin >> l >> w >> h; cin >> n;
    for (int i = 0 ; i < n; i ++) {
        int a, b; cin >> a >> b;
        inv[a] = b;
    }
    for (int i = 1 ; i < 20; i++) _2n[i]=_2n[i-1]*2;

    dfs(l,w,h);
    cout << cnt;
    return 0;
}