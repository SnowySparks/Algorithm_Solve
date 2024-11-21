#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    vector<int> lst(N+1);
    vector<int> arr(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> lst[i]; }
    sort(lst.begin(), lst.end());
    long long answer = 0;
    arr[0] = lst[0];
    for (int i = 1; i <= N; i++) {
        arr[i] = arr[i-1] + lst[i]; }
    for (int i = 1; i <= N; i++) {
        answer += (lst[i] + arr[i-1]);   }    
    cout << answer; return 0;
}