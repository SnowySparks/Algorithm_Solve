#include <iostream>
#include <vector>
using namespace std;
long long N, loc_r, loc_c;
long long answer = 0;

int mover[] = {0,0,1,1};
int movec[] = {0,1,0,1};
bool fd = false;
void pr(long long sr, long long sc, int R) { //시작위치 sr, sc; 길이 : 2^N;
    if (fd) return ;

    if ( sr == loc_r && sc == loc_c) {
        cout << answer << '\n'; return;
    }
    
    if (sr <= loc_r && sc <= loc_c && sr+R > loc_r && sc+R > loc_c) {
    pr(sr,sc,R/2);
    pr(sr,sc+R/2,R/2);
    pr(sr+R/2,sc,R/2);
    pr(sr+R/2,sc+R/2,R/2); }

    else {
        answer+= (R*R);
    }

}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> loc_r >> loc_c;
    pr(0,0,1<<N);
    return 0;
}