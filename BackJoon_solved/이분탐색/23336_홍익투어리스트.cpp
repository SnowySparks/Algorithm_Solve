#include <iostream>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;
int n, q;
set<int> sights;

void toggle(int loc) {
    set<int>::iterator it = sights.find(loc);

    if (it == sights.end()) {
        sights.insert(loc);
    }
    else {
        sights.erase(it);
    }
}

int needMinMove(int loc) {
    // 없음
    if (sights.size() == 0) return -1;

    set<int>::iterator lower_it = sights.lower_bound(loc);

    //자기자리가 명소인가
    if (*lower_it == loc) {
        return 0;
    }

    //현재 위치 이후부터 N까지 위치 중 명소가 없는 경우
    if (lower_it == sights.end()) {
        return n - loc + *(sights.begin());
    }
    
    int sight = *lower_it;
    return sight - loc;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        int tmp; cin >> tmp;
        if (tmp) sights.insert(i);
    }
    int cmd;
    int i, x;
    int nowLoc = 1;
    while (q--)
    {
        cin >> cmd;
        switch (cmd)
        {
        case 1:
            cin >> i;
            toggle(i);
            break;
        case 2:
            cin >> x;
            nowLoc = (nowLoc - 1 + x) % n + 1;
            break;
        case 3:
            cout << needMinMove(nowLoc) << '\n';
            break;
        }
    }
    
    return 0;
}