#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int ,int>;
int typeCnt = 0;
vector<pii> lst[6];
int mentoCnt[6] = {0, 1, 1, 1, 1, 1}; // 최소 1명씩 다 배치했다고 전제까기
int ans = 1e9 + 7;

//각 상담 종류에 따른 대기 시간 계산 함수
int waitTime(int loc) {
    int nowTime = 0; //현재시간
    int res = 0; //참가자 대기 시간 총 합
    priority_queue<int, vector<int>, greater<> > pq; // 오름차순 pq
    
    for (auto &[enterTime, duration] : lst[loc]) {
    
		    // 현재 상담참가자 수 >= 배정된 멘토 수 -> 참가 가능 자리 나올 떄 까지 pop
        while (pq.size() >= mentoCnt[loc] ) {
            nowTime = max(nowTime, pq.top()); //시간 갱신
            pq.pop();
        }
        
        //최소 1자리 이상 남았을 때 시간에 대해서
        
        // 입장 시간이 더 뒤인경우
        if (nowTime <= enterTime) {
            nowTime = enterTime; // 현재시간 갱신
            pq.push(enterTime + duration);
        }
        
        // 입장 시간보다 현재 시간이 더 뒤인경우 -> 대기발생
        else {
            res += nowTime - enterTime;
            pq.push(nowTime + duration);
        }
    }
    return res;
}

//모든 상담종류에 대한 대기시간 총합 계산
int totalWait() {
    int cal = 0;
    for (int i = 1; i <= typeCnt; ++i) {
        cal += waitTime(i);
    }
    return cal;
}

//백트래킹 - 각 상담종류에 따른 멘토 인원 배정 및 시물레이션
void back_track(int idx, int remain) {
    if (idx == typeCnt) {
        mentoCnt[idx] += remain;
        ans = min(ans, totalWait());
        mentoCnt[idx] -= remain;
        return;
    }
    for (int i = 0; i <= remain; ++i) {
        mentoCnt[idx] += i;
        back_track(idx+1, remain-i);
        mentoCnt[idx] -= i;
    }
}

int solution(int k, int n, vector<vector<int>> reqs) {
    typeCnt = k;
    sort(reqs.begin(), reqs.end(), [](const vector<int>&a, const vector<int> &b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });
    
    //상담 종류에 따라 분류해두기
    for (const vector<int> &req : reqs) {
        lst[req[2]].push_back({req[0], req[1]});
    }
    
    back_track(1, n-k);
    return ans;
}