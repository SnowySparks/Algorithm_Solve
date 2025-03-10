#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int n;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> arr;
    for (int i = 1; i <= n; ++i) {
        int tmp; cin >> tmp;
        if (arr.empty() || arr.back() != tmp) arr.push_back(tmp);
    }
    long long ans = 0;
    stack<int> st;
    for (int i = arr.size()-1; i >= 0; --i) {
        if (st.empty() || st.top() > arr[i]) st.push(arr[i]);
        else {
            ans += arr[i] - st.top();
            while (!st.empty() && arr[i] > st.top()) st.pop();
            st.push(arr[i]);
        }
    }

    while (st.size() > 1)
    {
        int t = st.top();
        st.pop();
        ans += st.top() - t;
    }
    cout << ans;

    return 0;
}