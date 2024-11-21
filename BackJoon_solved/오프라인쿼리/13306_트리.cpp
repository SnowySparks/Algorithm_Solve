#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int mv = 2e5+1;
const int _2mv = mv * 2 + 1;
#define f(a,b,c) for(int a=b; a<c ; ++a)
int n , q;
int inp_parent[mv];
int p[mv];
//--union _ find 

int find(int a) { 
    return a == p[a] ? a : p[a] = find(p[a]);
}

bool _union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    p[min(a,b)] = max(a,b);
    return true;
}

// 문제 특성상 꼭 입력받자마자 출력할 필요 없음 -> 오프라인 쿼리
// 다 입력미리 받고 처리 후 출력도 가능
// 쿼리를 주어진 순서대로 처리하지 않고 나에게 유리한 순서대로 재배치해서 처리해 가는 것이 주 목적

// query에서 해당 단자가 끊어졌다는 것은 역순서로는 연결했다는 의미이기도 함
// 또한 반드시 N-1번 끊는 입력 받기에, 최종적으론 전부 끊겨있음 -> 따라서 역순으로 병합으로 생각해볼 수 있음

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //input
    cin >> n >> q;
    f(i,2,n+1) cin >> inp_parent[i];
    q+=(n-1);

    //query input
    int a, b, c;
    stack<pair<int, int> > st; //역순처리를 위해 스택 이용
    f(i,0,q) {
        cin >> a;
        if (a) {cin >> b >> c; st.push({b,c}); }
        else {cin >> b; st.push({b, 0}); }
    }
    //set parent init_value
    f(i,1,n+1) p[i]=i;

    //역순으로 쿼리처리
    stack<bool> ans;

    while (!st.empty()) {
        a = st.top().first;
        b = st.top().second;
        st.pop();

        if (b) ans.push( find(a) == find(b) );
        else _union(a,inp_parent[a]);
    }

    //역순출력
    while (!ans.empty()) {
        cout << (ans.top() ? "YES" : "NO") <<'\n';
        ans.pop();
    }
    return 0;
}