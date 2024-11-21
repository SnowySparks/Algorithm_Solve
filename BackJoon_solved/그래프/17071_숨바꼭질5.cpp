#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define inf 500000
using namespace std;

int vs[2][inf+1];// 0 : 짝수 time때 있을 수 잇음 , 1 홀수 타임때 있을 수 있음. -> 홀수 , 짝수일때 시간의 최단시간

int mv(int sec) {
    return sec*(sec+1) /2;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(vs, -1, sizeof(vs));
    int start, end ; cin >> start >> end;
    vs[0][start] = 0 ;
    int temp[3];
    queue<pair<int , int> > q;
    q.push({start, 0});
    int answer = -1;
    while (!q.empty()) {
        int loc = q.front().first;
        int time = q.front().second;
        q.pop();
        temp[0] = loc -1; temp[1] = loc+1; temp[2] = loc*2;
        for (int i = 0; i < 3 ; i++) {
            if (temp[i] >= 0 && temp[i] <= inf && vs[(time+1)%2][temp[i]]== -1) {
                vs[(time+1)%2][temp[i]] = time+1;
                q.push({temp[i],time+1});
            }
        }
    }
    int ct = 0;
    int sl = end;
    while(true) {
        sl = end + mv(ct);
        if (sl > inf) break;
        if (vs[ct%2][sl] != -1 && ct >= vs[ct%2][sl]) {answer = ct; break;}
        ct++;
    }
    cout << answer;
    return 0;

}