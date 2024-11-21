#include  <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sv;
int dt[] = {1,2,3,4,5,6,7};

void print() {
    for (auto e : sv) cout << e << ' ';
    cout << '\n';
}

void dfs (int cnt, int N , int M) {
    if (cnt == M) {
        print();
        return;
    }

    for (int i = 0; i < N; i++) {
        sv.push_back(dt[i]);
        dfs(cnt+1,N,M);
        sv.pop_back();
    }

}

int main(void) {
    int n,m ; cin >> n >> m;
    dfs(0,n,m);
    return 0;
}