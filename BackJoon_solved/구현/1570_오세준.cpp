#include <iostream>
#define f(a,b,c) for (int a= b; a< c; a++)
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    pair<int, int> s, e;
    cin >> s.first >> s.second >> e.first >> e.second;
    int dx = e.first - s.first , dy = e.second - s.second;
    if (dx < 0 || dy < 0) {cout << -1; return 0;}
    if (dx +dy <= N) {
        f(i,0,dx) cout << "R";
        f(i,0,dy) cout << "U";
        f(i,0,N-(dx+dy)) cout <<"R";
        return 0;
    }
    int Q = (dx +dy)/N , R = (dy +dx) % N;
    int r1, u1, r2, u2;
    for (r1 = R; r1 >= 0; r1--) {
        if ((dx - r1*(Q+1))%Q!=0) continue;
        u1 = R - r1;
        r2 = (dx - (Q+1)*r1)/Q;
        u2 = (dy - (Q+1)*u1)/Q;
        if(r2 < 0 || u2 < 0) continue;
        if(r1 + r2+ u1+ u2 == N) break;
    }
    if (r1 < 0) cout << -1;
    else f(i,0,r1) {cout <<"R"; f(i,0,u1) cout <<"U"; f(i,0,r2) cout <<"R"; f(i,0,u2) cout <<"U";}
    return 0;
}