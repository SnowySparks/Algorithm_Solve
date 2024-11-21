#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[300001];
long long sum[300001];
//심심해서 정렬 안하면서 풀기
int main(void) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, Q, temp; cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        arr[temp]++;
    }
    int cnt = 0;
    int loc = 1;

    for (int i = 1 ; i <= N; i++) {
        while (arr[loc] == 0) {
            loc++;
        }
        if (cnt < arr[loc]) {
            sum[i] = sum[i-1] + loc;
            cnt++;
            if (cnt == arr[loc]) {
                cnt = 0; loc++;
            }
        }
    }

    int a, b;
    while (Q--) {
        cin >> a >> b;
        cout << sum[b] - sum[a-1] <<'\n';
    }
    return 0;
}