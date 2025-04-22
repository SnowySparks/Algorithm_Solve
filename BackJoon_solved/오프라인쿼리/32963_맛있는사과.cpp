#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define f(a, b, c) for (int a=b; a<c; ++a)
const int MAXN = 2e5;
int N, Q;

struct Query {
    int idx, p, ans = 0;
};
struct Apple {
    int t, s;
};
Apple apple[MAXN];


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> N >> Q;
    map<int, int> sizeRecord; //사과 기록 (무게 : 개수)
    f(i, 0, N) cin >> apple[i].t;
    f(i, 0, N) {
        cin >> apple[i].s;
        sizeRecord[apple[i].s]++;
    }
    vector<Query> queries(Q);
    for (int i = 0; i < Q; ++i) {
        queries[i].idx = i;
        cin >> queries[i].p;
    }
    // 사과 정렬 : 맛없는 것 부터 우선으로(?)
    sort(apple, apple+N, [](const Apple &a, const Apple &b){
        return a.t < b.t;
    });
    // offline query -> 값이 작은 것부터 처리하자.
    sort(queries.begin(), queries.end(), [](const Query &a, const Query &b){
        return a.p < b.p;
    });

    int notQualifiedCnt = 0; //만족하지 못하는 사과 수

    for (Query &q : queries) {
        if (notQualifiedCnt == N) {
            q.ans = 0;
            continue;
        }

        // 만족하지 못하는 사과 맛 제거
        for (;notQualifiedCnt < N && apple[notQualifiedCnt].t < q.p; ++notQualifiedCnt) {
            sizeRecord[apple[notQualifiedCnt].s]--;
            if (sizeRecord[apple[notQualifiedCnt].s] == 0) {
                sizeRecord.erase(apple[notQualifiedCnt].s);
            }
        }
        if (sizeRecord.empty()) q.ans = 0;
        else q.ans = (*sizeRecord.rbegin()).second;
    }

    // 다시 입력순으로 정렬
    sort(queries.begin(), queries.end(), [](const Query &a, const Query &b){
        return a.idx < b.idx;
    });

    // 출력
    for (Query &q : queries) {
        cout << q.ans << '\n';
    }

    return 0;
}