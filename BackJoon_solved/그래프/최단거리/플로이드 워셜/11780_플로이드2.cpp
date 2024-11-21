#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define inf 20000000
using namespace std;

int dt[101][101]; //[시작위치][종료위치] = 비용
int path[101][101]; //경로

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m; cin >> n >> m ;

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            dt[i][j] = inf;
            path[i][j] = inf;
        }
        dt[i][i] = 0;
    }
    int a,b,c;
    //데이터 입력
    for (int i = 0 ; i < m ; i++) {
        cin >> a >> b >> c;
        if (dt[a][b] > c) {
            dt[a][b] = c;
            path[a][b] = a; //단 하나 길 입력 -> 경류지 ==시작지 설정
        }
    }
    for (int i = 1 ; i<= n ;i++) {
        for (int j = 1; j <= n ; j++) {
            for (int k = 1 ; k <= n ; k++) {
                if (dt[j][k] > (dt[j][i] + dt[i][k])) {
                    dt[j][k] = dt[j][i] + dt[i][k];
                    path[j][k] = path[i][k];
                    //j- > k 가는데 반드시 i를 경유함 ==> i -> k로 가는데 반드시 경유하는 곳도 지나감
                    //i -> k 최단 거리가 반드시 i ->k 이거 뿐인 경우는 i가 저장, 
                }
            }
        }
    }

    for (int i = 1 ; i<= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            cout << (dt[i][j] == inf ? 0 : dt[i][j]) << ' ';
        }
        cout << '\n';
    }
    stack<int> st;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            if (path[i][j]>=inf || path[i][j] == 0) cout <<'0';
            else {
                int loc = j; st.push(loc);
                while (i!=path[i][loc]) {
                    loc = path[i][loc];
                    st.push(loc);
                }
                cout << st.size() +1 <<' ';
                cout << i <<' ';
                while (!st.empty()) {
                    cout << st.top() << ' ';
                    st.pop();
                }
            }
            cout <<'\n';
        }  
    }
    return 0;
}