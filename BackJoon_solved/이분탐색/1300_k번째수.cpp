#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N; cin >> N;
    int answer =0;
    int left = 1, right;
    int K ; cin >> K; right = K;
    int mid;
    int cnt = 0;
    while (left <= right) {
        mid = (left + right)/2;
        cnt = 0;
        for (int i = 1; i <= N ; i++) {

            cnt += min(mid/i,N);
        }

        if (cnt < K) {
            left = mid + 1;
        }
        else {
            answer = mid;
            right = mid-1;
        }
    }
    cout << answer ;
    return 0;
}