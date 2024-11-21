#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int loc[100001]; //시작점 이후 각 위치 도달하는데 걸리는 시간 저장

bool _valid(int x) {
    if (x >= 0 && x<= 100000) return true;
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int start, end; cin >> start >> end;
    int answer = 0;
    queue<pair<int, int> > q;
    for (int i = 0 ; i <= 100000; i++) {loc[i] = -1;}
    q.push({start,0});
    loc[start] = 0;

    int lst[3];
    while(!q.empty()) {
        int cur = q.front().first;
        int cost = q.front().second;
        q.pop();
        //최초도착
        if (cur == end && loc[end]== -1) {
            answer++;
            loc[end] = cost;
        }

        //이후 동일 시간 도착시 카운트
        else if ( cur == end && loc[end] == cost) {
            answer++;
        }

        else {
            //최초 도착이거나, 동일 시간인 경우 push
            lst[0] = cur+1; lst[1] = cur-1; lst[2] =cur*2;
            for (int i = 0 ; i < 3 ;i++) {
                if (_valid(lst[i])) {
                    if (loc[lst[i]] == -1 || loc[lst[i]] == cost+1) {
                        q.push({lst[i], cost+1});
                        loc[lst[i]] = cost +1;
                    }
                }
            }
        }
    }
    cout << loc[end] << '\n' << answer << '\n'; return 0;
    
}