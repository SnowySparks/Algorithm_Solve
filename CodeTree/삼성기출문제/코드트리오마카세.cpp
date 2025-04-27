#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <vector>
using namespace std;
#define f(a, b, c) for(int a=b; a<c; ++a)
using pii = pair<int, int>;

int L, Q;
unordered_map<string, int> nameToIdx; //이름 -> 이름인덱스
int guestLoc[15010]; //해당 손님(이름인덱스)가 있는 위치
priority_queue<pii, vector<pii>, greater<> > eatSusie; //먹히는 스시 (먹히는 시간, 먹히는 사람 인덱스)
vector<pii> waitSusie[15010]; // 아직 손님 잆는 경우 등록하는 스시(등록시간, 그때 위치)
int remainEatSusieCnt[15010]; // 해당 손님이 먹어야 하는 스시 수
int remainGuestCnt = 0; // 남아있는 게스트 수
int totalSusieCnt = 0; // 현재 남아있는 토탈 스시 수 (회전 하고 있는)

int nameIdx(const string &name) {
    if (nameToIdx.find(name) == nameToIdx.end()) {
        nameToIdx[name] = nameToIdx.size();
    }
    return nameToIdx[name];
}

int t, x, n; string name;

// 해당 손님이 더이상 스시먹을 필요가 없는 경우에 대한 처리
void removeGuest(int idx) {
    if (remainEatSusieCnt[idx] == 0) {
        remainEatSusieCnt[idx] = -1;
        guestLoc[idx] = -1;
        remainGuestCnt--;
    }
}

// 스시 시물레이션
void simulationSusie(int nowTime) {
    while(!eatSusie.empty() && eatSusie.top().first <= nowTime) {
        remainEatSusieCnt[eatSusie.top().second]--;
        --totalSusieCnt;
        if (remainEatSusieCnt[eatSusie.top().second] == 0) {
            removeGuest(eatSusie.top().second);
        }
        eatSusie.pop();
    }
}

// 스시 추가하기
void addSusie() {
    int idx = nameIdx(name);
    // 해당 게스트가 없다 -> 대기 목록에 두기
    if (guestLoc[idx] == -1) {
        waitSusie[idx].push_back({t, x});
        ++totalSusieCnt;
    }
    else {
        int needTime = (guestLoc[idx] - x + L)%L;
        // 같은위치 -> 즉시 먹기
        if (needTime == 0) {
            remainEatSusieCnt[idx]--;
            removeGuest(idx);
        }
        // 대기 목록에 두기
        else {
            eatSusie.push({needTime + t, idx});
            ++totalSusieCnt;
        }
    }
}

void addGuest() {
    int idx = nameIdx(name);
    remainGuestCnt++;
    remainEatSusieCnt[idx] = n;
    guestLoc[idx] = x;
    for (pii &susie : waitSusie[idx]) {
        int offsetTime = susie.first;
        int firstLoc = susie.second;

        int nowLoc = (firstLoc + (t - offsetTime)%L )%L;
        int needTime = (guestLoc[idx] - nowLoc + L)%L;

        if (needTime == 0) {
            remainEatSusieCnt[idx]--;
            removeGuest(idx);
            --totalSusieCnt;
        }
        else {
            eatSusie.push({needTime + t, idx});
        }
    }
    waitSusie[idx].clear();
}

void picture() {
    cout << remainGuestCnt << ' ' << totalSusieCnt <<'\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    memset(guestLoc, -1, sizeof(guestLoc));
    memset(remainEatSusieCnt, -1, sizeof(remainEatSusieCnt));
    cin >> L >> Q;
    int cmd;
    f(q, 1, Q+1) {
        cin >> cmd >> t;
        simulationSusie(t);
        switch (cmd)
        {
        case 100:
            cin >> x >> name;
            addSusie();
            break;
        case 200:
            cin >> x >> name >> n;
            addGuest();
            break;
        case 300:
            picture();
            break;
        }
    }
    return 0;
}
