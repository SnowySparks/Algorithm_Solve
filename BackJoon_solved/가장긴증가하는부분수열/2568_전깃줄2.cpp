#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int dp[100000]; //
bool is_lis[100000];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N ; cin >> N;
    vector<pair<int, int> > datas(N);//전봇대, 
    vector<int> L;
    vector<int>::iterator it;
    for (int i = 0; i <N; i++) {
        cin >> datas[i].first >> datas[i].second;
    }
    sort(datas.begin(), datas.end());
    int max_len = -1, idx= -1;

    for (int i = 0 ; i < N ; i++) {
        if (L.empty() || L.back() < datas[i].second) {
            L.push_back(datas[i].second);
            dp[i] = L.size();
        }
        else {
            it = lower_bound(L.begin(), L.end(), datas[i].second);
            *it = datas[i].second;
            dp[i] = (it - L.begin() + 1);
        }

        if (max_len < dp[i]) {
            max_len = dp[i]; idx = i;
        }
    }
    cout << N -max_len << endl;
    int t_count = N - max_len;
    vector<int> ans;

    for (int i = N-1 ; i >= 0 ; i--) {
        if (dp[i] == max_len) max_len --;
        else ans.push_back( datas[i].first );
    }
    sort(ans.begin(), ans.end());
    for (auto e : ans) {
        cout << e << '\n';
    }
    return 0;
}