#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define f(a, b, c) for (int a =b; a<c; ++a)
using namespace std;
#define MAX (int)1e8
int n;
int arr[14][14];
int dp[14][14][1<<14];
bool v[14][14];
vector<int> v1, v2;

int first_santa1, first_santa2;
int tsp(int santa1, int santa2, int v1, int v2 ,int state) {
    if (state == ((1<<n) - 1)) {
        if (arr[santa1][first_santa1] == 0 || arr[santa2][first_santa2] == 0 || v1 < 2 || v2 < 2) return MAX;
        return arr[santa1][first_santa1] + arr[santa2][first_santa2];
    }
    int &res = dp[santa1][santa2][state];
    if (res != -1) return res;
    res = MAX;
    for (int i = 0 ; i < n; ++i) {
        if (state & (1<<i)) {
            continue;
        }
        int nstate = (1 << i) | state;
        if (arr[santa1][i] != 0) {
            res = min(res, tsp(i, santa2,v1+1, v2, nstate) + arr[santa1][i]);
        }
        if (arr[santa2][i] != 0) {
            res = min(res, tsp(santa1, i, v1, v2+1, nstate) + arr[santa2][i]);
        }
    }
    return res;
}

void find_path(int s1, int s2, int state) {
    if (state == (1<<n)-1) {
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (state & (1<<i)) continue;
        if (dp[s1][s2][state] == dp[i][s2][state|(1<<i)] + arr[s1][i]) {
            v1.push_back(i);
            find_path(i,s2,state|(1<<i));
            return;
        }
        if (dp[s1][s2][state] == dp[s1][i][state|(1<<i)] + arr[s2][i]) {
            v2.push_back(i);
            find_path(s1,i,state|(1<<i));
            return;
        }
    }
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n;
    f(i, 0, n) f(j, 0, n) cin >> arr[i][j];
    int ans = MAX;
    f(i, 0, n-1) {
        f(j, i+1, n) {
            // cout <<"---\n";
            if (v[i][j]) continue;

            memset(dp, -1, sizeof(dp));
            first_santa1 = i; first_santa2 = j;
            ans = min(ans, tsp(i, j, 1, 1, (1<<i)|(1<<j) ));
            v1.push_back(i);
            v2.push_back(j);
            find_path(i, j, (1<<i)|(1<<j));
            // cout << v1.size() << '\n';
            // cout << v2.size() << '\n';
            // for (int &nd : v1) cout << nd << ' ';
            // cout << '\n';
            // for (int &nd : v2) cout << nd << ' ';
            // cout << '\n';

            for (int &n1 : v1) {
                for (int &n2 : v2) {
                    v[n1][n2] = true;
                }
            }

            v1.clear();
            v2.clear();
        }
    }
    cout << ans;
    return 0;
}