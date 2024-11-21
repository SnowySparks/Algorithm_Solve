#include <iostream>
#include <vector>  
#include <algorithm>
using namespace std;

int pre[1001], in[1001], inidx[1001];

void dfs(int inl, int inr, int prel, int prer) {
    if (inl > inr || prel > prer) return;
    int root_inindx = inidx[pre[prel]];
    int left_size = root_inindx - inl;
    dfs(inl, root_inindx,prel+1,prel+left_size);
    dfs(root_inindx+1,inr,prel+1+left_size,prer);
    cout << in[root_inindx] <<' ';
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    int N;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> pre[i];
        }
        for (int i = 1 ; i <= N; i++) {
            cin >> in[i];
            inidx[in[i]] = i;
        }
        dfs(1,N,1,N);
        cout << '\n';
    }
    return 0;
}