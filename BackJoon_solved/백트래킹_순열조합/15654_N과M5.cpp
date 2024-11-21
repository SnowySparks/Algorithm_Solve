#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dt;
vector<bool> visited;
vector<int> tb;

void print() {
    for (auto e : tb) {cout << e << ' ';}
    cout <<'\n';
}

void dfs(int cnt, int N, int M) {
    if (cnt == M) {print(); return; }

    for (int i = 0 ; i < N ; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        tb.push_back(dt[i]);
        dfs(cnt+1, N, M);
        tb.pop_back();
        visited[i] = false;
    }
    
}

int main(void) {
    int N, M; cin >> N >> M;
    int temp;
    for (int i = 0; i < N; i++) {cin >> temp; 
    dt.push_back(temp);
    visited.push_back(false);
    }
    sort(dt.begin(), dt.end());

    dfs(0,N,M);

}