#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX 1000001
using namespace std;

int arr[MAX];
int dp[MAX]; //해당 위치기준 가장 긴 것
stack<int> st; //답 출력용 
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> L;
    int N; cin >> N;
    int max_len = 0 ,idx = -1;
    vector<int>::iterator it;
    for (int i = 1 ; i <= N ; i++){
        cin >> arr[i];
        //비어 있는 경우 나 가장 마지막 L 위치 < arr[i] -> 스택후 
        if (L.empty() || L.back() < arr[i]) { L.push_back(arr[i]); dp[i] = L.size(); }
        else {
            //Lower_bound를 통해 L에 놓아야 할 위치에 arr[i] 값으로 업데이트
            //또한 해당 위치까지의 데이터 크기 (시작 ~ 해당위치) 의 길이를 업데이트
            it = lower_bound(L.begin(), L.end(),arr[i]);
            *it = arr[i];
            dp[i] = it - L.begin()+1;
        }
        if (max_len < dp[i]) {max_len = dp[i]; idx = i;}
    }
    cout << max_len << endl; //
    for (int i = idx ; i >= 1 ; i--) {
        if (max_len == 0 ) break;
        if (dp[i] == max_len ) {
            st.push(arr[i]);
            max_len--;
        }
    }
    while (!st.empty()) {
        cout << st.top() <<' ';
        st.pop();
    } cout << endl;
    return 0;
}