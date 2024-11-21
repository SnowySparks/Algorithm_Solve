#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define f(a,b,c) for(int a=b;a<c;a++)
int n;

int arr[20][20];
bool chv[20][20];
int ans = 0;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i,0,n) f(j,0,n) cin >> arr[i][j];
    f(i,0,n) {
        f(j,0,n) {
            f(k,0,n) {
                if (i!=j && j!=k && i!=k) {
                    if (arr[j][k] == arr[j][i] + arr[i][k]) chv[j][k] = true;
                    if (arr[j][k] > arr[j][i] + arr[i][k]) ans = -1;
                }
            }
        }
    }
    if (ans == -1) cout << ans;
    else {
        f(i,0,n) f(j,i,n) if (!chv[i][j]) ans+= arr[i][j];
        cout << ans;
    }
    return 0;
}