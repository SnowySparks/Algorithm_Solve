#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N ; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int a = 0, b=0;
    int answer = 2E9;
    while( a < N&&b < N) {
        if (abs(v[b] - v[a]) < M) {
            b++;
        }
        else {
            answer = min(answer, v[b] - v[a]);
            a++;
        }
    } 
    cout << answer;
    return 0;  
}