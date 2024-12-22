#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
using ll = long long;

const int max_n = 1e5;
const int max_m = 3e5;
int n, m;
ll arr[max_n + 1]; //몬스터 기본 난이도
bool isCatched[max_n + 1]; // 해당 몬스터는 이미 잡혀있는가?

priority_queue<pair<ll ,int> > pq; // ({-난이도, 잡은 몬스터})
vector<pair<int, ll> > need_item[max_n+1]; // need_item[아이템] {몬스터 번호, 추가 난이도}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);

    cin >> n >> m;
    int a, b ,t;
    for (int i = 1; i <= n; ++i) cin >> arr[i]; //기본 몬스터 난이도
    int p; cin >> p;
    for (int i = 0; i < p; ++i) {
        // 추가 난이도, 아이템 a가 없으면 몬스터 b의 난이도는 t만큼 올라간다
        cin >> a >> b >> t;
        arr[b]+=t;
        need_item[a].push_back({b, t});
    }

    for (int i = 1; i <= n; ++i) {
        pq.push({-arr[i], i });
    }
    int cnt = 0;
    ll max_difficulty = -1;

    ll difficulty;
    int monster_idx;

    while (!pq.empty() && cnt < m) {

        // 잡기
        tie(difficulty, monster_idx) = pq.top(); pq.pop();
        difficulty = -difficulty;
        if (isCatched[monster_idx]) continue; // 이미 잡힌 몬슨터에 대해서 더이상 다루지 않는다.
        isCatched[monster_idx] = true;
        max_difficulty = max(max_difficulty, difficulty);
        // cout << difficulty << ' ' << monster_idx << '\n';
        ++cnt;
        // 관련된 몬스터 난이도 낮추고 이를 반영하기
        for (pair<int, ll> items : need_item[monster_idx] ) {
            if (isCatched[items.first]) continue;
            arr[items.first] -= items.second;
            pq.push({-arr[items.first], items.first });
        }
    }
    cout << max_difficulty;

    return 0;
}