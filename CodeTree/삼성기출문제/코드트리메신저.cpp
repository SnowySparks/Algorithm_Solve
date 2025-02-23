#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define f(a, b, c) for(int a=b; a<c; ++a)
using namespace std;
const int MAXN = 1e5+1;
int N, Q;
int p[MAXN]; // 부모 노드
int a[MAXN]; // 권한
int dp[MAXN][22]; //자기자신 노드 제외,i노드에서(그기준)j만큼 위로 더 올릴수 있는 알람
int val[MAXN];//자기자신 제외 알람받는 수
bool isoff[MAXN]; //채팅방 꺼졌는가? -> 더 위로 못 올림

void print(int node) {
    cout << "---" << node << "----\n";
    f(i, 0, N+1) {
        if (dp[node][i]) cout << i << ':' <<dp[node][i] <<'|';
    }
    cout << "\n----\n";
}

void change(int node, int authLevel, int value) {
    if (value == 0) return;
    while (node != 0 && !isoff[node] && authLevel > 0) {
        dp[p[node]][authLevel-1] += value;
        val[p[node]] += value;
        node = p[node];
        authLevel--;
    }
    return;
}

void init() {
    f(i, 1, N+1) cin >> p[i];
    f(i, 1, N+1) cin >> a[i];
    f(i, 1, N+1) a[i] = min(a[i],20);
    f(i, 1, N+1) change(i, a[i], 1);
    // f(i, 1, N+1) print(i);
}

void toggle(int c) {
    if (isoff[c]) {
        isoff[c] = false;
        f(lv, 1, 22) change(c, lv, dp[c][lv]);
        change(c, a[c], 1);
    }
    else {
        f(lv, 1, 22) change(c, lv, -dp[c][lv]);
        change(c, a[c], -1);
        isoff[c] = true;
    }
}

void changePower(int c, int power) {
    if (power > 20) power = 20;
    change(c, a[c], -1);
    change(c, power, 1);
    a[c] = power;
}

void swapParent(int c1, int c2) {   
    bool offc1 = isoff[c1];
    bool offc2 = isoff[c2];
    if (!offc1) toggle(c1);
    if (!offc2) toggle(c2);
    swap(p[c1], p[c2]);
    if (!offc1) toggle(c1);
    if (!offc2) toggle(c2);
}



int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    int c, c1, c2, power;
    int cmd;
    f(query, 1, Q+1) 
    {   
        cin >> cmd;
        switch (cmd)
        {
        case 100:
            init();
            break;
        case 200:
            cin >> c;
            toggle(c);
            break;
        case 300:
            cin >> c >> power;
            changePower(c, power);
            break;
        case 400:
            cin >> c1 >> c2;
            swapParent(c1, c2);
            break;
        case 500:
            cin >> c;
            cout << val[c] << '\n';
            break;
        default:
            break;
        }
    }

    return 0;
}
