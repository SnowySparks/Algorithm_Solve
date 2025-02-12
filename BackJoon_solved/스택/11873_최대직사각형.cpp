#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
#define f(a, b, c) for(int a=b; a<c; ++a)
int n, m;
int arr[1002];
int dp[2][1002];

// 더 효율적인 스택 구현
int st[1010];
int idx = -1;

bool isEmpty() {
    return idx == -1;
}
int pop() {
    if (isEmpty()) return -1;
    return st[idx--];
}
int top() {
    if (isEmpty()) return -1;
    return st[idx];
}
void clear() {
    idx = -1;
}
void push(int number) {
    st[++idx] = number;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int ans = 0;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;
        ans = 0;
        memset(dp, 0, sizeof(dp));
        memset(arr, 0, sizeof(arr));

        f(r, 1, n+1) {
            swap(dp[0], dp[1]);
            f(c, 1, m+1) {
                cin >> arr[c];
                dp[1][c] = (arr[c] ? dp[0][c] + 1 : 0);
            }
            clear();
            push(0);
            f(c, 1, m+2) {
                while (!isEmpty() && dp[1][top()] > dp[1][c]) {
                    int h_idx = pop();
                    ans = max(ans, dp[1][h_idx]*(c-1-top()));
                }
                push(c);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}