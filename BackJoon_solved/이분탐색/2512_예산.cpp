#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
    int N; cin >> N;
    vector<int> arr(N);
    int lw = 1, rw = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        rw = max(rw, arr[i]);
    }
    int max_money; cin >> max_money;
    int mid ;
    int calc_money;
    int ans = 0;
    while (lw <= rw) {
        mid = (lw + rw) /2;
        calc_money = 0;
        for (auto e : arr) {
            if (e < mid) calc_money += e;
            else calc_money += mid;
            if (calc_money > max_money) break;
        }

        if (calc_money <= max_money) {
            ans = mid;
            lw = mid+1;
        }
        else {
            rw = mid -1;
        }
    }
    cout << ans;
    return 0;
}