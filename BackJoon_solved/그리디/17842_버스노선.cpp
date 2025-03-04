#include <iostream>
#include <cstring>
using namespace std;
const int N = 2e5+1;
int n;
int arr[N];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        arr[a]++;
        arr[b]++;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += (arr[i]==1 ? 1 : 0);
    }
    cout << cnt/2 + (cnt&1);
    return 0;
}