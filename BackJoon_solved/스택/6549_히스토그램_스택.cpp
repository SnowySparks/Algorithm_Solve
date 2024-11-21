#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void) {
    long long arr[100002] = {0,};
    stack<long long> st;
    long long temp;
    long long ans = 0;
    int len;
    while (true) {
        cin >> len;
        if (len == 0) break;

        for (int i = 1 ; i <= len ; i++) {
            cin >> arr[i];
        }
        st.push(0);
	    for (int i = 1; i <= len + 1; i++) {
		    while (!st.empty() && arr[st.top()] > arr[i]) { //항상 0은 남기면서
			    int check = st.top();
			    st.pop();
			    ans = max(ans, arr[check]*(i - st.top() - 1));
		    }
		    st.push(i);
	    }
        cout << ans << '\n';
        arr[len+1] = 0;
        while (!st.empty()) st.pop();
        ans = 0;
        memset(arr,0,sizeof(arr));
    }

}