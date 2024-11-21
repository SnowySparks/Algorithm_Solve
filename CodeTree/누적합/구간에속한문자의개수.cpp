#include <iostream>
#include <cstring>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;

int arr[1001][1001][3];
int n, m, k;
string s;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    f(i, 1, n+1) {
        cin >> s;
        // cout << (ch + 1) << '\n';
        f(j, 0, m) {
            arr[i][j+1][s[j] - 'a'] = 1;
        }
    }


    f(i, 1, n+1) {
        f(j, 1, m+1) {
            f(k, 0, 3) {
                arr[i][j][k] += arr[i-1][j][k] + arr[i][j-1][k] - arr[i-1][j-1][k];
            }
        }
    }

    // f(i, 1, n+1) {
    //     f(j, 1, m+1) {
    //         f(k, 0, 3) {
    //             cout << arr[i][j][k] <<'|';
    //         }
    //         cout << "\t";
    //     }
    //     cout << '\n';
    // }

    int r1, c1, r2, c2;
    while (k--)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        f(i, 0, 3) {
            cout << arr[r2][c2][i] - arr[r1-1][c2][i] - arr[r2][c1-1][i] + arr[r1-1][c1-1][i] << ' ';
        }
        cout << '\n';
    }
    

    return 0;
}