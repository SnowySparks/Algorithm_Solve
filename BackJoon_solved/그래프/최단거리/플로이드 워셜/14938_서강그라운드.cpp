#include <vector>
#include <algorithm>
#include <iostream>
#define inf 1000001;
using namespace std;

int dt[101][101];
int coin[101];

int main(void) {
    int n, m, r; cin >> n >> m >> r;
    int a,b,c;
    for (int i = 1 ; i <= n ; i++) {
        cin >> coin[i];
        for (int j = 1 ; j <= n ; j++) {
            dt[i][j] = inf;
        } dt[i][i] = 0;
    }
    for (int i = 1 ; i <= r; i++) {
        cin >> a >> b>> c;
        dt[a][b] = c;
        dt[b][a] = c;
    }
    for (int i = 1 ; i <= n; i++) {
        for (int j = 1 ; j <= n ; j++) {
            for (int k = 1 ; k <=n; k++) {
                dt[j][k] = min(dt[j][k] , dt[j][i] + dt[i][k]);
            }
        }
    }

    int answer = 0; int temp;
    for (int i = 1 ; i <= n ; i++) {
        temp = 0;
        for (int j = 1 ; j <= n ; j++) {
            if (dt[i][j] <= m) temp+=coin[j];
        }
        answer = max(answer, temp);
    }
    cout << answer ; return 0;
}