#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> pl, mu;
    int zero_ = 0;
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        int tmp; cin >> tmp;
        if (tmp > 0 ) pl.push_back(tmp);
        else if (tmp < 0) mu.push_back(tmp);
        else zero_++;
    }

    sort(pl.begin(), pl.end());
    sort(mu.begin(),mu.end());
    int i,j;
    for (i = (int)pl.size()-1; i > 0 ; i-=2) {
        ans += max(pl[i]*pl[i-1], pl[i] + pl[i-1]);
    }
    if (i == 0) ans+= pl[0];

    for (j = 0 ; j < (int)mu.size() -1;j+=2) {
        ans += (mu[j] * mu[j+1]);
    }

    if (j == (int)mu.size()-1) {
        if (zero_ == 0) ans += mu[j];
    }
    cout << ans; return 0;
}