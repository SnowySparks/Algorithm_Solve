#include <iostream>
#include <vector>
#include <algorithm>
#define inf 20000000
using namespace std;

int dt[101][101]; //[시작위치][종료위치] = 비용

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m; cin >> n >> m ;

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            dt[i][j] = inf;
        }
        dt[i][i] = 0;
    }

    int a,b,c;
    //데이터 입력
    for (int i = 0 ; i < m ; i++) {
        cin >> a >> b >> c;

        if (dt[a][b] > c) {
            dt[a][b] = c;
        }
    }

    //플로이드 알고리즘

    for (int i = 1 ; i<= n ;i++) {
        for (int j = 1; j <= n ; j++) {
            for (int k = 1 ; k <= n ; k++) {
                dt[j][k] = min(dt[j][k] , dt[j][i] + dt[i][k]);
            }
        }
    }

    for (int i = 1 ; i<= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            cout << (dt[i][j] == inf ? 0 : dt[i][j]) << ' ';
        }
        cout << '\n';
    }
    return 0;
}