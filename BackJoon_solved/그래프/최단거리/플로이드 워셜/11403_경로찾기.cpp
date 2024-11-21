#include <vector>
#include <algorithm>
#include <iostream>
#define inf 1000001
using namespace std;

int tp[101][101];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    int inp;
    for (int i = 1 ; i <= N ; i++) {
        for (int j = 1 ; j <= N ; j++) {
            cin >> tp[i][j];
            if (!tp[i][j]) tp[i][j] = inf;
        } 
    }
    for (int i = 1 ; i <= N ; i++) {
        for (int j = 1 ; j <= N ; j++) {
            for (int k = 1 ; k <= N ; k++) {
                tp[j][k] = min(tp[j][k],tp[j][i]+tp[i][k]);
            }
        }
    }
    for (int i = 1 ; i <=N; i++) {
        for (int j = 1 ; j <= N ; j++) {
            if (tp[i][j] >= inf) cout << 0 <<' ';
            else cout << 1 << ' ';
        } cout <<'\n';
    }
    return 0;
}