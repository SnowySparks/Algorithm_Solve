#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[51]; //유니온파인드
bool know_true[51]; //처음부터 알고 있는 사람

int _find(int a) {
    if (a == parent[a]) return a;
    return parent[a] = _find(parent[a]);
}

void _union (int a, int b) {
    int pa = _find(a), pb = _find(b);
    if (pa == pb) return;

    if (know_true[pa]) {
        parent[pb] = pa;
    }
    else if (know_true[pb]) {
        parent[pa] = pb;
    }
    else {
        parent[max(pa,pb)] = min(pa,pb);
    }
}

int main() {
    int N, M; cin >> N >> M; //사람수 파티인원
    int know_truep; cin >> know_truep;
    int temp;
    for (int i = 0; i < know_truep; i++) {
        cin >> temp;
        know_true[temp] = true;
    }
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    int answer = M;
    vector<vector<int> > tp(M);
    for (int i = 0 ; i < M ; i++) {
        int cnt; cin >> cnt;
        for (int j = 0; j < cnt ; j++) {
            cin >> temp;
            tp[i].push_back(temp);
            if (j > 0) _union(tp[i][j-1],tp[i][j]);
        }
    }

    for (int i = 0 ; i < M ; i++) {
        if (know_true[ _find(tp[i][0]) ] ) answer--;
    }
    cout << answer ; return 0;
}