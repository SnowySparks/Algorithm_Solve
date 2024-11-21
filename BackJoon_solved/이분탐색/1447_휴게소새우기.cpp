#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M,L; cin >> N >> M >> L;
    int inp;
    int max_dist = 0;
    int answer =0;
    vector<int> cood;
    vector<int> dist;
    for (int i = 0; i < N; i++) {
        cin >> inp; cood.push_back(inp);
    }
    cood.push_back(0);
    sort(cood.begin(), cood.end());
    for (int i = 1; i <= N; i++) {
        dist.push_back(cood[i] - cood[i - 1]);
        max_dist = max(max_dist, dist.back());
    }
    dist.push_back(L - cood.back());
    max_dist = max(max_dist, dist.back());
    int cnt = 0;
    int left = 1 , right = max_dist , mid;
    while (left <= right) {
        mid = (left + right)/2;
        cnt = 0;
        for (int p : dist) {
            cnt+=(p/mid);
            if (p % mid == 0) cnt--;
        }

        if (M < cnt) left = mid+1;
        else {right = mid-1; answer = mid;}
    }
    cout << answer;
    return 0;
}