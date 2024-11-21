#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define f(a, b, c) for (int a = b; a < c; ++a)
using namespace std;
int n, m;
const long long INF = 1e15;
int p[10001];
int rank[10001];  
long long weight[10001];

int parent(int x) {
    if (p[x] == x) return x;
    return p[x] = parent(p[x]);
}


void merge(int a, int b, int w) { 
    int pa = parent(a);
    int pb = parent(b);

    if (pa != pb) {
        if (rank[pa] < rank[pb]) {

        }
    }


}

// 아이디어. 가장 최상단 부모 기준 얼마나 차이 나는가?를 담으면 될 듯 함
// 단 처음엔 정보를 모르니, 정보를 모르는 상태인 것도 고려를 해야 할 듯

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    int a, b, c;
    vector<int> query;
    char cmd;
    f(tc, 1, T+1) {
        cin >> n >> m;
        f(i, 1, n+1) p[i] = i;
        query.clear();
        f(tt, 1, m + 1) {
            cin >> cmd;
            if (cmd == '!') {
                cin >> a >> b >> c;
                merge(a, b, c);
            }
        }
    }
    return 0;
}