#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, s;
int arr[50];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cin >> s;

    // 버블 정렬 응용
    for (int i = 0; i < n-1; ++i) {
        if (s == 0) break;
        // i = 대상
        int loc = i;

        for (int j = i+1; j < n; ++j) {
            if (j-i <= s && arr[loc] < arr[j]) loc = j;
        }

        if (loc == i) continue;
        s -= (loc - i);
        for (int j = loc; j > i; --j) {
            swap(arr[j], arr[j-1]);
        }
    }
    for (int i = 0; i < n; ++i) cout << arr[i] << ' ';
    return 0;
}