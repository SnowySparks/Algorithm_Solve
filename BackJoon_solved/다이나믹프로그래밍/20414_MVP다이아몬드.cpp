#include <iostream>
#include <cstring>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;

int n;
int s, g, p, d;
char ch[100];
int dp[100];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s >> g >> p >> d;
    cin >> (ch + 1);

    f(i, 1, n+1) {
        switch (ch[i])
        {
        case 'B':
            dp[i] = s -1 - dp[i-1];
            break;
        case 'S':
            dp[i] = g - 1 - dp[i-1];
            break;
        case 'G':
            dp[i] = p - 1- dp[i-1];
            break;
        case 'P':
            dp[i] = d -1- dp[i-1];
            break;
        case 'D':
            dp[i] = d;
            break;
        default:
            break;
        }
        dp[i] += dp[i-1];
    }
    cout << dp[n];
    return 0;
}