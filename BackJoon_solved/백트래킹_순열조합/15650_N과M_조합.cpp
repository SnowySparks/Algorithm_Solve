#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//조합

vector<int> sv;
bool visited[9];

void print(void) {
    for (int i = 0 ; i < 9 ; i++) {
        if (visited[i]) cout << i+1 << ' ';
    }
    cout << '\n';
}


void back_track(int cnt, int idx , int N, int M) {
    if (cnt == M) {print(); return;}
    for (int i = idx ; i < N ; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        back_track(cnt+1, i+1, N, M);
        visited[i] = false;
    }
}

int main(void) {
    int N, M; cin >> N >> M;
    back_track(0,0,N,M);
    return 0;
}