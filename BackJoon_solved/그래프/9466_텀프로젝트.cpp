#include <iostream>
#include <vector>
using namespace std;
const int inf =1e5+1;


int arr[inf], n, v[inf];
//0 : not_visited, >=1 , checked , -1 : cycle
int ans = 0;

void dfs(int x) {
    int cur = x;
    while(true) {
        v[cur] = x;
        cur = arr[cur]; 

        if (v[cur] == x) {
            while( v[cur] != -1) {
                ans++;
                v[cur] = -1;
                cur = arr[cur];
            }
            return;
        }
        else if (v[cur]) return;
    }
}

int main(void) {
    int t; cin >> t;
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while(t--) {
        cin >> n;
        for (int i = 1 ; i <= n;i++) v[i] = 0;
        ans = 0;
        for (int i = 1 ; i <= n;i++) cin >> arr[i];
        for (int i = 1 ; i <= n;i++) if (v[i]==0) dfs(i);
        cout << n - ans <<'\n';
    }
}