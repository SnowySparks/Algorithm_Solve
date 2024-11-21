#include <iostream>
#include <vector>
#include <algorithm>
#define F(a,b,c) for(int a = b; a <= c; a++)
using namespace std;
int N;
long long ans_cost = 0;
int nc = 0;
int p[201];
vector<pair<int, pair<int ,int> > > v;
int find(int a) {
    if (p[a]==a) return a;
    return p[a] = find(p[a]);
}
bool _u(int a, int b) {
    int pa = find(a) , pb = find(b);
    if (pa == pb) return false;
    p[(max(pa,pb))] = min(pa,pb);
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int tp;
    F(i,1,N) p[i] = i;
    F(i,1,N) {
        F(k,1,N) {
            cin >> tp;
            if (i < k) {
                if (tp < 0) {
                    ans_cost-=tp;
                    _u(i,k);
                }
                else {
                    v.push_back({tp,{i,k}});
                }
            }
        }
    }
    sort(v.begin(),v.end());
    vector<pair<int, int> > ans_c;
    for (auto e : v) {
        if (_u(e.second.first,e.second.second)) {
            ans_cost += e.first;
            ans_c.push_back({e.second.first,e.second.second});
            nc++;
        }
    }
    cout << ans_cost <<' ' << nc<<'\n';
    for (auto e : ans_c) {
        cout << e.first << ' ' << e.second << '\n';
    }
    return 0;
}