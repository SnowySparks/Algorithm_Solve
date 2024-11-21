#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> table;
vector<bool> visited;

void print() {
    for (int i = 0 ; i < table.size(); ++i) {
        if (visited[i]) cout << table[i] << ' ';
    } cout << '\n';
}

void dfs(int cnt, int idx , int N, int M) {
    if (cnt == M) {print(); return;}
    for (int i = idx ; i < N ; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        dfs(cnt+1, i+1, N, M);
        visited[i] = false;
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int k, inp1;
    while(true) {
        cin >> k; if (k==0 ) break;
        for (int i = 0 ; i < k ; i++) {
            cin >> inp1; 
            table.push_back(inp1);
            visited.push_back(false);
        }
        dfs(0,0,k,6); cout <<'\n';
        table.clear(); visited.clear();
    }
    return 0;
}

