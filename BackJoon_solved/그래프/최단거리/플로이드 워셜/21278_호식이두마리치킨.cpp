#include <iostream>
#include <vector>
#include <algorithm>
#define inf 100001
using namespace std;

int dt[101][101];
int main(void) {
     ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
     int N, M; cin >> N >> M;
     for (int i = 1; i <= N ; i++) {
        for (int j = 1 ; j <= N; j++) {
            dt[i][j] = inf;
        } dt[i][i] = 0;
     }
     int a,b;
     while (M--) {
        cin >> a >> b;
        dt[a][b] = 1; dt[b][a] = 1;
     }

     for (int i = 1; i <= N; i++) {
        for (int j = 1 ; j <= N; j++) {
            for (int k = 1 ; k <= N; k++) {
                dt[j][k] = min(dt[j][k],dt[j][i] + dt[i][k]);
            }
        }
     }
     int aloc = 0, bloc = 0;
     int min_dist = 2*inf;
     int calc = 0;
     for (int i = 1; i <= N; i++) {
        for (int j = 1 ; j <= N; j++) {
            calc = 0;

            for (int k = 1 ; k <= N ; k++) {
                calc += min (dt[k][i] + dt[i][k] , dt[k][j] + dt[j][k]);
            }

            if (min_dist > calc) {
                aloc = i; bloc =j; min_dist = calc;
            }
        }
     }
     cout << aloc << ' ' <<bloc << ' ' << min_dist;
     return 0;
}