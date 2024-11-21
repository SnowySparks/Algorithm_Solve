#include <iostream>
#include <vector>
#include <stack>
#define inf 1001
using namespace std;

int dt[1001];
int dp[1001][2]; //0 : 각 인덱스 LIS 배열 크기 , 1 // 그 이전 인덱스값
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    int max_length = 0, at_loc =1;
    stack<int> s;

    for (int i = 1 ; i <= N ; i++) {
        cin >> dt[i];
    }
    dp[1][0] = 1; dp[1][1] = -1;
    dp[0][1] = -1;

    for (int i = 1 ; i <= N ; i++) {
        for (int j = 1 ; j < i ; j++) {
            if (dt[j]<dt[i] && dp[i][0] < dp[j][0]+1 ) {
                dp[i][0] = dp[j][0]+1;
                dp[i][1] = j;
            }
        }
        if (max_length < dp[i][0]) {
            max_length = dp[i][0];
            at_loc = i;
        }
    }

    cout << max_length << '\n';
    int loc = at_loc ;
    while (loc != -1) {
        s.push(dt[loc]);
        loc = dp[loc][1];
    }

    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    return 0;
}