#include <iostream>
#include <vector>
#include <algorithm>
#define inf 1<<30
using namespace std;
int cd[2]; //n, m
int lst[2][20];
bool visited[20];
int k;
//밥 앨리스 각각 원 카드들
vector<int> bdt; //백트랙킹 저장용
//백트래킹 관한 모든
vector<int> addlst[2];

void act(int loc) {
    int sum = 0;
    for (auto e :bdt) sum += e;
    addlst[loc].push_back(sum);
}

void backtrack(int cnt, int idx, int N, int loc) {
    if (cnt == k) {act(loc); return;}
    for (int i = idx; i < N; i++) {
        bdt.push_back(lst[loc][i]);
        backtrack(cnt+1, i+1,N,loc);
        bdt.pop_back();
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    int temp;
    while(T--) {
        cin >> cd[0] >> cd[1] >> k;
        for (int i = 0; i < cd[0]; i++){ cin >> lst[0][i];}
        for (int k = 0; k < cd[1]; k++){ cin >> lst[1][k];}
        backtrack(0,0,cd[0],0);
        backtrack(0,0,cd[1],1);
        sort(addlst[0].begin(), addlst[0].end());
        sort(addlst[1].begin(), addlst[1].end());

        int maxv = max(abs(addlst[0].front() - addlst[1].back()) , abs(addlst[0].back() - addlst[1].front()));
        int minv = inf;
        for (int p = 0; p < addlst[0].size(); p++) {
            auto it = lower_bound(addlst[1].begin(), addlst[1].end(),addlst[0][p]);

            if (it != addlst[1].end()) minv = min(minv, abs(*it - addlst[0][p]));
            if (it != addlst[1].begin()) minv = min(minv, abs(*(it-1) - addlst[0][p]));
            if (minv == 0) break;
        }
        cout << minv << ' ' << maxv << '\n';
        addlst[0].clear();
        addlst[1].clear();
    }
    return 0;
}