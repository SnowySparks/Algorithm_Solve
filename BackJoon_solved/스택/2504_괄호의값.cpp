#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str; cin >> str;
    if (str.size() % 2 == 1) {
        cout << 0;
        return 0;
    }
    // 괄호에 들어갈 수록 2, 3배가 됨
    stack<char> st;

    int ans = 0;
    int preSum = 1;
    for (int i = 0; i < str.size(); ++i) {
        char ch = str[i];
        if (ch == '(') {
            preSum *= 2;
            st.push('(');
        }
        else if (ch == '[') {
            preSum *= 3;
            st.push('[');
        }
        else if (ch == ')') {
            if (st.empty() || st.top() != '(') {
                ans = 0;
                break;
            }
            st.pop();
            if (str[i-1] == '(') ans += preSum;
            preSum /= 2;
        }
        else if (ch == ']') {
            if (st.empty() || st.top() != '[') {
                ans = 0;
                break;
            }
            st.pop();
            if (str[i-1] == '[') ans += preSum;
            preSum /= 3;
        }
    }
    if (!st.empty()) ans = 0;
    cout << ans;
    return 0;
}