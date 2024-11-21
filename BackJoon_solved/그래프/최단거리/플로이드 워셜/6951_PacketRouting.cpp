#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 5*1E6+1;
int gh[101][101];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, W, T; cin >> N >> W >> T;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            gh[i][j] =inf;
        }
        gh[i][i] = 0;
    }
    int a,b,c;
    for (int i = 1 ; i <= W ; i++) { 
        cin >> a >> b >> c;
        gh[a][b] = c;
        gh[b][a] = c;
    }

    for (int i = 1 ; i <= N ; i++) {
        for (int j = 1 ; j <= N; j++) {
            for (int k = 1 ; k <= N ; k++) {
                gh[j][k] = min (gh[j][k] , gh[j][i] + gh[i][k]);
            }
        }
    }
    while(T--) {
        cin >> a >> b;
        cout << gh[a][b] <<'\n';
    }
    return 0;
}