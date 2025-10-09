#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;

int N, M;
unordered_map<int ,int> idxToLoc;
set<int> lampLoc;

struct info {
    int loc1, loc2;
    bool operator<(const info &other) const {
        int myLen = abs(loc1-loc2);
        int otherLen = abs(other.loc1 - other.loc2);

        if (myLen == otherLen) {
            return min(loc1, loc2) > min(other.loc1, other.loc2);
        }
        return myLen < otherLen;
    }
};

priority_queue<info> pq;

void init() {
    cin >> N >> M;
    vector<int> lst(M);
    for (int i = 0; i < M; ++i) {
        cin >> lst[i];
        idxToLoc[i+1] = lst[i];
        lampLoc.insert(lst[i]);

        if (i) {
            pq.push({lst[i-1], lst[i]});
        }
    }
}

void pre() {
    while (!pq.empty()) {
        int a = pq.top().loc1;
        int b = pq.top().loc2;
        
        // 양 끝점 존재 검사
        if (!lampLoc.count(a) || !lampLoc.count(b)) {
            pq.pop();
            continue;
        }
        auto it = lampLoc.find(a);
        if (it == lampLoc.end()) { pq.pop(); continue; }
        auto nit = next(it);
        if (nit != lampLoc.end() && *nit == b) {
            // 진짜 인접한 쌍 -> valid
            break;
        }
        // 그 외(존재는 하지만 사이에 다른 가로등이 있음) -> 무효
        pq.pop();
    }
}

void add() {
    pre();
    int loc1 = pq.top().loc1;
    int loc2 = pq.top().loc2;
    int mid = (loc1 + loc2 + 1) >> 1;
    
    if (lampLoc.count(mid) || mid == loc1 || mid == loc2) return;
    pq.pop();

    lampLoc.insert(mid);
    idxToLoc[++M] = mid;
    pq.push({loc1, mid});
    pq.push({mid, loc2});

}

void del(int idx) {
    int loc = idxToLoc[idx];
    idxToLoc.erase(idx);
    lampLoc.erase(loc);

    set<int>::iterator it = lampLoc.upper_bound(loc);
    if (it == lampLoc.end()) return;
    if (it == lampLoc.begin()) return;
    
    set<int>::iterator beforeIt = prev(it);
    pq.push({*beforeIt, *it});
    pre();
}

int cal_r() {
    pre();
    int firstDist = (*lampLoc.begin() - 1) << 1;
    int lastDist = (N - *lampLoc.rbegin() ) << 1;
    int midDist = abs(pq.top().loc2 - pq.top().loc1);
    return max(midDist, max(firstDist, lastDist));
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int cmd, D, Q;
    cin >> Q;

    for (int query = 1; query <= Q; ++query) {
        cin >> cmd;
        switch (cmd)
        {
            case 100:
               init();
               break;
            case 200:
                add();
                break;
            case 300:
                cin >> D;
                del(D);
                break;
            case 400:
                cout << cal_r() << '\n';
                break;
        }
    }
}