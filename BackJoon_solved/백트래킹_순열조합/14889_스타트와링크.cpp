#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int table[21][21];
int min_sum = 200000000;
vector<int> sv;
vector<bool> sv_b;

void solve(int N) {
    int start = 0, rink = 0;
    vector<int> st, rn;
    for (int i = 0 ; i < N ; i++) {
        if (sv_b[i]) st.push_back(i+1);
        else rn.push_back(i+1);
    }
    for (int i = 0 ; i < N/2 ; i++) {
        for (int j = i+1 ; j < N/2 ; j++) {
            start += (table[st[i]][st[j]] + table[st[j]][st[i]]);
            rink += (table[rn[i]][rn[j]] + table[rn[j]][rn[i]]);
        }
    }
    min_sum = min( min_sum, abs(start-rink)); 
}

void dfs(int cnt ,int idx, int N) {
    if (cnt == N/2) {solve(N); return;}
    for (int i = idx ; i < N ; i++) {
        if (sv_b[i]) continue;
        sv_b[i] = true;
        dfs(cnt+1, i+1, N);
        sv_b[i] = false;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    for (int i = 1; i <= N ; i++) {
        sv.push_back(i);
        sv_b.push_back(false);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> table[i][j];
        }
    }
    dfs(0,0,N);
    cout << min_sum;
    return 0;
}