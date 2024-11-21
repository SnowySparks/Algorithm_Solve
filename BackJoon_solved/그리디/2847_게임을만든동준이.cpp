#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    vector<int> lst(N);
    for (int i = 0; i < N; i++) cin >> lst[i];
    int answer = 0;
    for (int i = N-2 ; i >= 0 ; i--) {
        if (lst[i] < lst[i+1]) continue;
        else {
            answer += (lst[i] - lst[i+1]) +1;
            lst[i] = lst[i+1]- 1;
        }
    }
    cout << answer; return 0;
}