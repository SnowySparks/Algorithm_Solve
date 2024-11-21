#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    string s; cin >> s;
    int cnt = 1;
    for (int i = 0; i < N ; i++) if (s[i]!='C') cnt++;
    cout << N/cnt;
    return 0;
}