#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

struct Ship
{
    int id, p, r, v; //id, 공격력, 재장전 시간, 업뎃 버전 정보
    Ship(int id = 0, int p = 0, int r = 0, int v = 0) : id(id), p(p), r(r), v(v) {}
    bool operator<(const Ship &other) const {
        if (p == other.p) return (id > other.id);
        return p < other.p;
    }
};


int N;
unordered_map<int, Ship> idinfo; // id 정보
unordered_map<int, int> verinfo; //업데이트 버전 정보
unordered_map<int, bool> ready; //장전상태
priority_queue<pii, vector<pii>, greater<pii> > reloadList; // 장전 필요 (장전되는 시간, id)
priority_queue<Ship> able; // 공격 목록

void init();
void add();
void change(int id);
void shoot(int t);
void pre(int t);


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int T, id; cin >> T;
    int cmd;
    for (int t = 1; t <= T; ++t) {
        pre(t);
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
            cin >> id;
            change(id);
            break;
        case 400:
            shoot(t);
            break;
        }
    }

    return 0;
}

void init() {
    cin >> N;
    int id, p, r;
    for (int i = 0; i < N; ++i) {
        cin >> id >> p >> r;
        idinfo[id] = Ship(id, p, r, 1);
        verinfo[id] = 1;
        ready[id] = true;
        able.push(idinfo[id]);
    }
}

void add() {
    int id, p, r;
    cin >> id >> p >> r;
    idinfo[id] = Ship(id, p, r, 1);
    verinfo[id] = 1;
    ready[id] = true;
    able.push(idinfo[id]);
}


void change(int id) {
    int pw; cin >> pw;
    if (idinfo[id].p == pw) return; //동일하면 의미가 없음
    verinfo[id]++;
    idinfo[id].p = pw;
    idinfo[id].v++;
    
    if (ready[id] == true) {
        able.push(idinfo[id]);
    }
}

void pre(int t) {
    while (!reloadList.empty() && reloadList.top().first <= t)
    {
        int id = reloadList.top().second;
        able.push(idinfo[id]);
        reloadList.pop();
        ready[id] = true;
    }
    
}

void shoot(int t) {
    vector<int> shootList;
    int totalDamage = 0;
    while (!able.empty() && shootList.size() < 5)
    {
        Ship ship = able.top(); able.pop();

        if (ship.v != verinfo[ship.id]) {
            continue;
        }
        shootList.push_back(ship.id);
        totalDamage += ship.p;
    }
    for (int id : shootList) {
        ready[id] = false;
        reloadList.push({idinfo[id].r + t, id});
    }

    sort(shootList.begin(), shootList.end(), [](const int a, const int b) {
        if (idinfo[a].p == idinfo[b].p) return a < b;
        return idinfo[a].p > idinfo[b].p;
    });

    cout << totalDamage << ' ' << shootList.size();
    for (int id : shootList) {
        cout << ' ' << id;
    }
    cout << '\n';
    return;
}