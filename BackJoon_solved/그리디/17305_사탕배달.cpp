#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
int n, maxW;
vector<ll> three, five;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("in.txt","r",stdin);
    cin >> n >> maxW;
    three.push_back(0);
    five.push_back(0);
    int t; ll s;
    for (int i = 0; i < n; ++i) {
        cin >> t >> s;
        switch (t)
        {
        case 3:
            three.push_back(s);
            break;
        case 5:
            five.push_back(s);
        }
    }
    sort(three.begin()+1, three.end(), greater<>());
    sort(five.begin()+1,five.end(), greater<>());

    for (int i = 1; i < three.size(); ++i) three[i] += three[i-1];
    for (int i = 1; i < five.size(); ++i) five[i] += five[i-1];

    int maxThreeCnt = min((int)three.size()-1, maxW/3);
    ll ans = 0;

    for (int i = maxThreeCnt; i >= 0; --i) {
        int fiveCnt = min((int)five.size()-1, (maxW - 3*i)/5);
        ans = max(ans, three[i] + five[fiveCnt]);
    }

    cout << ans;

    return 0;
}