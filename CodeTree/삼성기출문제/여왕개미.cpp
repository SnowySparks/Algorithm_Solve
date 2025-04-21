#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define f(a, b, c) for(int a=b; a<c; ++a)
using namespace std;
int N; // 누적된 총 개미집 수
int home[20001]; // i 번 개미집
bool isBroken[20001]; // i번개미집은 철거되었는가?
const int inf = 1e9 + 7;

void input() {
    cin >> N;
    f(i, 1, N+1) cin >> home[i];
}

void construct(int p) {
    home[++N] = p;
}

void remove(int q) {
    isBroken[q] = true;
}

int search(int workerAnt) {
    int res = inf; //최소 이동 거리
    int l = 0, r = inf - 7; // 개미가 이동 제약 거리 범위. (단 아에 이동 안해도 되는 경우도 고려)
    int st = -1, ed = -1;
    while (l < r)
    {
        int cnt = 0; //이분탐색상 필요한 개미 수
        int maxMoveLength = 0; //이동 거리 최대
        int mid = (l + r) >> 1;
        st = -inf; ed = -inf;
        f(idx, 1 , N+1) {
            if (isBroken[idx]) continue;
            if (home[idx] - st > mid) {
                if (++cnt >  workerAnt) break; //더 많은 개미필요 -> 즉각 탐색 종료
                maxMoveLength = max(maxMoveLength, ed-st);
                st = home[idx];
                ed = home[idx];
            }
            else {
                ed = home[idx];
            }
        }
        maxMoveLength = max(maxMoveLength, ed-st);

        if (cnt > workerAnt) {
            l = mid + 1;
        }
        else {
            r = mid;
            res = min(res, maxMoveLength);
        }
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int Q; cin >> Q;
    int p, q, r;
    f(query, 1, Q+1) {
        int cmd;
        cin >> cmd;
        switch (cmd)
        {
        case 100:
            input();
            break;
        case 200:
            cin >> p;
            construct(p);
            break;
        case 300:
            cin >> q;
            remove(q);
            break;
        case 400:
            cin >> r;
            cout << search(r) << '\n';
        default:
            break;
        }
    }

    return 0;
}