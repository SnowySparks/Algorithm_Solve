#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define f(a, b, c) for(int a = b; a < c; ++a)
using namespace std;
using pii = pair<int ,int>;
int n;
vector< pii > people; // 시작, 종료 시간
int roomNum[100001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    priority_queue<pii, vector<pii>, greater<pii> > pq; // 종료시간, 인덱스값, 현재 이용중인 방
    priority_queue<int, vector<int>, greater<int>> left_room; //배정 가능한 방
    cin >> n;
    people.resize(n);
    for (pii &a : people) {
        cin >> a.first >> a.second;
    }
    // 시작 시간 기준 정렬
    sort(people.begin(), people.end());

    int max_room = 0;
    
    for (const auto &[p, q] : people) {
        // 현재 이용 되는 것중. 종료시간 <= 현재 시작시간 인 경우 전부 Pop 및 배정 가능 방 등록
        while(!pq.empty() && pq.top().first <= p) {
            left_room.push(pq.top().second);
            pq.pop();
        }
        // 배정 가능방 없다 ->  새로운 방 하나 사용해야 함
        if (left_room.empty()) {
            ++max_room;
            roomNum[max_room]++;
            pq.push({q, max_room});
        }
        //있다 -> 배정 가능한 방중 가장 최소값 하나를 새로 배정
        else {
            int idx = left_room.top(); left_room.pop();
            roomNum[idx]++;
            pq.push({q, idx});
        }
    }
    cout << max_room << '\n';
    f(i, 1, max_room+1) cout << roomNum[i] <<' ';
    return 0;
}