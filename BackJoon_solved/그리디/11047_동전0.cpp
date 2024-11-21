#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, money; cin >> N >> money;
    int dt[10];
    int answer = 0;
    for (int i = 0 ; i < N ; i++) cin >> dt[i];
    for (int i = N-1 ; i >=0 ; i--) {
        answer+=(money/dt[i]);
        money%=dt[i];
    }

    cout << answer; return 0;
}