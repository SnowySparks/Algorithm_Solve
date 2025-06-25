#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int N, Q;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> N >> Q;
    vector<set<int> > S(N+1);
    for (int i = 1; i <= N; ++i) {
        int len; cin >> len;
        for (int j = 0; j < len; ++j) {
            int tmp; cin >> tmp;
            S[i].insert(tmp);
        }
    }

    int cmd, a, b;
    for (int q=0; q < Q; ++q) {
        cin >> cmd;

        switch (cmd)
        {
        case 1:
            cin >> a >> b;
            // 항상 작은 것이 -> 큰쪽으로 넘어가도록
            if (S[a].size() < S[b].size()) swap(S[a], S[b]);
            for (int bitem : S[b]) {
                S[a].insert(bitem);
            }
            S[b].clear();
            break;
        
        case 2:
            cin >> a;
            cout << S[a].size() << '\n';
            break;
        }
    }

    return 0;
}