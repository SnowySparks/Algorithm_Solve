#include <iostream>
#include <cstring>
using namespace std;
#define f(a,b,c) for(int a=b; a<c;++a)

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T,n,k; cin >> T;
    int arr[15][15], ans = 0;
    f(t,1,T+1) {
        ans = 0;
        cin >> n >> k;
        f(i,0,n) {
            f(j,0,n) {
                cin >> arr[i][j];
            }
        }
        f(row,0,n) {
            int cnt = 0;
            f(col,0,n) {
                if (arr[row][col] == 1) {
                    cnt++;
                }
                if (arr[row][col] == 0 || col == n -1){
                    if (cnt == k) ans++;
                    if (arr[row][col] == 0) cnt = 0;
                }
            }
        }
        f(col,0,n) {
            int cnt = 0;
            f(row,0,n) {
                if (arr[row][col] == 1) {
                    cnt++;
                }
                if (arr[row][col] == 0 || row == n -1){
                    if (cnt == k) ans++;
                    if (arr[row][col] == 0) cnt = 0;
                }
            }
        }
        cout << '#' << t << ' ' << ans <<'\n';
    }
    return 0;
}
