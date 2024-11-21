#include <iostream>
#include <unordered_map>
using namespace std;
#define f(a,b,c) for(int a=b;a<c;++a)
int arr[4][5000], n;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n;
    f(k, 0, 4) {
        f(i, 0, n) cin >> arr[k][i];
    }

    unordered_map<int, int> cal;
    f(i, 0, n) f(j, 0, n) cal[arr[0][i] + arr[1][j]]++;
    long long ans = 0;
    f(i, 0, n) f(j, 0, n) ans += 1LL * cal[ -(arr[2][i] + arr[3][j])];
    cout << ans;
    // meet in the middle

    // 이분탐색으로도 찾기 가능
    // 원리 : upper - lower = 갯수 
}