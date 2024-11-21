#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
#define f(a,b,c) for(int a=b;a<c;a++)

int a[22];
int b[22];
int base3(int n, int *p) {
    stack<int> st;
    while (n) {
        st.push(n % 3);
        n/=3;
    }
    int cnt = st.size();
    int rcnt = cnt;
    for (int i = cnt - 1 ; i >= 0 ; i--) {
        if (st.top() == 2) {
            p[i]--;
            p[i+1]++;
            if (i == cnt -1) rcnt++;
        }
        else if (st.top() == 1 ) p[i]++;

        st.pop();
    }
    f(i,0,rcnt) {
        if (p[i] == 2 ) {
            p[i] = 1;
            p[i+1]++;

            if (i == rcnt - 1) rcnt++;
        }
    }
    f(i,0,rcnt) if(p[i]!=0) p[i]=1;
    return rcnt;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    int mst;
    bool ans = true;
    f(i,1,t+1) {
        ans = true;
        int r1, r2; cin >> r1 >> r2;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int st1 = base3(abs(r1),a);
        int st2 = base3(abs(r2),b);

        f(i, 0, max(st1,st2)) {
            if (a[i] == b[i]) {
                ans = false;
                break;
            }
        }

        cout << '#' <<i << ' ' << (ans? "yes" : "no") << '\n';
    }

    return 0;

}