#include <iostream>
#include <cstring>
#include <stack>
#define f(a, b, c) for(int a=b; a<c; ++a)
using namespace std;
const int maxn = 1e5 + 1;
int leftCnt[maxn], rightCnt[maxn], leftIdx[maxn], rightIdx[maxn], n;
int arr[maxn];
const int INF = 1e9+7;

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n;
    f(i, 1, n+1) cin >> arr[i];
    memset(leftIdx, -1, sizeof(leftIdx));
    memset(rightIdx, -1, sizeof(rightIdx));


    stack<int> st;

    st.push(n);
    // 오등큰수
    for (int idx = n-1; idx >= 1; --idx) {
        while (!st.empty() && arr[st.top()] <= arr[idx]) st.pop();
        rightCnt[idx] = st.size();
        if (!st.empty()) rightIdx[idx] = st.top();
        st.push(idx);    
    }

    while (!st.empty()) st.pop();

    // 왼등큰수
    st.push(1);

    f(idx, 2, n+1) {
        while (!st.empty() && arr[st.top()] <= arr[idx]) st.pop();
        leftCnt[idx] = st.size();
        if (!st.empty()) leftIdx[idx] = st.top();
        st.push(idx);    
    }

    f(i, 1, n+1) {
        cout << leftCnt[i] + rightCnt[i];
        if (leftCnt[i] + rightCnt[i]) {
            cout << ' ';
            int l = (leftIdx[i] == -1 ? INF : i - leftIdx[i]);
            int r = (rightIdx[i] == -1 ? INF : rightIdx[i] - i);
            if (l <= r) {
                cout << leftIdx[i];
            }
            else {
                cout << rightIdx[i];
            }
        }
        cout << '\n';
    }
    return 0;
}