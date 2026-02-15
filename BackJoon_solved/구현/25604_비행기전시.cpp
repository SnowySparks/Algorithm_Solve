#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, m, t;
int startTime[10'001];
int endTime[10'001];
const int MAX_TIME = 1'000'000'000;
const int MIN_TIME = -MAX_TIME;

struct Part
{
    int idx, m, r;
};

void init(queue<Part> *q) {
    cin >> n >> m >> t;
    int d, m, r;
    for (int i = 1; i <= n; ++i) {
        cin >> d >> m >> r;
        startTime[i] = MAX_TIME;
        endTime[i] = MIN_TIME;
        q[d].push({i, m, r});
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    queue<Part> q[2];
    q[0] = queue<Part>();
    q[1] = queue<Part>();
    init(q);
    int nowTime = 0, nowLoc = 0;
    while (!q[0].empty() || !q[1].empty()) 
    {

        queue<Part> &nowQ = q[nowLoc];
        queue<Part> &otherQ = q[(nowLoc ^ 1)];
        
        //비어있는 경우
        if (nowQ.empty()) {
            nowLoc ^=1;
            nowTime += t;
            continue;
        }

        if (nowQ.front().r > nowTime) {
            if (otherQ.empty()) {
                nowTime = nowQ.front().r;
                continue;
            }

            if (nowQ.front().r > otherQ.front().r) {
                nowTime = max(nowTime, otherQ.front().r)+t;
                nowLoc ^= 1;
            }
            else {
                nowTime = nowQ.front().r;
            }
            continue;
        }

        else {
            int nowWeight = 0;
            while (!nowQ.empty() && nowWeight < m && nowQ.front().r <= nowTime)
            {
                startTime[nowQ.front().idx] = min(nowTime, startTime[nowQ.front().idx]);
                endTime[nowQ.front().idx] = max(endTime[nowQ.front().idx], nowTime + t);

                int leftWeight = max(0, m - nowWeight);
                if (nowQ.front().m <= max(0, leftWeight) ) {
                    nowWeight += nowQ.front().m;
                    nowQ.pop();
                }
                else {
                    nowWeight += leftWeight;
                    nowQ.front().m -= leftWeight;
                    break;
                }
            }
            nowLoc ^= 1;
            nowTime += t;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << startTime[i] <<' ' <<endTime[i] << '\n';
    }
    return 0;
}