#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef pair<int ,int> pii;
const int inf = 1e9 + 7;
int n;
int arr[1000];
int maxDiff;
unordered_map<int, vector<pii> > ab;

void calPlus() {
    ab.clear();
    maxDiff = -2 * inf;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i+1; j < n; ++j) {
            ab[arr[i] + arr[j]].push_back({i, j});
            maxDiff = max(maxDiff, arr[i] + arr[j]);
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    while (1)
    {
        cin >> n;
        if (n == 0) break;
        int ans = -2 * inf;
        for (int i = 0; i < n; ++i) cin >> arr[i];
        sort(arr, arr + n);
        calPlus();

        for (int d = n-1; d > 0; --d) {

            if (ans !=  (-2 * inf) ) break;

            for (int c = 0; c < d; ++c) {
                if (ans != -2 * inf) break;
                if (arr[d] - arr[c] > maxDiff) continue;; // <- 차이가 엄청 커서 불가능한 경우
                int needab = arr[d] - arr[c];

                if (ab.find(needab) == ab.end()) continue;

                for (pii &idx : ab[needab]) {
                    if (idx.first == d || idx.second == d) continue;
                    if (idx.first == c || idx.second == c) continue;
                    ans = arr[d];
                    break;
                }
            }
        }

        switch (ans)
        {
        case -2*inf:
            cout << "no solution\n";
            break;
        
        default:
            cout << ans << '\n';
            break;
        }


    }
    


    return 0;
}