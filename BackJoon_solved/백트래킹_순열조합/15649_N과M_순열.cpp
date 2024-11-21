#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//순열

vector<int> sv;
bool visited[9];
int arr[9];

void print(void) {
    for (auto e : sv) {
        cout << e <<' ';
    } 
    cout << '\n';
}

void dfs(int cnt, int N, int M) {
    if (cnt == M) { print(); return; }

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue; 
        visited[i] = true;
        sv.push_back(arr[i]);
        dfs(cnt+1,N,M);
        sv.pop_back();
        visited[i] = false;
    }
}

int main(void) {
    int N, M; cin >> N >> M;

    for (int i = 0; i < N; i++) {
        arr[i] = i+1;
    }
    dfs(0,N,M);
    return 0;
}