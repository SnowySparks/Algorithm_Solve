#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct comp1 {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1]>b[1];
    }
 };

 struct comp2 {
    bool operator()(vector<int> a, vector<int> b) {
        return a[0]==b[0] ? a[1]>b[1] : a[0]>b[0];
    }
 };


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int> , vector<vector<int>> , comp1> standby;
    priority_queue<vector<int> , vector<vector<int>> , comp2> data;
    int start=0, end=-1; //시간
    for (auto e : jobs) {
        data.push(e);
    }
    while (!data.empty()) {
        if (standby.empty() && end < data.top()[0]) {
            start=data.top()[0];
            end=start+data.top()[1];

            answer+=(end - data.top()[0]);
            data.pop();
        }
        else {
            while ((!data.empty()) && (data.top()[0]<=end)) {
                standby.push(data.top());
                data.pop();
            }
            start=end;
            end=start + standby.top()[1];
            answer+=(end - standby.top()[0]);

            standby.pop();
        }
    }
    while (!standby.empty()) {
        start=end;
        end=start + standby.top()[1];
        answer+=(end - standby.top()[0]);
        standby.pop();
    }
    return answer/jobs.size();
}