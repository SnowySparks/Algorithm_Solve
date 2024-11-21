#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    vector<int> lst(N);
    for (int i = 0; i < N ; i++) {
        cin >> lst[i];
    }
    sort(lst.begin(), lst.end());
    int a1 = 0 , a2 = lst.size() -1;
    int answer = 0;
    while (a1 < a2) {
        if (lst[a1] + lst[a2] < M) {
            a1++;
        }
        else if (lst[a1] + lst[a2] > M) a2--; 
        else {
            answer++;
            a1++;
        }
    }
    cout << answer ; return 0;
}