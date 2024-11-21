#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    vector<int> p = {500, 100, 50, 10, 5 ,1};
    int N; cin >> N;
    N = 1000 - N;
    int ans = 0;
    for (int e : p) {
        ans+= (N/e);
        N%=e;
    }
    cout << ans; return 0;
}