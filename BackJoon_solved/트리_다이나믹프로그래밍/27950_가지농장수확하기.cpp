#include <iostream>
#include <vector>
// 틀렸으니 수정 필요
using namespace std;
using pii = pair<int,int>;
#define f(a,b,c) for(int a=b; a<c; a++)

int N;
vector<int> dt[10001];
bool v[10001] = {false,};
pii r[10001]; //super개수, 이동횟수

void dfs(int node) {
    v[node] = true;
    if (dt[node].size()==1) {
        r[node].first = 1;
    }
    for (int e : dt[node]) {
        if (v[e]) continue;
        dfs(e);
        if (r[e].first > 3) r[node].second+= (r[e].first/3)*2 + (r[e].first%3==0?0:2) + r[e].second;
        else r[node].second+=r[e].second+2;
        r[node].first+= r[e].first;
    }
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    f (p,0,N-1) {
        int a,b;
        cin >>a >> b;
        dt[a].push_back(b);
        dt[b].push_back(a);
    }
    dfs(1);
    cout << r[1].second;
    return 0;
}