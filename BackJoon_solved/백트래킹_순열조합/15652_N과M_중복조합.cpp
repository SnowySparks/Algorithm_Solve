#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//조합

vector<int> sv;
int dt[8] = {1,2,3,4,5,6,7,8};
bool visited[8];

void print(void) {
    for (auto e : sv) { cout << e << ' ';}
    cout << '\n';
}
void back_track(int cnt, int idx , int N, int M) {
    if (cnt == M) {print(); return;}
    for (int i = idx ; i < N ; i++) {
        sv.push_back(dt[i]);
        back_track(cnt+1, i, N, M);
        sv.pop_back();
    }
}
int main(void) {
    int N, M; cin >> N >> M;
    back_track(0,0,N,M);
    return 0;
}