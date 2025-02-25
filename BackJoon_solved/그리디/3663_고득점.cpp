#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;


int query(const string &str) {
    int n = str.size();
    int minMove = n-1;
    int j;
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'A') {
            j = i;
            while (j+1 < n && str[j+1] == 'A') ++j;
            int leftMove = i > 0 ? i-1 : 0;
            int rightMove = n-j-1;
            minMove = min(minMove, leftMove + rightMove + min(leftMove, rightMove));
            i = j + 1; // 이미 탐색한 구간 스킵
        }
    }
    int alphaMove = 0;
    for (char ch : str) {
        alphaMove += min(ch - 'A', 'Z'-ch + 1);
    }
    return minMove + alphaMove;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str;
    int T; cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> str;
        cout << query(str)<<'\n';
    }
    return 0;
}