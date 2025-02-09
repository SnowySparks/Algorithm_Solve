#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
int n;
pair<int ,int> arr[50002];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr+1+n);
    stack<int> st;
    int ans = 0;
    for (int i = 1; i <= n+1; ++i) {
        if (!st.empty() && st.top() > arr[i].second) {
            int beforeHeight = st.top();
            ++ans;
            while (!st.empty() && st.top() > arr[i].second) 
            {
                if (st.top() != beforeHeight) {
                    beforeHeight = st.top();
                    ++ans;
                }
                st.pop();
            }    
        }
        if (arr[i].second > 0) st.push(arr[i].second);
    }
    cout << ans;
    return 0;
}