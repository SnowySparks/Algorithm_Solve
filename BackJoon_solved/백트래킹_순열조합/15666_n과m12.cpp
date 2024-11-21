#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> arr;
vector<int> seq;
void backtrack(int len, int idx) {
    if (len == m) {
        for (int e : seq) {
            cout << e <<' ';
        }
        cout << '\n';
        return;
    }

    int last = 0;
    for (int i = idx; i < n; i++) {
        if (last != arr[i]) {
            last = arr[i];
            seq.push_back(arr[i]);
            backtrack(len+1,i);
            seq.pop_back();
        }
    }
    return;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0 ; i < n ; i++) cin>> arr[i];
    sort(arr.begin(), arr.end());
    backtrack(0,0);
    return 0;

}