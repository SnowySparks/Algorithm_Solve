#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define f(a,b,c) for(int a = b; a < c; a++)

int n;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int h, cnt = 0;
    ll ans = 0;
    stack<pii> st; //ascending order. tall & same tall counter
    // 현재 i 에서 ? ~ i-1까지 만족하는 구간 내에서의 이을 수 있는 경우의 수를 구함
    f(i, 1, n + 1) {
        cnt = 1;
        cin >> h;
        //현 내리막 st에서 더 높은 h 등장. --> h 크기보다 작은 것은 더이상 이용가치 x
        while(!st.empty() && st.top().first < h) {
            ans += st.top().second;
            st.pop();
        }
        if (!st.empty()) {
            if (st.top().first == h) {
                cnt = st.top().second +1; //연속 동일 높이 건물 갱신
                ans += st.top().second; //동일 높이의 건물에 대한 정답 갱신
                st.pop();
                if (!st.empty()) ans++; //stack에 h보다 바로 다음으로 큰 건물과의 연결성 반영
            }
            else { //더 낮은 높이
                cnt = 1;
                ans += 1;
            }
        }
        st.push({h, cnt}); //푸쉬
    }
    cout << ans << '\n';
    return 0;
}
