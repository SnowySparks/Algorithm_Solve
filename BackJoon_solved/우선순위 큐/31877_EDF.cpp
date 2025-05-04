#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, T = 0;
const int inf = 2e9+100;
struct info {
    int t; // 남은 작업 시간
    int d; // 마감시간
    bool operator<(const info &other) const {
        if (d != other.d) return d<other.d; // 마감 시간
        return t < other.t; // 남은 처리 시간
    }
    bool operator>(const info &other) const {
        if (d != other.d) return d>other.d; // 마감 시간
        return t > other.t; // 남은 처리 시간
    }
};

struct addinfo {
    int w;// 추가시간
    int t; // 남은 작업 시간
    int d; // 마감시간
    bool operator<(const addinfo &other) const {
        if (w != other.w) return w < other.w; // 들어온시간
        if (d != other.d) return d<other.w; // 마감 시간
        return t < other.t; // 남은 처리 시간
    }
    bool operator>(const addinfo &other) const {
        if (w != other.w) return w > other.w; //들어온시간
        if (d != other.d) return d>other.w; // 마감 시간
        return t > other.t; // 남은 처리 시간
    }
};




int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    priority_queue<info, vector<info>, greater<> > pq; //작업 중인 것들
    priority_queue<addinfo, vector<addinfo>, greater<> > subpq; //추가 작업 대기목록
    // freopen("input.txt","r",stdin);
    cin >> n;
    int w,t,d,f;
    for (int i = 0; i < n; ++i) {
        cin >> t >> d;
        pq.push({t, d});
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> w >> t >> d;
        subpq.push({w, t, d});
    }

    bool isPossible = true;

    // 데드라인이 작은 순, 같은 경우 남은 작업시간이 작은 순이 우선
    while ((!pq.empty() || !subpq.empty()) && isPossible)
    {   
        info topWork = pq.top(); pq.pop();
        // 추가 작업 들어가기 전 -> 다 처리하기
        // cout << T << ' ' << topWork.t << ' ' << topWork.d << '\n';
        int minAddWorkTime = (subpq.empty() ? inf : subpq.top().w); // 추가되는 작업시간의 최소 시간
        int mainWork = min(topWork.t, minAddWorkTime - T); // 추가 작업에 대해서 작업 가능한 최소 시간
        if (T + mainWork > topWork.d ) { //작업 데드라인 오버 -> 종료
            isPossible = false;
            break;
        }
        else { //처리가능 작업
            topWork.t -= mainWork;
            T+= mainWork;
            if (topWork.t > 0) {
                pq.push({
                    topWork.t, topWork.d
                });
            }
        }

        while (!subpq.empty() && T == subpq.top().w) //추가 작업 넣기.
        {   
            t = subpq.top().t;
            w = subpq.top().w;
            d = subpq.top().d;
            pq.push({t, d});
            subpq.pop();
        }

        // 모든 pq가 끝나고 아직 추가작업이 남아있는 경우 
        if (pq.empty() && !subpq.empty()) {
            T = subpq.top().w;
            pq.push({subpq.top().t, subpq.top().d});
            subpq.pop();
        }
    }

    if (!isPossible) {
        cout << "NO" << '\n';
    }
    else {
        cout << "YES\n";
        cout << T;
    }
    
    return 0;
}